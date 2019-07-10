/*
 * cal.c
 *
 *  Created on: Apr 30, 2018
 *      Author: denis
 */


#include <cal.h>

SEG_CODE CalStruct defaultCal = {
      0,    //        unsigned char slotFree;
     10,    //        unsigned char deltaT;
    240,    //        unsigned char maxTimeBulk;
    240,    //        unsigned char maxTimeTrickle;
     20,    //        unsigned char maxTimeAtMaxV;
    135     //        unsigned char tempHotThr;
};

typedef union {
    CalStruct cal;
    unsigned char bytes[16];
} Cal;

#define CAL_SLOTS_ADDR 0x1D00
#define TOTAL_CAL_SLOTS 255/sizeof(Cal)

SEG_CODE Cal calibrations[TOTAL_CAL_SLOTS] _at_ CAL_SLOTS_ADDR;

CalStruct *cal = &defaultCal;

void findCal() {
    unsigned char i = TOTAL_CAL_SLOTS-1;
    do {
        if (calibrations[i].cal.slotFree != 0xff) {
            cal = &calibrations[i].cal;
            break;
        }
    } while ( i-- > 0);
}

