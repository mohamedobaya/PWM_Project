/*
 * LCD_Config.h
 *
 * Created: 4/28/2023 9:01:17 AM
 *  Author: NewVision
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "CPU_Config.h"

// Ports
#define LCD				PORTA
#define LCD_DATA_PORT	DIO_PORTA	// Data Port
#define LCD_CNTRL_PORT	DIO_PORTC	// Control Port

// Control Pins
#define LCD_RS DIO_PIN0
#define LCD_RW DIO_PIN1
#define LCD_EN DIO_PIN2

// Data Pins
#define LCD_D0 DIO_PIN0
#define LCD_D1 DIO_PIN1
#define LCD_D2 DIO_PIN2
#define LCD_D3 DIO_PIN3
#define LCD_D4 DIO_PIN4
#define LCD_D5 DIO_PIN5
#define LCD_D6 DIO_PIN6
#define LCD_D7 DIO_PIN7

// Direction
#define LCD_OUT	DIO_OUT

//Values
#define LCD_LOW		DIO_LOW
#define LCD_HIGH	DIO_HIGH

#endif /* LCD_CONFIG_H_ */