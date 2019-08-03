/*
 * buffer.h
 *
 *  Created on: Aug 2, 2019
 *      Author: denispetrov
 */

#ifndef BUFFER_H_
#define BUFFER_H_

#include <compiler_defs.h>
#include <uart.h>

#define BUFFER_SIZE 80
extern SEG_IDATA uint8_t buffer[BUFFER_SIZE];
extern uint8_t buffer_head;
extern uint8_t buffer_tail;
extern uint8_t buffer_end;
extern bool buffer_full;
extern uint8_t pointer_tail;

void * allocate_buffer(uint8_t size);
char * allocate_pointer(char * buf);
char get_next_byte();
void allocate_ready();
//uint8_t * insert_bytes(char * bytes);
//void get_bytes(uint8_t * buffer, uint8_t n);

#define P(str) allocate_pointer(str);allocate_ready();
#define Pi(num) uitoa(num);allocate_ready();
#define Ph(num) uitoh(num);allocate_ready();
#define Pf(num) fptoa(num);allocate_ready();

#endif /* BUFFER_H_ */
