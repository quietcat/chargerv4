#include "msg_codes.h"

void queue_init(void);

char queue_is_empty(void);

char queue_get(void);

#define Q_SIZE 16

extern SEG_IDATA char q_storage[Q_SIZE];

extern volatile char q_head;
extern volatile char q_tail;
extern volatile bit q_full;
extern volatile char q_param;

#define QUEUE_PUT(event) \
        if ( ! q_full ) {\
            q_storage[q_head++] = (event);\
            if ( q_head == Q_SIZE ) q_head = 0;\
            if ( q_head == q_tail ) q_full = 1;\
        }

#define QUEUE_PUT_PARAM(event,param) \
        QUEUE_PUT(-event);\
        QUEUE_PUT(param);

#define DISABLE_INTERRUPTS IE_EA=0
#define ENABLE_INTERRUPTS IE_EA=1

#define QUEUE_GET_PARAM q_param
