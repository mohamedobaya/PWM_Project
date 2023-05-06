/*
 * WDT.h
 *
 * Created: 5/6/2023 11:13:34 AM
 *  Author: NewVision
 */ 


#ifndef WDT_H_
#define WDT_H_

#include "WDT_Config.h"

void WDT_Initialize(WDT_Voltage volt);
void WDT_Start(WDT_Prescaler prescaler);
void WDT_Refresh(void);


#endif /* WDT_H_ */