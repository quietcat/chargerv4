/*
 * uart.h
 *
 *  Created on: Feb 21, 2015
 *      Author: denis
 */

#ifndef UART_H_
#define UART_H_

extern void uart_send_str(char * s);

// how many strings can be buffered up for sending
#define UART_TX_QUEUE_SIZE 16

#endif /* UART_H_ */
