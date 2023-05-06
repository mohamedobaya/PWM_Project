/*
 * CPU_Config.h
 *
 * Created: 5/5/2023 9:20:12 AM
 *  Author: NewVision
 */ 


#ifndef CPU_CONFIG_H_
#define CPU_CONFIG_H_

#undef F_CPU				// Disable internal crystal
#define F_CPU 16000000		// Enable external crystal
#include <avr/io.h>			// Predefined library for Input & Output
#include <avr/interrupt.h>	// Predefined library for interrupts function
#include <util/delay.h>		// Predefined library for delay functions
// #include <stdlib.h>
#include "STD_TYPES.h"		// Standard DataTypes for general purpose
#include "BIT_MATH.h"		// Bit wise operations
#include "MC_PERIPHERALS.h"	// MicroController Peripherals
#include "Helper_Functions.h"



#endif /* CPU_CONFIG_H_ */