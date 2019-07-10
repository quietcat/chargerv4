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
