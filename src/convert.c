
// Program Size: data=187.5 xdata=0 const=0 code=5238

#include <compiler_defs.h>
#include "convert.h"

#define RING_BUFFER_SIZE 32
uint8_t SEG_IDATA ring_buffer[RING_BUFFER_SIZE];
uint8_t ring_buffer_pos = 0;

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
    if (ring_buffer_pos >= RING_BUFFER_SIZE) {
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

uint8_t * uitoh(uint16_t v) {
    unsigned char pos = ring_buffer_pos;
    unsigned char sz = 5;
    ring_buffer_pos += sz;
    if (ring_buffer_pos >= RING_BUFFER_SIZE) {
        pos = 0;
        ring_buffer_pos = sz;
    }
    {
        uint8_t i = pos+sz-1;
        uint8_t d;
        ring_buffer[i--] = 0;
        for (d = 4; d > 0; i--, d--) {
            uint8_t digit = v % 16;
            if (digit < 10) {
                ring_buffer[i] = digit + '0';
            } else {
                ring_buffer[i] = digit-10 + 'A';
            }
            v /= 16;
        };
    }
    return &ring_buffer[pos];
}

uint32_t accum;
bit rounding;

uint8_t * fptoa(uint16_t v) {
    uint8_t pos = ring_buffer_pos;
    uint16_t int_part = (v >> FRAC_BITS);
    uint8_t sz = 7; // #.####
    accum = (v & FRAC_MASK);
    accum *= 10000;
    rounding = (accum & FRAC_MSB);
    accum /= FRAC_BASE;
    if (rounding) accum ++;
    ring_buffer_pos += sz;
    if (ring_buffer_pos >= RING_BUFFER_SIZE) {
        pos = 0;
        ring_buffer_pos = sz;
    }
    {
        uint8_t i = pos+sz-1;
        uint8_t d;
        ring_buffer[i--] = 0;
        for (d = 4; d > 0; d--, i--) {
            ring_buffer[i] = (accum % 10) + '0';
            accum /= 10;
        }
        ring_buffer[i--] = '.';
        ring_buffer[i] = int_part + '0';
    }
    return &ring_buffer[pos];
}

uint16_t ufixmult(uint16_t o1, uint16_t o2) {
    accum = o1;
    accum *= o2;
    rounding = (accum & FRAC_MSB);
    accum >>= FRAC_BITS;
    if (rounding) accum ++;
    return accum;
}

#if 0
short fixmult(short o1, short o2) {
  unsigned short o1pos = o1;
  unsigned short o2pos = o2;
  bit sign1 = ((o1 & SIGN_BIT) != 0);
  bit sign2 = ((o2 & SIGN_BIT) != 0);
  bit sign = sign1 ^ sign2;
  if (sign1) {
    o1pos = (~o1) + 1;
  }
  if (sign2) {
    o2pos = (~o2) + 1;
  }
  unsigned short result = ufixmult(o1pos, o2pos);
  if (sign) {
    result = (~result)+1;
  }
  return result; // assume little-endian
}

#endif
