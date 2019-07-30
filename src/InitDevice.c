//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include <SI_C8051F850_Register_Enums.h>
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	WDT_0_enter_DefaultMode_from_RESET();
	CLOCK_0_enter_DefaultMode_from_RESET();
	PORTS_0_enter_DefaultMode_from_RESET();
	PORTS_1_enter_DefaultMode_from_RESET();
	PORTS_2_enter_DefaultMode_from_RESET();
	PBCFG_0_enter_DefaultMode_from_RESET();
	ADC_0_enter_DefaultMode_from_RESET();
	TIMER01_0_enter_DefaultMode_from_RESET();
	TIMER16_3_enter_DefaultMode_from_RESET();
	TIMER_SETUP_0_enter_DefaultMode_from_RESET();
	UART_0_enter_DefaultMode_from_RESET();
	VREF_0_enter_DefaultMode_from_RESET();
	INTERRUPT_0_enter_DefaultMode_from_RESET();
	// [Config Calls]$

}

extern void PORTS_0_enter_DefaultMode_from_RESET(void) {

	// $[P0 - Port 0 Pin Latch]
	/***********************************************************************
	 - P0.0 is high. Set P0.0 to drive or float high
	 - P0.1 is high. Set P0.1 to drive or float high
	 - P0.2 is high. Set P0.2 to drive or float high
	 - P0.3 is high. Set P0.3 to drive or float high
	 - P0.4 is high. Set P0.4 to drive or float high
	 - P0.5 is high. Set P0.5 to drive or float high
	 - P0.6 is low. Set P0.6 to drive low
	 - P0.7 is high. Set P0.7 to drive or float high
	 ***********************************************************************/
	P0 = P0_B0__HIGH | P0_B1__HIGH | P0_B2__HIGH | P0_B3__HIGH | P0_B4__HIGH
			| P0_B5__HIGH | P0_B6__LOW | P0_B7__HIGH;
	// [P0 - Port 0 Pin Latch]$

	// $[P0MDOUT - Port 0 Output Mode]
	/***********************************************************************
	 - P0.0 output is open-drain
	 - P0.1 output is open-drain
	 - P0.2 output is open-drain
	 - P0.3 output is push-pull
	 - P0.4 output is push-pull
	 - P0.5 output is open-drain
	 - P0.6 output is push-pull
	 - P0.7 output is push-pull
	 ***********************************************************************/
	P0MDOUT = P0MDOUT_B0__OPEN_DRAIN | P0MDOUT_B1__OPEN_DRAIN
			| P0MDOUT_B2__OPEN_DRAIN | P0MDOUT_B3__PUSH_PULL
			| P0MDOUT_B4__PUSH_PULL | P0MDOUT_B5__OPEN_DRAIN
			| P0MDOUT_B6__PUSH_PULL | P0MDOUT_B7__PUSH_PULL;
	// [P0MDOUT - Port 0 Output Mode]$

	// $[P0MDIN - Port 0 Input Mode]
	/***********************************************************************
	 - P0.0 pin is configured for analog mode
	 - P0.1 pin is configured for analog mode
	 - P0.2 pin is configured for analog mode
	 - P0.3 pin is configured for digital mode
	 - P0.4 pin is configured for digital mode
	 - P0.5 pin is configured for digital mode
	 - P0.6 pin is configured for digital mode
	 - P0.7 pin is configured for digital mode
	 ***********************************************************************/
	P0MDIN = P0MDIN_B0__ANALOG | P0MDIN_B1__ANALOG | P0MDIN_B2__ANALOG
			| P0MDIN_B3__DIGITAL | P0MDIN_B4__DIGITAL | P0MDIN_B5__DIGITAL
			| P0MDIN_B6__DIGITAL | P0MDIN_B7__DIGITAL;
	// [P0MDIN - Port 0 Input Mode]$

	// $[P0SKIP - Port 0 Skip]
	/***********************************************************************
	 - P0.0 pin is skipped by the crossbar
	 - P0.1 pin is skipped by the crossbar
	 - P0.2 pin is skipped by the crossbar
	 - P0.3 pin is not skipped by the crossbar
	 - P0.4 pin is not skipped by the crossbar
	 - P0.5 pin is not skipped by the crossbar
	 - P0.6 pin is not skipped by the crossbar
	 - P0.7 pin is not skipped by the crossbar
	 ***********************************************************************/
	P0SKIP = P0SKIP_B0__SKIPPED | P0SKIP_B1__SKIPPED | P0SKIP_B2__SKIPPED
			| P0SKIP_B3__NOT_SKIPPED | P0SKIP_B4__NOT_SKIPPED
			| P0SKIP_B5__NOT_SKIPPED | P0SKIP_B6__NOT_SKIPPED
			| P0SKIP_B7__NOT_SKIPPED;
	// [P0SKIP - Port 0 Skip]$

	// $[P0MASK - Port 0 Mask]
	// [P0MASK - Port 0 Mask]$

	// $[P0MAT - Port 0 Match]
	// [P0MAT - Port 0 Match]$

}

extern void PBCFG_0_enter_DefaultMode_from_RESET(void) {

	// $[XBR0 - Port I/O Crossbar 0]
	/***********************************************************************
	 - UART TX, RX routed to Port pins P0.4 and P0.5
	 - SPI I/O unavailable at Port pins
	 - SMBus0 I/O unavailable at Port pins
	 - CP0 unavailable at Port pin
	 - Asynchronous CP0 unavailable at Port pin
	 - CP1 unavailable at Port pin
	 - Asynchronous CP1 unavailable at Port pin
	 - SYSCLK unavailable at Port pin
	 ***********************************************************************/
	XBR0 = XBR0_URT0E__ENABLED | XBR0_SPI0E__DISABLED | XBR0_SMB0E__DISABLED
			| XBR0_CP0E__DISABLED | XBR0_CP0AE__DISABLED | XBR0_CP1E__DISABLED
			| XBR0_CP1AE__DISABLED | XBR0_SYSCKE__DISABLED;
	// [XBR0 - Port I/O Crossbar 0]$

	// $[XBR1 - Port I/O Crossbar 1]
	// [XBR1 - Port I/O Crossbar 1]$

	// $[XBR2 - Port I/O Crossbar 2]
	/***********************************************************************
	 - Weak Pullups enabled 
	 - Crossbar enabled
	 ***********************************************************************/
	XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED;
	// [XBR2 - Port I/O Crossbar 2]$

	// $[PRTDRV - Port Drive Strength]
	// [PRTDRV - Port Drive Strength]$

}

extern void WDT_0_enter_DefaultMode_from_RESET(void) {

	// $[Watchdog Timer Init Variable Declarations]
	uint32_t i;
	bool ea;
	// [Watchdog Timer Init Variable Declarations]$

	// $[WDTCN - Watchdog Timer Control]
	// Deprecated
	// [WDTCN - Watchdog Timer Control]$

	// $[WDTCN_2 - Watchdog Timer Control]

	// Feed WDT timer before disabling (Erratum WDT_E102)
	WDTCN = 0xA5;

	// Add 2 LFO cycle delay before disabling WDT (Erratum WDT_E102)
	for (i = 0; i < (2 * 3062500UL) / (10000 * 3); i++) {
		NOP();
	}

	// Disable WDT
	ea = IE_EA;
	IE_EA = 0;
	WDTCN = 0xDE;
	WDTCN = 0xAD;
	IE_EA = ea;

	// [WDTCN_2 - Watchdog Timer Control]$

}

extern void ADC_0_enter_DefaultMode_from_RESET(void) {

	// $[ADC0GTH - ADC0 Greater-Than High Byte]
	// [ADC0GTH - ADC0 Greater-Than High Byte]$

	// $[ADC0GTL - ADC0 Greater-Than Low Byte]
	// [ADC0GTL - ADC0 Greater-Than Low Byte]$

	// $[ADC0LTH - ADC0 Less-Than High Byte]
	// [ADC0LTH - ADC0 Less-Than High Byte]$

	// $[ADC0LTL - ADC0 Less-Than Low Byte]
	// [ADC0LTL - ADC0 Less-Than Low Byte]$

	// $[ADC0PWR - ADC0 Power Control]
	/***********************************************************************
	 - Burst Mode Power Up Time = 0x0F
	 - Disable low power mode
	 - Low power mode disabled
	 - Select bias current mode 3 
	 ***********************************************************************/
	ADC0PWR = (0x0F << ADC0PWR_ADPWR__SHIFT) | ADC0PWR_ADLPM__LP_BUFFER_DISABLED
			| ADC0PWR_ADMXLP__LP_MUX_VREF_DISABLED | ADC0PWR_ADBIAS__MODE3;
	// [ADC0PWR - ADC0 Power Control]$

	// $[ADC0TK - ADC0 Burst Mode Track Time]
	// [ADC0TK - ADC0 Burst Mode Track Time]$

	// $[ADC0MX - ADC0 Multiplexer Selection]
	/***********************************************************************
	 - Select ADC0.0
	 ***********************************************************************/
	ADC0MX = ADC0MX_ADC0MX__ADC0P0;
	// [ADC0MX - ADC0 Multiplexer Selection]$

	// $[ADC0AC - ADC0 Accumulator Configuration]
	/***********************************************************************
	 - Left justified. No shifting applied
	 - Disable 12-bit mode
	 - ADC0H:ADC0L contain the result of the latest conversion when Burst
	 Mode is disabled
	 - Perform and Accumulate 1 conversion 
	 ***********************************************************************/
	ADC0AC = ADC0AC_ADSJST__LEFT_NO_SHIFT | ADC0AC_AD12BE__12_BIT_DISABLED
			| ADC0AC_ADAE__ACC_DISABLED | ADC0AC_ADRPT__ACC_1;
	// [ADC0AC - ADC0 Accumulator Configuration]$

	// $[ADC0CF - ADC0 Configuration]
	/***********************************************************************
	 - SAR Clock Divider = 0x06
	 - ADC0 operates in 8-bit mode
	 - The on-chip PGA gain is 1
	 - Delayed Track Mode
	 ***********************************************************************/
	ADC0CF = (0x06 << ADC0CF_ADSC__SHIFT) | ADC0CF_AD8BE__8_BIT
			| ADC0CF_ADGN__GAIN_1 | ADC0CF_ADTM__TRACK_DELAYED;
	// [ADC0CF - ADC0 Configuration]$

	// $[ADC0CN1 - ADC0 Control 1]
	// [ADC0CN1 - ADC0 Control 1]$

	// $[ADC0CN0 - ADC0 Control 0]
	/***********************************************************************
	 - Enable ADC0 
	 ***********************************************************************/
	ADC0CN0 |= ADC0CN0_ADEN__ENABLED;
	// [ADC0CN0 - ADC0 Control 0]$

}

extern void TIMER16_3_enter_DefaultMode_from_RESET(void) {

	// $[Timer Initialization]
	// Save Timer Configuration
	U8 TMR3CN_TR3_save;
	TMR3CN_TR3_save = TMR3CN & TMR3CN_TR3__BMASK;
	// Stop Timer
	TMR3CN &= ~(TMR3CN_TR3__BMASK);
	// [Timer Initialization]$

	// $[TMR3CN - Timer 3 Control]
	// [TMR3CN - Timer 3 Control]$

	// $[TMR3H - Timer 3 High Byte]
	// [TMR3H - Timer 3 High Byte]$

	// $[TMR3L - Timer 3 Low Byte]
	// [TMR3L - Timer 3 Low Byte]$

	// $[TMR3RLH - Timer 3 Reload High Byte]
	/***********************************************************************
	 - Timer 3 Reload High Byte = 0xF8
	 ***********************************************************************/
	TMR3RLH = (0xF8 << TMR3RLH_TMR3RLH__SHIFT);
	// [TMR3RLH - Timer 3 Reload High Byte]$

	// $[TMR3RLL - Timer 3 Reload Low Byte]
	/***********************************************************************
	 - Timer 3 Reload Low Byte = 0x06
	 ***********************************************************************/
	TMR3RLL = (0x06 << TMR3RLL_TMR3RLL__SHIFT);
	// [TMR3RLL - Timer 3 Reload Low Byte]$

	// $[TMR3CN]
	/***********************************************************************
	 - Start Timer 3 running
	 ***********************************************************************/
	TMR3CN |= TMR3CN_TR3__RUN;
	// [TMR3CN]$

	// $[Timer Restoration]
	// Restore Timer Configuration
	TMR3CN |= TMR3CN_TR3_save;
	// [Timer Restoration]$

}

extern void TIMER_SETUP_0_enter_DefaultMode_from_RESET(void) {

	// $[CKCON - Clock Control]
	/***********************************************************************
	 - System clock divided by 12
	 - Counter/Timer 0 uses the clock defined by the prescale field, SCA
	 - Timer 2 high byte uses the clock defined by the T2XCLK bit in TMR2CN
	 - Timer 2 low byte uses the clock defined by the T2XCLK bit in TMR2CN
	 - Timer 3 high byte uses the clock defined by the T3XCLK bit in TMR3CN
	 - Timer 3 low byte uses the clock defined by the T3XCLK bit in TMR3CN
	 - Timer 1 uses the system clock
	 ***********************************************************************/
	CKCON = CKCON_SCA__SYSCLK_DIV_12 | CKCON_T0M__PRESCALE
			| CKCON_T2MH__EXTERNAL_CLOCK | CKCON_T2ML__EXTERNAL_CLOCK
			| CKCON_T3MH__EXTERNAL_CLOCK | CKCON_T3ML__EXTERNAL_CLOCK
			| CKCON_T1M__SYSCLK;
	// [CKCON - Clock Control]$

	// $[TMOD - Timer 0/1 Mode]
	/***********************************************************************
	 - Mode 0, 13-bit Counter/Timer
	 - Timer Mode
	 - Timer 0 enabled when TR0 = 1 irrespective of /INT0 logic level
	 - Mode 2, 8-bit Counter/Timer with Auto-Reload
	 - Timer Mode
	 - Timer 1 enabled when TR1 = 1 irrespective of /INT1 logic level
	 ***********************************************************************/
	TMOD = TMOD_T0M__MODE0 | TMOD_CT0__TIMER | TMOD_GATE0__DISABLED
			| TMOD_T1M__MODE2 | TMOD_CT1__TIMER | TMOD_GATE1__DISABLED;
	// [TMOD - Timer 0/1 Mode]$

	// $[TCON - Timer 0/1 Control]
	/***********************************************************************
	 - Start Timer 1 running
	 ***********************************************************************/
	TCON |= TCON_TR1__RUN;
	// [TCON - Timer 0/1 Control]$

}

extern void UART_0_enter_DefaultMode_from_RESET(void) {

	// $[SCON0 - UART0 Serial Port Control]
	/***********************************************************************
	 - UART0 reception enabled
	 ***********************************************************************/
	SCON0 |= SCON0_REN__RECEIVE_ENABLED;
	// [SCON0 - UART0 Serial Port Control]$

}

extern void VREF_0_enter_DefaultMode_from_RESET(void) {

	// $[REF0CN - Voltage Reference Control]
	/***********************************************************************
	 - The ADC0 voltage reference is the VDD pin
	 - The internal reference operates at 1.65 V nominal
	 - The ADC0 ground reference is the GND pin
	 - Disable the Temperature Sensor
	 ***********************************************************************/
	REF0CN = REF0CN_REFSL__VDD_PIN | REF0CN_IREFLVL__1P65
			| REF0CN_GNDSL__GND_PIN | REF0CN_TEMPE__TEMP_DISABLED;
	// [REF0CN - Voltage Reference Control]$

}

extern void INTERRUPT_0_enter_DefaultMode_from_RESET(void) {

	// $[EIE1 - Extended Interrupt Enable 1]
	/***********************************************************************
	 - Enable interrupt requests generated by the ADINT flag
	 - Disable CP0 interrupts
	 - Disable CP1 interrupts
	 - Disable all Port Match interrupts
	 - Disable all PCA0 interrupts
	 - Disable all SMB0 interrupts
	 - Enable interrupt requests generated by the TF3L or TF3H flags
	 - Disable ADC0 Window Comparison interrupt
	 ***********************************************************************/
	EIE1 = EIE1_EADC0__ENABLED | EIE1_ECP0__DISABLED | EIE1_ECP1__DISABLED
			| EIE1_EMAT__DISABLED | EIE1_EPCA0__DISABLED | EIE1_ESMB0__DISABLED
			| EIE1_ET3__ENABLED | EIE1_EWADC0__DISABLED;
	// [EIE1 - Extended Interrupt Enable 1]$

	// $[EIP1 - Extended Interrupt Priority 1]
	// [EIP1 - Extended Interrupt Priority 1]$

	// $[IE - Interrupt Enable]
	/***********************************************************************
	 - Enable each interrupt according to its individual mask setting
	 - Disable external interrupt 0
	 - Disable external interrupt 1
	 - Disable all SPI0 interrupts
	 - Disable all Timer 0 interrupt
	 - Disable all Timer 1 interrupt
	 - Disable Timer 2 interrupt
	 - Enable UART0 interrupt
	 ***********************************************************************/
	IE = IE_EA__ENABLED | IE_EX0__DISABLED | IE_EX1__DISABLED
			| IE_ESPI0__DISABLED | IE_ET0__DISABLED | IE_ET1__DISABLED
			| IE_ET2__DISABLED | IE_ES0__ENABLED;
	// [IE - Interrupt Enable]$

	// $[IP - Interrupt Priority]
	// [IP - Interrupt Priority]$

}

extern void TIMER01_0_enter_DefaultMode_from_RESET(void) {

	// $[Timer Initialization]
	//Save Timer Configuration
	U8 TCON_save;
	TCON_save = TCON;
	//Stop Timers
	TCON &= ~TCON_TR0__BMASK & ~TCON_TR1__BMASK;

	// [Timer Initialization]$

	// $[TH0 - Timer 0 High Byte]
	// [TH0 - Timer 0 High Byte]$

	// $[TL0 - Timer 0 Low Byte]
	// [TL0 - Timer 0 Low Byte]$

	// $[TH1 - Timer 1 High Byte]
	/***********************************************************************
	 - Timer 1 High Byte = 0x96
	 ***********************************************************************/
	TH1 = (0x96 << TH1_TH1__SHIFT);
	// [TH1 - Timer 1 High Byte]$

	// $[TL1 - Timer 1 Low Byte]
	// [TL1 - Timer 1 Low Byte]$

	// $[Timer Restoration]
	//Restore Timer Configuration
	TCON |= (TCON_save & TCON_TR0__BMASK) | (TCON_save & TCON_TR1__BMASK);

	// [Timer Restoration]$

}

extern void CLOCK_0_enter_DefaultMode_from_RESET(void) {

	// $[CLKSEL - Clock Select]
	/***********************************************************************
	 - Clock derived from the Internal High-Frequency Oscillator
	 - SYSCLK is equal to selected clock source divided by 1
	 ***********************************************************************/
	CLKSEL = CLKSEL_CLKSL__HFOSC | CLKSEL_CLKDIV__SYSCLK_DIV_1;
	// [CLKSEL - Clock Select]$

}

extern void PMU_0_enter_DefaultMode_from_RESET(void) {

}

extern void PORTS_1_enter_DefaultMode_from_RESET(void) {

	// $[P1 - Port 1 Pin Latch]
	// [P1 - Port 1 Pin Latch]$

	// $[P1MDOUT - Port 1 Output Mode]
	/***********************************************************************
	 - P1.0 output is push-pull
	 - P1.1 output is push-pull
	 - P1.2 output is open-drain
	 - P1.3 output is push-pull
	 ***********************************************************************/
	P1MDOUT = P1MDOUT_B0__PUSH_PULL | P1MDOUT_B1__PUSH_PULL
			| P1MDOUT_B2__OPEN_DRAIN | P1MDOUT_B3__PUSH_PULL;
	// [P1MDOUT - Port 1 Output Mode]$

	// $[P1MDIN - Port 1 Input Mode]
	// [P1MDIN - Port 1 Input Mode]$

	// $[P1SKIP - Port 1 Skip]
	// [P1SKIP - Port 1 Skip]$

	// $[P1MASK - Port 1 Mask]
	// [P1MASK - Port 1 Mask]$

	// $[P1MAT - Port 1 Match]
	// [P1MAT - Port 1 Match]$

}

extern void PORTS_2_enter_DefaultMode_from_RESET(void) {
	// $[P2 - Port 2 Pin Latch]
	// [P2 - Port 2 Pin Latch]$

	// $[P2MDOUT - Port 2 Output Mode]
	/***********************************************************************
	 - P2.0 output is push-pull
	 ***********************************************************************/
	P2MDOUT = P2MDOUT_B0__PUSH_PULL;
	// [P2MDOUT - Port 2 Output Mode]$

}

