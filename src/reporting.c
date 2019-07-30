/*
 * reporting.c
 *
 *  Created on: Jul 28, 2019
 *      Author: denis
 */


#include "msg_codes.h"
#include "oversampling.h"
#include "convert.h"
#include "uart.h"
#include "reporting.h"

#define VMAX_3V3 (BASE*3 + BASE*3/10)

void reporting_service(char msg) {
    switch(msg) {
    case MSG_5SECOND: {
        uint16_t vfix = ufixmult(VMAX_3V3, oversampled_voltage >> (sizeof(short)*8-FRACTION_BITS));
        uart_send_str(fptoa(vfix));
        uart_send_str("\r\n");
        break;
    }
    }
}
