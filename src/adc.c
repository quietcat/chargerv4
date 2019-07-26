/*
 * adc.c
 *
 *  Created on: Feb 21, 2015
 *      Author: denis
 */

//#include <compiler_defs.h>
#include <SI_C8051F850_Register_Enums.h>                  // SFR declarations
#include "queue.h"
#include "adc.h"

unsigned char temp_value;
unsigned char volt_value;
unsigned char batn_value;

INTERRUPT_USING (ADC0EOC_ISR, ADC0EOC_IRQn, 3) {
    QUEUE_PUT(MSG_ADC0EOC);
    ADC0CN0_ADINT = 0;
}


void adc_service(msg) {
    switch(msg) {
        case MSG_TICK:
            ADC0CN0_ADBUSY = 1;
            break;
        case MSG_ADC0EOC:
            switch (ADC0MX & ADC0MX_ADC0MX__FMASK) {
            case ADC0MX_ADC0MX__ADC0P0:
                temp_value = ADC0H;
                ADC0MX = ADC0MX_ADC0MX__ADC0P1;
                break;
            case ADC0MX_ADC0MX__ADC0P1:
                volt_value = ADC0H;
                ADC0MX = ADC0MX_ADC0MX__ADC0P2;
                QUEUE_PUT(MSG_VOLTAGE);
                break;
            case ADC0MX_ADC0MX__ADC0P2:
                batn_value = ADC0H;
                ADC0MX = ADC0MX_ADC0MX__ADC0P0;
                break;
            default:
                ADC0MX = ADC0MX_ADC0MX__ADC0P0;
                break;
            }
            break;
    }
}
