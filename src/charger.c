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
#include "buffer.h"
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
    P("T: ");Pi(temp_value);
    P(" Tmax: ");Pi(max_temp);
#endif
    P(" V: ");
    Pi(oversampled_voltage);
    P(" V*99.5%: ");
    Pi(max_voltage_995);
    P(" Vmax: ");
    Pi(max_voltage);
}

void print_data2(void) {
    P("B+: ");
    Pi(volt_value);
    P(" B-: ");
    Pi(batn_value);
}

void print_cal(void) {
    P(    "Delta T         : ");
    Pi(cal->deltaT);
    P("\r\nMax bulk min    : ");
    Pi(cal->maxTimeBulk);
    P("\r\nMax trickle min : ");
    Pi(cal->maxTimeTrickle);
    P("\r\nMax min @ max V : ");
    Pi(cal->maxTimeAtMaxV);
    P("\r\nTemp hot thr    : ");
    Pi(cal->tempHotThr);
    P("\r\n");
}

void charger_go_idle(void) {
    print_data();
    P("   Go idle\r\n");
    cstate = ST_IDLE;
    BULK_OFF;
}

void charger_service(char msg) {
    switch (msg) {
        case MSG_SECOND:
            switch (cstate) {
                case ST_STARTUP:
                    P("   Calibration\r\n");
                    cstate = ST_CAL;
                    break;
                case ST_CAL:
                    idle_voltage = volt_value - volt_value / 8;
                    trickle_diff = volt_value / 4;
                    print_cal();
                    P("   Idle\r\n");
                    cstate = ST_IDLE;
                    BULK_OFF;
                    break;
                case ST_IDLE:
                    if ( batn_value > NEG_ACTIVE_VOLTAGE ) {
                        print_data();
                        P("   Start trickle\r\n");
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
                        P("   Initial bulk charge\r\n");
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
                        print_data2();
                        charger_go_idle();
                    }
                    break;
                case ST_BULK_2:
                    if ( volt_value >= idle_voltage ) {
                        charger_go_idle();
                    }
                    break;
                case ST_MANUAL:
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
                    P("    Battery too hot, stopping charge\r\n");
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
                    P("   Temp neg delta trip\r\n");
                }
                if (temp_deglitch_counter > TEMP_DEGLITCH_COUNTER_MAX) {
                    P("   Full - temp sensor\r\n");
                    cstate = ST_FULL;
                    BULK_OFF;
                    break;
                }
#endif
                if (volt_deglitch_counter > VOLT_DEGLITCH_COUNTER_MAX) {
                    P("   Full - negative delta V\r\n");
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
                    P("   Volt neg delta trip\r\n");
                }
                break;
            }
            break;
        case MSG_MINUTE:
            switch (cstate) {
                case ST_TRICKLE:
                    print_data();
                    if ( ++charging_minutes == cal->maxTimeTrickle ) {
                        P("   Error: trickle charge time exceeded, battery may be faulty\r\n");
                        cstate = ST_ERROR;
                    } else {
                        P("   ");
                        Pi(charging_minutes);
                        P(" min trickle\r\n");
                    }
                    break;
                case ST_BULK_2:
                    print_data();
                    if ( ++charging_minutes == cal->maxTimeBulk ) {
                        P("   Maximum bulk charge time reached\r\n");
                        cstate = ST_FULL;
                        BULK_OFF;
                    } else {
                        P("   ");
                        Pi(charging_minutes);
                        P(" min bulk\r\n");
                    }
                    if ( ++minutes_at_max_voltage == cal->maxTimeAtMaxV) {
                        P("   Full after max minutes at max voltage\r\n");
                        cstate = ST_FULL;
                        BULK_OFF;
                    }
                    break;
                case ST_TOO_HOT:
                    print_data();
                    if ( ++charging_minutes == COOL_DOWN_MINUTES) {
                        P("    Cool down period ended\r\n");
                        charger_go_idle();
                    } else {
                        P("    Cooling down\r\n");
                    }
                    break;
                case ST_IDLE:
                    print_data();
                    P("   Idle, waiting\r\n");
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
                        P("   Temp sensor fault\r\n");
                    }
#endif
                    print_data();
                    P("   Begin bulk charge\r\n");
                    cstate = ST_BULK_2;
                    break;
            }
            break;
        case MSG_INIT:
            BULK_OFF;
            P("\r# NiCd/NiMH Charger v4.0.0 #\r\n");
            cstate = ST_STARTUP;
            break;
    }
}
