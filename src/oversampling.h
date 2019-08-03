/*
 * oversampling.h
 *
 *  Created on: Feb 22, 2015
 *      Author: denis
 */

#ifndef OVERSAMPLING_H_
#define OVERSAMPLING_H_

void oversampling_service(char msg);
extern unsigned int oversampled_voltage;

// two extra bits of resolution
#define SAMPLE_COUNT 256


#endif /* OVERSAMPLING_H_ */
