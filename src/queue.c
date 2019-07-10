#include <compiler_defs.h>
//#include <SI_C8051F300_Register_Enums.h>

#include "queue.h"

volatile char SEG_IDATA q_storage[Q_SIZE];

volatile char q_head;
volatile char q_tail;
volatile bit q_full;
volatile char q_param;

void queue_init(void) {
    q_head = 0;
    q_tail = 0;
    q_full = 0;
}

char queue_is_empty(void) {
    return (q_head == q_tail && !q_full);
}

#pragma disable
char deque(void) {
    char rv;
    if (queue_is_empty())
        return 0;
    rv = q_storage[q_tail++];
    q_full = 0;
    if (q_tail == Q_SIZE)
        q_tail = 0;
    return rv;
}

char queue_get(void)
{
    char msg = deque();
    if ( msg < 0 ) {
        msg = -msg;
        q_param = deque();
    }
    return msg;
}
