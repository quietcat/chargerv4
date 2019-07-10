#ifndef CLOCK_H_
#define CLOCK_H_

void clock_service(char msg);

// increased every 10 ms
extern volatile unsigned long ticks;
extern unsigned long seconds;
extern unsigned char hundredths;
extern volatile bit reset_watchdog;

#define MAX_TICK (0xffffffffL / 1000L * 1000L) // largest multiple of 1000 that can fit in 64 bits

void set_timer(char timer_id, char time_in_sec);

#endif
