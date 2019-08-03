
// Program Size: data=187.5 xdata=0 const=0 code=5238

#include <compiler_defs.h>
#include "buffer.h"
#include "convert.h"

char * uitoa(unsigned int v) {
    unsigned char sz = 5;
    if (v < 10) {
        sz = 1;
    } else if (v < 100) {
        sz = 2;
    } else if (v < 1000) {
        sz = 3;
    } else if (v < 10000) {
        sz = 4;
    }
    {
        char * buf = allocate_buffer(sz);
        char i;
        if (buf == NULL) return NULL;
        for (i = sz-1; i >= 0; i--) {
            buf[i] = (v % 10) + '0';
            v /= 10;
        }
        return buf;
    }
}

char * uitoh(unsigned int v) {
    char * buf = allocate_buffer(4);
    char d;
    if (buf == NULL) return NULL;
    for (d = 3; d >= 0; d--) {
        uint8_t digit = v % 16;
        if (digit < 10) {
            buf[d] = digit + '0';
        } else {
            buf[d] = digit-10 + 'A';
        }
        v /= 16;
    };
    return buf;
}

uint32_t accum;
bit rounding;

char * fptoa(unsigned int v) {
    char * buf = allocate_buffer(6); // #.####
    uint16_t int_part = (v >> FRAC_BITS);
    int8_t d;
    if (buf == NULL) return NULL;
    accum = (v & FRAC_MASK);
    accum *= 10000;
    rounding = (accum & FRAC_MSB);
    accum /= FRAC_BASE;
    if (rounding) accum ++;
    for (d = 5; d > 1; d--) {
        buf[d] = (accum % 10) + '0';
        accum /= 10;
    }
    buf[1] = '.';
    buf[0] = int_part + '0';
    return buf;
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
