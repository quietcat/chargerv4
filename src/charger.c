/*
 * charger.c
 *
 *  Created on: Feb 23, 2015
 *      Author: denis
 */

#include <SI_C8051F850_Register_Enums.h>                  // SFR declarations
#include "clock.h"
#include "queue.h"
#include "oversampling.h"
#include "adc.h"
#include "convert.h"
#include "uart.h"
#include "charger.h"
#include "cal.h"

#define STR_1(s) #s
#define STR(s) STR_1(s)

unsigned char idle_voltage = 0;
unsigned char trickle_diff = 255;
#define NEG_ACTIVE_VOLTAGE  5
#define COOL_DOWN_MINUTES   10

char cstate = ST_STARTUP;
unsigned int max_voltage = 0;
unsigned int max_voltage_995 = 0; // voltage at 99.5% of max_voltage
unsigned char max_temp = 0;
unsigned char charging_minutes;
unsigned char minutes_at_max_voltage = 0;
unsigned char volt_deglitch_counter = 0;
#define VOLT_DEGLITCH_COUNTER_MAX 100

#ifdef TEMP_SENSOR_5K
unsigned char temp_deglitch_counter = 0;
#define TEMP_DEGLITCH_COUNTER_MAX 100
#define TEMP_SENSOR_OK 250
#endif

//bit temp_sensor_present;
//bit temp_sensor_5k;

void print_data(void) {
#if defined(TEMP_SENSOR_5K)
    uart_send_str("T: ");
    uart_send_str(uitoa(temp_value));
    uart_send_str(" Tmax: ");
    uart_send_str(uitoa(max_temp));
#endif
    uart_send_str(" V: ");
    uart_send_str(uitoa(oversampled_voltage));
    uart_send_str(" V*99.5%: ");
    uart_send_str(uitoa(max_voltage_995));
    uart_send_str(" Vmax: ");
    uart_send_str(uitoa(max_voltage));
}

void print_data2(void) {
    uart_send_str("B+: ");
    uart_send_str(uitoa(volt_value));
    uart_send_str(" B-: ");
    uart_send_str(uitoa(batn_value));
}

void print_cal(void) {
    uart_send_str(    "Delta T         : ");
    uart_send_str(uitoa(cal->deltaT));
    uart_send_str("\r\nMax bulk min    : ");
    uart_send_str(uitoa(cal->maxTimeBulk));
    uart_send_str("\r\nMax trickle min : ");
    uart_send_str(uitoa(cal->maxTimeTrickle));
    uart_send_str("\r\nMax min @ max V : ");
    uart_send_str(uitoa(cal->maxTimeAtMaxV));
    uart_send_str("\r\nTemp hot thr    : ");
    uart_send_str(uitoa(cal->tempHotThr));
    uart_send_str("\r\n");
}

void charger_go_idle(void) {
    print_data();
    uart_send_str("   Go idle\r\n");
    cstate = ST_IDLE;
    BULK_OFF;
}

void charger_service(char msg) {
    switch (msg) {
        case MSG_SECOND:
            switch (cstate) {
                case ST_STARTUP:
                    uart_send_str("   Calibration\r\n");
                    cstate = ST_CAL;
                    break;
                case ST_CAL:
                    idle_voltage = volt_value - volt_value / 8;
                    trickle_diff = volt_value / 4;
                    print_cal();
                    uart_send_str("   Idle\r\n");
                    cstate = ST_IDLE;
                    break;
                case ST_IDLE:
                    if ( batn_value > NEG_ACTIVE_VOLTAGE ) {
                        print_data();
                        uart_send_str("   Start trickle\r\n");
                        cstate = ST_TRICKLE;
                        charging_minutes = 0;
                        QUEUE_PUT(MSG_CLK_RST);
                    }
                    break;
                case ST_TRICKLE:
                    if ( batn_value <= NEG_ACTIVE_VOLTAGE ) {
                        charger_go_idle();
                        break;
                    }
                    if ( volt_value-batn_value >= trickle_diff ) {
                        print_data();
                        uart_send_str("   Initial bulk charge\r\n");
                        cstate = ST_BULK_1;
                        charging_minutes = 0;
                        set_timer(MSG_TIMER_0,5); // at least 5 seconds of bulk charging
                        BULK_ON;
                    }
                    break;
                case ST_TOO_HOT:
                case ST_FULL:
                case ST_ERROR:
                    if ( batn_value <= NEG_ACTIVE_VOLTAGE ) {
                        charger_go_idle();
                    }
                    break;
                case ST_BULK_1:
                    if ( volt_value >= idle_voltage ) {
                        charger_go_idle();
                    }
                    break;
                case ST_BULK_2:
                    if ( volt_value >= idle_voltage ) {
                        charger_go_idle();
                    }
                    break;
                default:
                    BULK_OFF;
                    cstate = ST_IDLE;
                    break;
            }
            break;
        case MSG_OVSVOLT:
            switch (cstate) {
            case ST_BULK_2:
                if ( volt_value >= idle_voltage ) {
                    charger_go_idle();
                    break;
                }
                if (volt_deglitch_counter > 0) {
                    volt_deglitch_counter--;
                }
#if defined(TEMP_SENSOR_5K)
                if (temp_value <= cal->tempHotThr) {
                    uart_send_str("    Battery too hot, stopping charge\r\n");
                    cstate = ST_TOO_HOT;
                    charging_minutes = 0;
                    break;
                }
                if (temp_deglitch_counter > 0) {
                    temp_deglitch_counter--;
                }
                if (max_temp < temp_value) {
                    max_temp = temp_value;
                } else if (temp_value < max_temp - cal->deltaT) {
                    temp_deglitch_counter += 10;
                    uart_send_str("   Temp neg delta trip\r\n");
                }
                if (temp_deglitch_counter > TEMP_DEGLITCH_COUNTER_MAX) {
                    uart_send_str("   Full - temp sensor\r\n");
                    cstate = ST_FULL;
                    BULK_OFF;
                    break;
                }
#endif
                if (volt_deglitch_counter > VOLT_DEGLITCH_COUNTER_MAX) {
                    uart_send_str("   Full - negative delta V\r\n");
                    cstate = ST_FULL;
                    BULK_OFF;
                    break;
                }
                if (max_voltage < oversampled_voltage) {
                    max_voltage = oversampled_voltage;
                    minutes_at_max_voltage = 0;
                    max_voltage_995 = max_voltage - max_voltage / 200; // 99.5%
                } else if (oversampled_voltage < max_voltage_995) {
                    volt_deglitch_counter += 10;
                    uart_send_str("   Volt neg delta trip\r\n");
                }
                break;
            }
            break;
        case MSG_MINUTE:
            switch (cstate) {
                case ST_TRICKLE:
                    print_data();
                    if ( ++charging_minutes == cal->maxTimeTrickle ) {
                        uart_send_str("   Error: trickle charge time exceeded, battery may be faulty\r\n");
                        cstate = ST_ERROR;
                    } else {
                        uart_send_str("   ");
                        uart_send_str(uitoa(charging_minutes));
                        uart_send_str(" min trickle\r\n");
                    }
                    break;
                case ST_BULK_2:
                    print_data();
                    if ( ++charging_minutes == cal->maxTimeBulk ) {
                        uart_send_str("   Maximum bulk charge time reached\r\n");
                        cstate = ST_FULL;
                        BULK_OFF;
                    } else {
                        uart_send_str("   ");
                        uart_send_str(uitoa(charging_minutes));
                        uart_send_str(" min bulk\r\n");
                    }
                    if ( ++minutes_at_max_voltage == cal->maxTimeAtMaxV) {
                        uart_send_str("   Full after max minutes at max voltage\r\n");
                        cstate = ST_FULL;
                        BULK_OFF;
                    }
                    break;
                case ST_TOO_HOT:
                    print_data();
                    if ( ++charging_minutes == COOL_DOWN_MINUTES) {
                        uart_send_str("    Cool down period ended\r\n");
                        charger_go_idle();
                    } else {
                        uart_send_str("    Cooling down\r\n");
                    }
                    break;
                case ST_IDLE:
                    print_data();
                    uart_send_str("   Idle, waiting\r\n");
                    break;
            }
            break;
        case MSG_TIMER_0:
            switch (cstate) {
                case ST_BULK_1:
                    volt_deglitch_counter = 0;
                    max_temp = 0;
                    max_voltage = 0;
                    charging_minutes = 0;
                    minutes_at_max_voltage = 0;
#if defined(TEMP_SENSOR_5K)
                    temp_deglitch_counter = 0;
                    if (temp_value >= TEMP_SENSOR_OK) {
                        uart_send_str("   Temp sensor fault\r\n");
                    }
#endif
                    print_data();
                    uart_send_str("   Begin bulk charge\r\n");
                    cstate = ST_BULK_2;
                    break;
            }
            break;
        case MSG_INIT:
            uart_send_str("\r# NiCd/NiMH Charger v4.0.0 #\r\n");
            cstate = ST_STARTUP;
            break;
    }
}
