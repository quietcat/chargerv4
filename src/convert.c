
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
