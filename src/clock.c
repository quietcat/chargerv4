#include <SI_C8051F850_Register_Enums.h>                  // SFR declarations
#include "clock.h"
#include "queue.h"

// increased every 1 ms
unsigned long ticks = 0;
unsigned long seconds = 0;
unsigned char hundredths = 0;
unsigned char minute_second = 0;
volatile bit reset_watchdog = 0;

#define MAX_TIMERS 4

unsigned char SEG_IDATA timers[MAX_TIMERS];

// timer 2 overflow, every 1 ms, using bank 1 of gen purpose regs
INTERRUPT_USING (TIMER3_ISR, TIMER3_IRQn, 2)
{
//    if (reset_watchdog) {
//        PCA0CPH2 = 0x01; // reset watchdog timer
//    }
    QUEUE_PUT(MSG_TICK); // generate timer event
    TMR3CN &= ~TMR3CN_TF3H__BMASK; // clear interrupt
//    TMR2CN_TF2H = 0; // reset TF2H bit to clear interrupt flag, see SFR def in datasheet
}

void clock_service(char msg) {
    switch (msg) {
        case MSG_TICK:
            ticks++;
            if (ticks == MAX_TICK) {
                ticks = 0;
            }
            if ((ticks % 10L) == 0) {
                QUEUE_PUT(MSG_10MS);
//                WDTCN = 0xA5; //reset watchdog
            }
            break;
        case MSG_10MS:
            hundredths++;
            if (hundredths == 100) {
                hundredths = 0;
                seconds++;
                QUEUE_PUT(MSG_SECOND);
            }
            break;
        case MSG_SECOND:
            minute_second++;
            if ( minute_second % 5 == 0) {
            	QUEUE_PUT(MSG_5SECOND);
            }
            if ( minute_second == 60 ) {
                minute_second = 0;
                QUEUE_PUT(MSG_MINUTE);
            }
            {
                int i;
                for ( i = 0; i < MAX_TIMERS; i++ ) {
                    if ( timers[i] > 0 && --timers[i] == 0 ) {
                        QUEUE_PUT(MSG_TIMER+i);
                    }
                }
            }
            break;
        case MSG_INIT:
        case MSG_CLK_RST:
            ticks = 0;
            hundredths = 0;
            seconds = 0;
            minute_second = 0;
            {
                int i;
                for ( i = 0; i < MAX_TIMERS; i++ ) {
                    timers[i] = 0;
                }
            }
            break;
    }
}

void set_timer(char timer_id, char time_in_sec) {
    timers[timer_id-MSG_TIMER_0] = time_in_sec;
}
