/*
 * GRAPH_LCD_Config.h
 *
 * Created: 5/4/2023 6:01:00 PM
 *  Author: NewVision
 */ 


#ifndef GRAPH_LCD_CONFIG_H_
#define GRAPH_LCD_CONFIG_H_

#include "CPU_Config.h"

// LCD Ports
#define LCD_CNTRL_PORT	DIO_PORTC	// Control Port
#define LCD_DATA_PORT	DIO_PORTA	// Data Port

// LCD Control Pins
#define LCD_RS			DIO_PIN0
#define LCD_RW			DIO_PIN1
#define LCD_EN			DIO_PIN2
#define LCD_RST			DIO_PIN3
#define LCD_CS1			DIO_PIN4
#define LCD_CS2			DIO_PIN5

// LCD Data Pins
#define LCD_D0			DIO_PIN0
#define LCD_D1			DIO_PIN1
#define LCD_D2			DIO_PIN2
#define LCD_D3			DIO_PIN3
#define LCD_D4			DIO_PIN4
#define LCD_D5			DIO_PIN5
#define LCD_D6			DIO_PIN6
#define LCD_D7			DIO_PIN7

// Direction
#define LCD_OUT			DIO_OUT

// Values
#define LCD_LOW			DIO_LOW
#define LCD_HIGH		DIO_HIGH

// Instructions
#define LCD_ON			0x3F
#define LCD_OFF			0x3E


#endif /* GRAPH_LCD_CONFIG_H_ */