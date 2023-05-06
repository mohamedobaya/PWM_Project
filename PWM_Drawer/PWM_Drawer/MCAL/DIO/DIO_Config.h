/*
 * DIO_Config.h
 *
 * Created: 5/5/2023 9:23:49 AM
 *  Author: NewVision
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#include "CPU_Config.h"
#include "DIO_Address.h"

// Ports
typedef enum
{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}DIO_PORT;

// Pins
typedef enum
{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
}DIO_PIN;

// Direction
typedef enum
{
	DIO_IN,
	DIO_OUT
}DIO_DIR;

// Value
typedef enum
{
	DIO_LOW,
	DIO_HIGH
}DIO_VAL;

#endif /* DIO_CONFIG_H_ */