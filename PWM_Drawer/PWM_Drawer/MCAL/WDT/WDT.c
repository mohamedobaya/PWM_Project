/*
 * WDT.c
 *
 * Created: 5/6/2023 11:13:42 AM
 *  Author: NewVision
 */ 

#include "WDT.h"

void WDT_Initialize(WDT_Voltage volt)
{
	// Watchdog timer Turn-Off Enable
	SET_BIT(WDTCR, WDTOE);
	// Watchdog timer Enable
	SET_BIT(WDTCR, WDE);
}

void WDT_Start(WDT_Prescaler prescaler)
{
	/*
	switch (prescaler)
	{
		case WDT_3V_17ms:
		CLR_BIT(WDTCR, WDP2);CLR_BIT(WDTCR, WDP1);CLR_BIT(WDTCR, WDP0);
		break;
		case WDT_3V_34ms:
		CLR_BIT(WDTCR, WDP2);CLR_BIT(WDTCR, WDP1);SET_BIT(WDTCR, WDP0);
		break;
	}
	*/
	//Choose 5V 2.1seconds
	SET_BIT(WDTCR, WDP2);SET_BIT(WDTCR, WDP1);SET_BIT(WDTCR, WDP0);
}

void WDT_Refresh(void)
{
	//Watchdog reset timer
	asm("WDR");
}