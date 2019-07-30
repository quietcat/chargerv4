/*
 * reporting.c
 *
 *  Created on: Jul 28, 2019
 *      Author: denis
 */


#include "msg_codes.h"
#include "oversampling.h"
#include "uart.h"
#include "reporting.h"

void reporting_service(char msg) {
    switch(msg) {
    case MSG_INIT: {
    	uart_send_str("VREF: ");
        uart_send_str(fptoa(VREF,3));
        uart_send_str("V\r\n");
    	break;
    }
    case MSG_5SECOND: {
        uint16_t vfix = ufixmult(VREF, oversampled_voltage >> (INT_BITS));
        uart_send_str("B+: ");
        uart_send_str(fptoa(vfix,3));
        uart_send_str("V\r\n");
        break;
    }
    }
}
