
// Program Size: data=187.5 xdata=0 const=0 code=5238

#include <SI_C8051F850_Register_Enums.h>                  // SFR declarations
#include "buffer.h"
#include "convert.h"

/*
 * LX51 will give "L30: memory space overlap" warning, which should be ignored
 */
uint8_t data R5 _at_ 0x5;
uint8_t remainder;

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
            /*
             * See explanation in fptoa() below how this works
             */
            v /= 10;
            remainder = R5;
            buf[i] = remainder + '0';
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
    uint16_t frac_part;
    int8_t d;
    if (buf == NULL) return NULL;
    accum = (v & FRAC_MASK);
    accum *= 10000;
    rounding = (accum & FRAC_MSB);
    accum /= FRAC_BASE;
    /*
     * 16 most significant bits are 0, so we don't need to waste time performing
     * 32-bit division when converting to decimal string
     *
     * This reduces computation time from 254uS to 52 uS
     */
    frac_part = accum;
    if (rounding) frac_part ++;
    P2_B0 = 0;
    for (d = 5; d > 1; d--) {
        /*
         * This is the usual way of converting binary to decimal text, using two
         * divisions:
         *
         * buf[d] = (frac_part % 10) + '0';
         * frac_part /= 10;
         *
         * Optimizing one division away
         * making use of the fact that both quotient and remainder are calculated
         * by the same library function, ?C?UIDIV, which returns quotient in R6-R7,
         * and remainder in R4-R5. Because the divisor is less than 256, remainder
         * will always fit in one byte.
         *
         * This further reduces computation time from 52uS to 27uS.
         *
         */
        frac_part /= 10;
        remainder = R5;
        buf[d] = remainder + '0';
    }
    P2_B0 = 1;
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
