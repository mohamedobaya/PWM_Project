/*
 * WDT_Config.h
 *
 * Created: 5/6/2023 11:13:26 AM
 *  Author: NewVision
 */ 


#ifndef WDT_CONFIG_H_
#define WDT_CONFIG_H_

#include "CPU_Config.h"
#include "WDT_Address.h"

typedef enum
{
	WDT_3V = 0,
	WDT_5V = 1
}WDT_Voltage;
typedef enum
{
	WDT_3V_17ms   = 0,
	WDT_3V_34ms   = 1,
	WDT_3V_68ms   = 2,
	WDT_3V_140ms  = 3,
	WDT_3V_270ms  = 4,
	WDT_3V_550ms  = 5,
	WDT_3V_1100ms = 6,
	WDT_3V_2200ms = 7,
	WDT_5V_16ms   = 8,
	WDT_5V_32ms   = 9,
	WDT_5V_65ms   = 10,
	WDT_5V_130ms  = 11,
	WDT_5V_260ms  = 12,
	WDT_5V_520ms  = 13,
	WDT_5V_1000ms = 14,
	WDT_5V_2100ms = 15
}WDT_Prescaler;



#endif /* WDT_CONFIG_H_ */