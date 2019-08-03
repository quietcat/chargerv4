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

unsigned int ufixmult(unsigned int o1, unsigned int o2);

char * uctoa(unsigned char c);
char * uitoa(unsigned int v);
char * uitoh(unsigned int v);
char * fptoa(unsigned int v);

#endif
