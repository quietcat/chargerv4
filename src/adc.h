/*
 * adc.h
 *
 *  Created on: Feb 21, 2015
 *      Author: denis
 */

#ifndef ADC_H_
#define ADC_H_

extern unsigned char temp_value;
extern unsigned char volt_value;
extern unsigned char batn_value;

void adc_service(char msg);

#endif /* ADC_H_ */
