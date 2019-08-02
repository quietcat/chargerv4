
// Program Size: data=187.5 xdata=0 const=0 code=5238

#include <compiler_defs.h>
#include "buffer.h"
#include "convert.h"

char * uitoa(unsigned int v) {
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
    {
        char * buf = allocate_buffer(sz);
        char i = sz-1;
        if (buf == NULL) return NULL;
        buf[i] = 0;
        for (i--; i >= 0; i--) {
            buf[i] = (v % 10) + '0';
            v /= 10;
        }
        return buf;
    }
}
