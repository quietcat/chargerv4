/*
 * uart_service.c
 *
 *  Created on: Feb 21, 2015
 *      Author: denis
 */

#include <SI_C8051F850_Register_Enums.h>
#include "queue.h"
#include "uart.h"
//#include "convert.h"
#include "clock.h"
//#include "adc.h"
#include "charger.h"

char SEG_IDATA ch_buf[2];

extern void uart_service(char msg, char param) {
    switch(msg) {
        case MSG_UART_RX:
            if ( param != '\n' && param != '\r' ) {
                ch_buf[0] = param;
                ch_buf[1] = 0;
                switch (param) {
                case 'w':
                    reset_watchdog = 0;
                    break;
                case 'e':
                    cstate = ST_ERROR;
                    BULK_OFF;
                    uart_send_str("Sim error\r\n");
                    break;
                case 't':
                    cstate = ST_TOO_HOT;
                    BULK_OFF;
                    uart_send_str("Sim temp\r\n");
                    break;
                case 'f':
                    cstate = ST_FULL;
                    BULK_OFF;
                    uart_send_str("Sim full\r\n");
                    break;
                case 'i':
                    cstate = ST_IDLE;
                    BULK_OFF;
                    uart_send_str("Sim idle\r\n");
                    break;
                case 'b':
                    BULK_CTL = ~BULK_CTL;
                    if (BULK_CTL) {
                        uart_send_str("Sim bulk on\r\n");
                    } else {
                        uart_send_str("Sim bulk off\r\n");
                    }
                    break;
                case 'a':
                    print_data2();
                    uart_send_str("\r\n");
                    break;
                case 'm':
                    if (cstate == ST_MANUAL) {
                        uart_send_str("Manual off\r\n");
                        cstate = ST_IDLE;
                    } else if (cstate == ST_IDLE) {
                        uart_send_str("Manual on\r\n");
                        cstate = ST_MANUAL;
                    } else {
                        uart_send_str("Go idle first\r\n");
                    }
                    break;
                default:
                    uart_send_str(ch_buf);
                    break;
                }
            } else {
                uart_send_str("\r\n");
            }
            break;
    }
}
