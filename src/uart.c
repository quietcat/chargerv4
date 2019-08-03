/*
 * uart.c
 *
 *  Created on: Feb 21, 2015
 *      Author: denis
 */

#include <SI_C8051F850_Register_Enums.h>
#include "queue.h"
#include "uart.h"
#include "buffer.h"

volatile bit tx_busy = 0;

void uart_notify() {
    bit IE_EA_save = IE_EA;
    IE_EA=0;
    if ( ! tx_busy ) {
        tx_busy = 1;
        SCON0_TI = 1;
    }
    IE_EA=IE_EA_save;
}

INTERRUPT_USING (UART0_ISR, UART0_IRQn, 1)
{
    if (SCON0_TI) {
        char tx_char = get_next_byte();

        if ( tx_char != 0 ) {
            tx_busy = 1;
            SBUF0 = tx_char;
        }
        else {
            tx_busy = 0;
        }
        SCON0_TI = 0;
    }
    if (SCON0_RI) {
        char rx_char = SBUF0;
        QUEUE_PUT_PARAM(MSG_UART_RX,rx_char);
        SCON0_RI = 0;
    }
}

#if 0
void uart_send_str(char * s) {
    if ( uart_tx_queue_full ) return;
    {
        char new_head = uart_tx_queue_head + 1;
        if ( new_head == UART_TX_QUEUE_SIZE ) {
            new_head = 0;
        }
        if ( new_head == uart_tx_queue_tail ) {
            uart_tx_queue_full = 1;
//            uart_tx_queue[uart_tx_queue_head] = "ERROR: TX queue overrun, message(s) lost\r\n";
        } else {
            uart_tx_queue[uart_tx_queue_head] = s;
        }
        uart_tx_queue_head = new_head;
        if ( ! tx_busy ) {
            tx_busy = 1;
            tx_data = s;
            SCON0_TI = 1;
        }
    }
}
#endif
