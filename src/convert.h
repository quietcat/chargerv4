#ifndef CONVERT_H_
#define CONVERT_H_

#include <stdint.h>

#define SIGN_BIT 0x8000
#define FRACTION_BITS 14
#define BASE (1 << FRACTION_BITS)
#define FRAC_MSB (1 << (FRACTION_BITS-1))
#define FRAC_MASK (BASE-1)
#define INT_MASK (~FRAC_MASK)

typedef union {
   uint32_t integer_part;
   uint16_t short_part[2];
} two_shorts;

unsigned short ufixmult(uint16_t o1, uint16_t o2);
uint16_t muldiv(uint16_t o1, uint16_t multiplier, uint16_t divisor);

char * uctoa(unsigned char c);
char * uitoa(unsigned int v);
char * uitoh(unsigned int v);
char * fptoa(uint16_t v);
extern unsigned char ring_buffer_pos;

#endif
