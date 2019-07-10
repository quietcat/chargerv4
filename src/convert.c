
// Program Size: data=187.5 xdata=0 const=0 code=5238

#include <compiler_defs.h>
#include "convert.h"

#define RING_BUFFER_SIZE 32
unsigned char SEG_IDATA ring_buffer[RING_BUFFER_SIZE];
unsigned char ring_buffer_pos = 0;

char * uitoa(unsigned int v) {
    unsigned char pos = ring_buffer_pos;
    unsigned char sz = 6;
    if (v < 10) {
        sz = 2;
    } else if (v < 100) {
        sz = 3;
    } else if (v < 1000) {
        sz = 4;
    } else if (v < 10000) {
        sz = 5;
    }
    ring_buffer_pos += sz;
    if (ring_buffer_pos > RING_BUFFER_SIZE) {
        pos = 0;
        ring_buffer_pos = sz;
    }
    {
        unsigned char i = pos+sz-1;
        ring_buffer[i] = 0;
        do {
            ring_buffer[--i] = (v % 10) + '0';
            v /= 10;
        } while (v);
    }
    return &ring_buffer[pos];
}
