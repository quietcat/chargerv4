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
#include "buffer.h"

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
                    P("Sim error\r\n");
                    break;
                case 't':
                    cstate = ST_TOO_HOT;
                    BULK_OFF;
                    P("Sim temp\r\n");
                    break;
                case 'f':
                    cstate = ST_FULL;
                    BULK_OFF;
                    P("Sim full\r\n");
                    break;
                case 'i':
                    cstate = ST_IDLE;
                    BULK_OFF;
                    P("Sim idle\r\n");
                    break;
                case 'b':
                    BULK_CTL = ~BULK_CTL;
                    if (BULK_CTL) {
                        P("Sim bulk on\r\n");
                    } else {
                        P("Sim bulk off\r\n");
                    }
                    break;
                case 'a':
                    print_data2();
                    P("\r\n");
                    break;
                case 'm':
                    if (cstate == ST_MANUAL) {
                        P("Manual off\r\n");
                        cstate = ST_IDLE;
                    } else if (cstate == ST_IDLE) {
                        P("Manual on\r\n");
                        cstate = ST_MANUAL;
                    } else {
                        P("Go idle first\r\n");
                    }
                    break;
                default:
                    P(ch_buf);
                    break;
                }
            } else {
                P("\r\n");
            }
            break;
    }
}
