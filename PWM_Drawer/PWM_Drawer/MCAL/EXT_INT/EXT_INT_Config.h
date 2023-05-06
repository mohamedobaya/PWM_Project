/*
 * EXT_INT_Config.h
 *
 * Created: 5/5/2023 9:24:36 AM
 *  Author: NewVision
 */ 


#ifndef EXT_INT_CONFIG_H_
#define EXT_INT_CONFIG_H_

#include "CPU_Config.h"
#include "EXT_INT_Address.h"

// External interrupts in MC
typedef enum
{
	EXT_INT0,
	EXT_INT1,
	EXT_INT2
}EXT_INT;

// External Interrupt Trigger
typedef enum
{
	EXT_INT_LOW,
	EXT_INT_HIGH,
	EXT_INT_FALL,
	EXT_INT_RISE
}EXT_INT_TRIGGER;

#endif /* EXT_INT_CONFIG_H_ */