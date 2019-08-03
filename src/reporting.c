/*
 * reporting.c
 *
 *  Created on: Jul 28, 2019
 *      Author: denis
 */

#include <compiler_defs.h>
#include "msg_codes.h"
#include "oversampling.h"
#include "uart.h"
#include "reporting.h"
#include "buffer.h"

void reporting_service(char msg) {
    switch(msg) {
    case MSG_INIT: {
    	P("VREF: ");
        Ph(VREF);
        P(" ");
        Pf(VREF);
        P("V\r\n");
    	break;
    }
    case MSG_5SECOND: {
        uint16_t vfix = ufixmult(VREF, oversampled_voltage >> (INT_BITS));
        P("B+: ");
        Pi(oversampled_voltage);
        P(" ");
        Pf(vfix);
        P("V\r\n");
        NOP();
        break;
    }
    }
}
