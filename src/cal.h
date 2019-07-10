/*
 * cal.h
 *
 *  Created on: Apr 30, 2018
 *      Author: denis
 */

#ifndef CAL_H_
#define CAL_H_

#include <compiler_defs.h>

#define CAL_SIZE 16

typedef struct {
    unsigned char slotFree;
    unsigned char deltaT;
    unsigned char maxTimeBulk;
    unsigned char maxTimeTrickle;
    unsigned char maxTimeAtMaxV;
    unsigned char tempHotThr;
} CalStruct;

extern CalStruct *cal;

#endif /* CAL_H_ */
