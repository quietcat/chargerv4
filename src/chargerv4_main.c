//=========================================================
// src/chargerv4_main.c: generated by Hardware Configurator
//
// This file will be updated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_C8051F850_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
#include "clock.h"
#include "uart.h"
#include "uart_service.h"
#include "queue.h"
#include "adc.h"
#include "oversampling.h"
#include "charger.h"
#include "led.h"
#include "reporting.h"
#include "buffer.h"

// $[Generated Includes]
// [Generated Includes]$

//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup (void)
{
    // Call hardware initialization routine
    enter_DefaultMode_from_RESET();

//    WDTCN = 0xDE;
//    WDTCN = 0xAD;

  // $[SiLabs Startup]
  // [SiLabs Startup]$
}

void go_idle(void) {

//    PCON = PCON_IDLE__IDLE | PCON_STOP__STOP;

    PCON |= PCON_IDLE__IDLE;         // Enter Idle mode. The processor will
                                     // wake upon receiving an interrupt.

    PCON = PCON;                     // Dummy 3-cycle instruction as per the
                                     // datasheet recommendation for going
                                     // into Idle mode.


}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void)
{

  P("Init\r\n");

  if (RSTSRC & RSTSRC_WDTRSF__BMASK) {
      P("wrst\r\n");
  }
  queue_init(); // initialize event queue
  QUEUE_PUT(MSG_INIT);

  P1_B0 = 1;

  while (1) 
  {
    // $[Generated Run-time code]
    // [Generated Run-time code]$

      char msg = queue_get();

      if ( msg == MSG_EMPTY ) {
          P2_B0 = 1;
          go_idle();
          P2_B0 = 0;
      } else {
          clock_service(msg);
          if (msg == MSG_SECOND) {
              P1_B3 = ~P1_B3;
          }
          uart_service(msg,QUEUE_GET_PARAM);
          adc_service(msg);
          oversampling_service(msg);
          charger_service(msg);
          led_service(msg);
          reporting_service(msg);
      }

  }                             
}
