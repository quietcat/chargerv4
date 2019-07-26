/*
 * led.h
 *
 *  Created on: Feb 20, 2015
 *      Author: denis
 */

#ifndef LED_H_
#define LED_H_

void led_service(unsigned char msg);

#undef SINGLE_COLOR

#define LEDR P0_B3
#define LEDG P0_B7
//SBIT(LEDR,SFR_P0,3);
//SBIT(LEDG,SFR_P0,7);

#define LED_OFF (LEDR=0,LEDG=0)
#define LEDR_ON (LEDR=1,LEDG=0)
#define LEDG_ON (LEDG=1,LEDR=0)

#endif /* LED_H_ */
