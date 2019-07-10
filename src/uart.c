/*
 * uart.c
 *
 *  Created on: Feb 21, 2015
 *      Author: denis
 */

#include <SI_C8051F850_Register_Enums.h>
#include "queue.h"
#include "uart.h"

volatile char * tx_data = "";
volatile bit tx_busy = 0;

char * SEG_IDATA uart_tx_queue[UART_TX_QUEUE_SIZE];
char             uart_tx_queue_head = 0;
volatile char    uart_tx_queue_tail = 0;
volatile bit     uart_tx_queue_full = 0;

#define TX_QUEUE_EMPTY (uart_tx_queue_head == uart_tx_queue_tail && !uart_tx_queue_full)



INTERRUPT_USING (UART0_ISR, UART0_IRQn, 1)
{
    if (SCON0_TI) {
        char tx_char;
        // find next character to send
        // first, if we are on a zero character and there are more strings in the queue,
        // find next non-empty string
        while ( *tx_data == 0 && !TX_QUEUE_EMPTY ) {
            if ( ++uart_tx_queue_tail == UART_TX_QUEUE_SIZE ) uart_tx_queue_tail = 0;
            tx_data = uart_tx_queue[uart_tx_queue_tail];
            uart_tx_queue_full = 0;
        }

        tx_char = *tx_data;

        if ( !TX_QUEUE_EMPTY && tx_char != 0 ) {
            tx_busy = 1;
            SBUF0 = tx_char;
            tx_data++; // pointer arithmetic
        }
        else {
            tx_data = "";
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


void uart_send_str(char * s) {
    if ( uart_tx_queue_full ) return;
    {
        char new_head = uart_tx_queue_head + 1;
        if ( new_head == UART_TX_QUEUE_SIZE ) {
            new_head = 0;
        }
        if ( new_head == uart_tx_queue_tail ) {
            uart_tx_queue_full = 1;
            uart_tx_queue[uart_tx_queue_head] = "ERROR: TX queue overrun, message(s) lost\r\n";
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
