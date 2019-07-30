#ifndef CONVERT_H_
#define CONVERT_H_

#include <stdint.h>

#define SIGN_BIT (0x8000)
#define FRAC_BITS (14)
#define FRAC_BASE (1 << FRAC_BITS)
#define FRAC_MSB (1 << (FRAC_BITS-1))
#define FRAC_MASK (FRAC_BASE-1)
#define INT_MASK (~FRAC_MASK)
#define INT_BITS (16-FRAC_BITS)

typedef union {
   uint32_t integer_part;
   uint16_t short_part[2];
} two_shorts;

uint16_t ufixmult(uint16_t o1, uint16_t o2);

char * uctoa(unsigned char c);
char * uitoa(unsigned int v);
uint8_t * uitoh(uint16_t v);
uint8_t * fptoa(uint16_t v, uint8_t decimal_digits);
extern unsigned char ring_buffer_pos;

#endif
