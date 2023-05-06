/*
 * DIO.c
 *
 * Created: 5/5/2023 9:23:07 AM
 *  Author: NewVision
 */ 

#include "DIO.h"

void DIO_SET_PIN_DIR(DIO_PORT port, DIO_PIN pin, DIO_DIR dir)
{
	switch(dir)
	{
		case DIO_IN:
		switch(port)
		{
			case DIO_PORTA:
			CLR_BIT(DDRA, pin);
			break;
			
			case DIO_PORTB:
			CLR_BIT(DDRB, pin);
			break;
			
			case DIO_PORTC:
			CLR_BIT(DDRC, pin);
			break;
			
			case DIO_PORTD:
			CLR_BIT(DDRD, pin);
			break;
		}
		break;
		
		case DIO_OUT:
		switch(port)
		{
			case DIO_PORTA:
			SET_BIT(DDRA, pin);
			break;
			
			case DIO_PORTB:
			SET_BIT(DDRB, pin);
			break;
			
			case DIO_PORTC:
			SET_BIT(DDRC, pin);
			break;
			
			case DIO_PORTD:
			SET_BIT(DDRD, pin);
			break;
		}
		break;
	}
}

void DIO_SET_PIN_VAL(DIO_PORT port, DIO_PIN pin, DIO_VAL val)
{
	switch(val)
	{
		case DIO_LOW:
		switch(port)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA, pin);
			break;
			
			case DIO_PORTB:
			CLR_BIT(PORTB, pin);
			break;
			
			case DIO_PORTC:
			CLR_BIT(PORTC, pin);
			break;
			
			case DIO_PORTD:
			CLR_BIT(PORTD, pin);
			break;
		}
		break;
		
		case DIO_HIGH:
		switch(port)
		{
			case DIO_PORTA:
			SET_BIT(PORTA, pin);
			break;
			
			case DIO_PORTB:
			SET_BIT(PORTB, pin);
			break;
			
			case DIO_PORTC:
			SET_BIT(PORTC, pin);
			break;
			
			case DIO_PORTD:
			SET_BIT(PORTD, pin);
			break;
		}
		break;
	}
}

uint8_t DIO_GET_PIN_VAL(DIO_PORT port, DIO_PIN pin)
{
	uint8_t val = 0;
	switch(port)
	{
		case DIO_PORTA:
		val = GET_BIT(PINA, pin);
		break;
		
		case DIO_PORTB:
		val = GET_BIT(PINB, pin);
		break;
		
		case DIO_PORTC:
		val = GET_BIT(PINC, pin);
		break;
		
		case DIO_PORTD:
		val = GET_BIT(PIND, pin);
		break;
	}
	return val;
}

void DIO_TGL_PIN_VAL(DIO_PORT port, DIO_PIN pin)
{
	switch(port)
	{
		case DIO_PORTA:
		TGL_BIT(PORTA, pin);
		break;
		
		case DIO_PORTB:
		TGL_BIT(PORTB, pin);
		break;
		
		case DIO_PORTC:
		TGL_BIT(PORTC, pin);
		break;
		
		case DIO_PORTD:
		TGL_BIT(PORTD, pin);
		break;
	}
}

void DIO_SET_PIN_PULLUP(DIO_PORT port, DIO_PIN pin)
{
	switch(port)
	{
		case DIO_PORTA:
		SET_BIT(PORTA, pin);
		break;
		
		case DIO_PORTB:
		SET_BIT(PORTB, pin);
		break;
		
		case DIO_PORTC:
		SET_BIT(PORTC, pin);
		break;
		
		case DIO_PORTD:
		SET_BIT(PORTD, pin);
		break;
	}
}
