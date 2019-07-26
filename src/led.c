/*
 * led.c
 *
 *  Created on: Feb 20, 2015
 *      Author: denis
 */
#include <SI_C8051F850_Register_Enums.h>                  // SFR declarations
#include "queue.h"
#include "clock.h"
#include "led.h"
#include "charger.h"

#ifdef SINGLE_COLOR
void led_service(unsigned char msg) {
    switch ( msg ) {
        case MSG_10MS:
            switch (cstate) {
            case ST_IDLE:
                switch (hundredths) {
                case  0: LEDR_ON; break;
                case  1: LED_OFF; break;
                case 25: LEDR_ON; break;
                case 26: LED_OFF; break;
                }
                break;
            case ST_STARTUP:
                switch (hundredths) {
                case  0: LEDR_ON; break;
                case  1: LED_OFF; break;
                case 25: LEDR_ON; break;
                case 26: LED_OFF; break;
                case 50: LEDR_ON; break;
                case 51: LED_OFF; break;
                case 75: LEDR_ON; break;
                case 76: LED_OFF; break;
                }
                break;
            case ST_TRICKLE:
                switch (hundredths) {
                case  0: LEDR_ON; break;
                case  5: LED_OFF; break;
                }
                break;
            case ST_TOO_HOT:
                switch (hundredths) {
                case  0: LEDR_ON; break;
                case 25: LED_OFF; break;
                case 50: LEDR_ON; break;
                case 75: LED_OFF; break;
                }
                break;
            case ST_BULK_1:
            case ST_BULK_2:
                switch (hundredths) {
                case  0: LEDR_ON; break;
                case 95: LED_OFF; break;
                }
                break;
            case ST_FULL:
                switch (hundredths) {
                case  0: LEDR_ON; break;
                case 73: LED_OFF; break;
                case 75: LEDR_ON; break;
                case 98: LED_OFF; break;
                }
                break;
            case ST_ERROR:
                switch (hundredths) {
                case  0:
                    if (LEDR) {
                        LED_OFF;
                    } else {
                        LEDR_ON;
                    }
                    break;
                }
            }
            break;
    }
}
#else
void led_service(unsigned char msg) {
    switch ( msg ) {
        case MSG_10MS:
            switch (cstate) {
            case ST_IDLE:
                switch (hundredths) {
                case  0: LEDG_ON; break;
                case  5: LED_OFF; break;
                case 25: LEDG_ON; break;
                case 30: LED_OFF; break;
                }
                break;
            case ST_STARTUP:
                switch (hundredths) {
                case  0: LEDG_ON; break;
                case  1: LED_OFF; break;
                case 25: LEDG_ON; break;
                case 26: LED_OFF; break;
                case 50: LEDG_ON; break;
                case 51: LED_OFF; break;
                case 75: LEDG_ON; break;
                case 76: LED_OFF; break;
                }
                break;
            case ST_TRICKLE:
                switch (hundredths) {
                case  0: LEDR_ON; break;
                case  5: LED_OFF; break;
                }
                break;
            case ST_TOO_HOT:
                switch (hundredths) {
                case  0: LEDR_ON; break;
                case 25: LED_OFF; break;
                case 50: LEDR_ON; break;
                case 75: LED_OFF; break;
                }
                break;
            case ST_BULK_1:
            case ST_BULK_2:
                switch (hundredths) {
                case  0: LEDR_ON; break;
                case 95: LED_OFF; break;
                }
                break;
            case ST_FULL:
                switch (hundredths) {
                case  0: LEDG_ON; break;
                case 50: LED_OFF; break;
                }
                break;
            case ST_MANUAL:
                switch (hundredths) {
                case  0: BULK_CTL ? LEDR_ON : LEDG_ON; break;
                case 10: LED_OFF; break;
                case 25: BULK_CTL ? LEDR_ON : LEDG_ON; break;
                case 35: LED_OFF; break;
                case 50: BULK_CTL ? LEDR_ON : LEDG_ON; break;
                case 60: LED_OFF; break;
                case 75: BULK_CTL ? LEDR_ON : LEDG_ON; break;
                case 85: LED_OFF; break;
                }
                break;
            case ST_ERROR:
                switch (hundredths) {
                case  0:
                    if (LEDR) {
                        LED_OFF;
                    } else {
                        LEDR_ON;
                    }
                    break;
                }
            }
            break;
    }
}
#endif
