/*
 * charger.h
 *
 *  Created on: Feb 23, 2015
 *      Author: denis
 */

#ifndef CHARGER_H_
#define CHARGER_H_

SBIT(BULK_CTL,SFR_P0,6);
#define BULK_ON (BULK_CTL=1)
#define BULK_OFF (BULK_CTL=0)

#define ST_IDLE     1
#define ST_TRICKLE  2
#define ST_BULK_1   3
#define ST_BULK_2   4
#define ST_FULL     5
#define ST_ERROR    6
#define ST_STARTUP  7
#define ST_TOO_HOT  8
#define ST_CAL      9
#define ST_MANUAL   10
extern char cstate;

void charger_service(char msg);
void print_data2(void);

#undef TEMP_SENSOR_5K

#endif /* CHARGER_H_ */
