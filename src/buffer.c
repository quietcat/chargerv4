/*
 * buffer.c
 *
 *  Created on: Aug 2, 2019
 *      Author: denispetrov
 */

#include "buffer.h"

uint8_t SEG_IDATA buffer[BUFFER_SIZE];
uint8_t buffer_head = 0;
uint8_t buffer_tail = 0;
uint8_t buffer_end = BUFFER_SIZE;
bool buffer_full = 0;
uint8_t buffer_ready_head = 0;
bool buffer_ready_full = 0; // when ready_head == tail, indicates whether ready portion of buffer is zero-length or full buffer
uint8_t pointer_tail = 0;

void * allocate_buffer(uint8_t size) {
    uint8_t buffer_at = buffer_head;
    if (buffer_tail == buffer_head) { // empty buffer, restart from top of buffer
        buffer_tail = 0;
        buffer_head = 0;
        buffer_ready_head = 0;
        buffer_end = BUFFER_SIZE;
    }
    if (buffer_head < buffer_tail) {
        if (buffer_head + size > buffer_tail)
            return NULL;
        buffer_head += size;
    } else {
        if (buffer_head + size > BUFFER_SIZE) {
            if (size > buffer_tail)
                return NULL;
            buffer_end = buffer_head;
            if (buffer_tail == buffer_end) { // edge case starting with an empty buffer
                buffer_tail = 0;
                buffer_end = BUFFER_SIZE;
            }
            buffer_head = size;
            buffer_at = 0;
        } else {
            buffer_end = BUFFER_SIZE;
            buffer_head += size;
            if (buffer_head + size == BUFFER_SIZE) {
                buffer_end = BUFFER_SIZE;
                buffer_head = 0;
            }
        }
    }
    if (buffer_head == buffer_tail)
        buffer_full = 1;
    return &buffer[buffer_at];
}

char * allocate_pointer(char * buf) {
    char ** ptr_alloc = allocate_buffer(sizeof(buf));
    if (ptr_alloc == NULL) return NULL;
    *ptr_alloc = buf;
    return ptr_alloc;
}

void allocate_ready() {
    buffer_ready_head = buffer_head;
    buffer_ready_full = buffer_full;
    uart_notify();
}

char get_next_byte() {
    if (buffer_tail != buffer_ready_head || buffer_ready_full) {
        uint8_t next_char = buffer[buffer_tail];
        if (next_char == SI_GPTR_MTYPE_DATA || next_char == SI_GPTR_MTYPE_XDATA || next_char == SI_GPTR_MTYPE_PDATA || next_char == SI_GPTR_MTYPE_CODE ) {
            char * ptr_read = (SI_GENERIC_PTR*) &buffer[buffer_tail];
            next_char = ptr_read[pointer_tail];
            pointer_tail += 1;
            if (ptr_read[pointer_tail] == 0) {
                pointer_tail = 0;
                buffer_tail += sizeof(SI_GENERIC_PTR);
                if (buffer_tail == buffer_end) {
                    buffer_tail = 0;
                    buffer_end = BUFFER_SIZE;
                }
            }
        } else {
            buffer_tail += 1;
            if (buffer_tail == buffer_end) {
                buffer_tail = 0;
                buffer_end = BUFFER_SIZE;
            }
        }
        buffer_full = false;
        buffer_ready_full = false;
        return next_char;
    }
    return 0;
}

