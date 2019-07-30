
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

char * uitoh(unsigned int v) {
    unsigned char pos = ring_buffer_pos;
    unsigned char sz = 5;
    ring_buffer_pos += sz;
    if (ring_buffer_pos >= RING_BUFFER_SIZE) {
        pos = 0;
        ring_buffer_pos = sz;
    }
    {
        unsigned char i = pos+sz-1;
        ring_buffer[i] = 0;
        do {
            unsigned char digit = v % 16;
            if (digit < 10) {
                ring_buffer[--i] = digit + '0';
            } else {
                ring_buffer[--i] = digit-10 + 'A';
            }
            v /= 16;
        } while (v);
    }
    return &ring_buffer[pos];
}

#define PRECISION_DIGITS 4
#define FRAC_BASE 10000

uint16_t muldiv(uint16_t o1, uint16_t multiplier, uint16_t divisor) {
    return ((uint32_t)o1 * (uint32_t)multiplier)/((uint32_t)divisor);
}

char * fptoa(uint16_t v) {
    unsigned char pos = ring_buffer_pos;
    unsigned char sz = 7;
    ring_buffer_pos += sz;
    if (ring_buffer_pos >= RING_BUFFER_SIZE) {
        pos = 0;
        ring_buffer_pos = sz;
    }
    {
        unsigned char i = pos+sz-1;
        uint16_t frac = (uint32_t)(v & FRAC_MASK) * (uint32_t)FRAC_BASE / (uint32_t)BASE;
        ring_buffer[i] = 0;
        do {
            ring_buffer[--i] = (frac % 10) + '0';
            frac /= 10;
        } while (frac);
        ring_buffer[--i] = '.';
        ring_buffer[--i] = (v >> FRACTION_BITS) + '0';
    }
    return &ring_buffer[pos];
}

unsigned short ufixmult(uint16_t o1, uint16_t o2) {
  two_shorts truncater;

  truncater.integer_part = ((uint32_t)o1 * (uint32_t)o2);
  // if fractional part >= 0.5, need to round up
  if (truncater.integer_part & FRAC_MSB) {
      truncater.integer_part >>= FRACTION_BITS; // divide by BASE
      truncater.integer_part += 1; // rounding bit
  } else {
      truncater.integer_part >>= FRACTION_BITS; // divide by BASE
  }
  return truncater.short_part[1]; // assume little-endian
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

