/*
 * EXT_INT.c
 *
 * Created: 5/5/2023 9:24:43 AM
 *  Author: NewVision
 */ 


#include "EXT_INT.h"

void EXT_INT_INIT(EXT_INT ext_interrupt, EXT_INT_TRIGGER trigger)
{
	//Disable Global interrupt, to ensure that interrupt initialized successfully
	cli();	// or - CLR_BIT(SREG, 7);
	//-------------------------------------------------
	switch(ext_interrupt)
	{
		// external interrupt 0
		case EXT_INT0:
		SET_BIT(GICR, INT0);	// activate external interrupt 0
		switch(trigger)			// when to trigger interrupt
		{
			case EXT_INT_LOW:
			CLR_BIT(MCUCSR, ISC01);CLR_BIT(MCUCSR, ISC00);
			break;
			
			case EXT_INT_HIGH:
			CLR_BIT(MCUCSR, ISC01);SET_BIT(MCUCSR, ISC00);
			break;
			
			case EXT_INT_FALL:
			SET_BIT(MCUCSR, ISC01);CLR_BIT(MCUCSR, ISC00);
			break;
			
			case EXT_INT_RISE:
			SET_BIT(MCUCSR, ISC01);SET_BIT(MCUCSR, ISC00);
			break;
		}
		break;
		
		// external interrupt 1
		case EXT_INT1:
		SET_BIT(GICR, INT1);	// activate external interrupt 1
		switch(trigger)			// when to trigger interrupt
		{
			case EXT_INT_LOW:
			CLR_BIT(MCUCSR, ISC11);CLR_BIT(MCUCSR, ISC10);
			break;
			
			case EXT_INT_HIGH:
			CLR_BIT(MCUCSR, ISC11);SET_BIT(MCUCSR, ISC10);
			break;
			
			case EXT_INT_FALL:
			SET_BIT(MCUCSR, ISC11);CLR_BIT(MCUCSR, ISC10);
			break;
			
			case EXT_INT_RISE:
			SET_BIT(MCUCSR, ISC11);SET_BIT(MCUCSR, ISC10);
			break;
		}
		break;
		
		// external interrupt 2
		case EXT_INT2:
		SET_BIT(GICR, INT2);	// activate external interrupt 2
		switch(trigger)			// when to trigger interrupt
		{
			case EXT_INT_LOW:
			case EXT_INT_HIGH:
			case EXT_INT_FALL:
			CLR_BIT(MCUCSR, ISC2);
			break;
			
			case EXT_INT_RISE:
			SET_BIT(MCUCSR, ISC2);
			break;
		}
		break;
	}
	//-------------------------------------------------
	//Enable Global interrupt, to ensure that interrupt initialized successfully
	sei();	// or - SET_BIT(SREG, 7);
}