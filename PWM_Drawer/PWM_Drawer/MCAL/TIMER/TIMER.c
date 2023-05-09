/*
 * TIMER.c
 *
 * Created: 5/5/2023 9:25:01 AM
 *  Author: NewVision
 */ 

#include "TIMER.h"


void TIMER_INIT(TIMER_CHANNEL channel, uint16_t mode, uint8_t prescaler)
{
	if (mode == (uint16_t) PWM_MODE)
	{
		if (prescaler > (uint8_t) PH_CORRECT_OFFSET)
		{
			mode = (uint16_t) PH_CORRECT_MODE;
			prescaler -= PH_CORRECT_OFFSET;
		}
	}
	
	switch (channel)
	{
		case CHANNEL_0:
		TCCR0 = (uint8_t) mode;
		timer0_prescaler = prescaler;
		break;
		
		case CHANNEL_1:
		TCCR1 = (uint8_t) mode;
		timer1_prescaler = prescaler;
		break;
		
		case CHANNEL_2:
		TCCR2 = (uint8_t) mode;
		timer2_prescaler = prescaler;
		break;
	}
}

void TIMER_START(TIMER_CHANNEL channel)
{
	switch (channel)
	{
		case CHANNEL_0:
		TCNT0 = 0;								// Reset Timer 0 Counter
		TCCR0 |= timer0_prescaler;				// Setting Timer 0 prescaler
		break;
		
		case CHANNEL_1:
		TCNT1 = 0;								// Reset Timer 1 Counter
		TCCR1 |= (uint16_t) timer1_prescaler;	// Setting Timer 1 prescaler
		break;
		
		case CHANNEL_2:
		TCNT2 = 0;								// Reset Timer 2 Counter
		TCCR2 |= timer2_prescaler;				// Setting Timer 2 prescaler
		break;
	}
}

void TIMER_STOP(TIMER_CHANNEL channel)
{
	switch (channel)
	{
		case CHANNEL_0:
		TCNT0 &= TIMER_OPERATION_STOP;
		break;
		
		case CHANNEL_1:
		TCNT1 &= TIMER1_OPERATION_STOP;
		break;
		
		case CHANNEL_2:
		TCNT2 &= TIMER_OPERATION_STOP;
		break;
	}
}

void TIMER_DELAYms_SYNCHRONOUS(TIMER_CHANNEL channel, uint32_t delayed_time)
{
	switch (channel)
	{
		case CHANNEL_0:
		
		OCR0 = TIMER_1_MS_DELAY;			// make a compare match after 1ms
		TIMER_START(CHANNEL_0);				// start timer operation on channel 0
		
		while (delayed_time--)
		{
			while (!GET_BIT(TIFR, OCF0));	// wait until 1ms is over
			
			SET_BIT(TIFR, OCF0);			// clear flag bit
		}
		
		TIMER_STOP(CHANNEL_0);				// stop timer operation on channel 0
		
		break;
		//-----------------------------------------------//
		case CHANNEL_1:
		
		OCR1A = TIMER_1_MS_DELAY;			// make a compare match after 1ms
		TIMER_START(CHANNEL_1);				// start timer operation on channel 0
		
		while (delayed_time--)
		{
			while (!GET_BIT(TIFR, OCF1A));	// wait until 1ms is over
			
			SET_BIT(TIFR, OCF1A);			// clear flag bit
		}
		
		TIMER_STOP(CHANNEL_1);				// stop timer operation on channel 0
		
		break;
		//-----------------------------------------------//
		case CHANNEL_2:
		
		OCR2 = TIMER_1_MS_DELAY;			// make a compare match after 1ms
		TIMER_START(CHANNEL_2);				// start timer operation on channel 0
		
		while (delayed_time--)
		{
			while (!GET_BIT(TIFR, OCF2));	// wait until 1ms is over
			
			SET_BIT(TIFR, OCF2);			// clear flag bit
		}
		
		TIMER_STOP(CHANNEL_2);				// stop timer operation on channel 0
		
		break;
	}
}

void TIMER_DELAYms_ASYNCHRONOUS(TIMER_CHANNEL channel, uint32_t delayed_time, void (*operation_pointer)(void), uint8_t operation_type)
{
	switch (channel)
	{
		case CHANNEL_0:
		
		OCR0 = TIMER_1_MS_DELAY;			// make a compare match after 1ms
		
		//	timer 0 operation parameters
		timer0_delayTimeMs = delayed_time;
		ptr_timer0ISR = operation_pointer;
		timer0_prescaler = operation_type;
		
		// enabling interrupt
		SET_BIT(TIMSK, OCIE0);
		
		TIMER_START(CHANNEL_0);				// start timer operation on channel 0

		break;
		//--------------------------------------------//
		case CHANNEL_1:
		
		OCR1A = TIMER_1_MS_DELAY;			// make a compare match after 1ms
		
		//	timer 1 operation parameters
		timer1_delayTimeMs = delayed_time;
		ptr_timer1ISR = operation_pointer;
		timer1_prescaler = operation_type;
		
		// enabling interrupt
		SET_BIT(TIMSK, OCIE1A);
		
		TIMER_START(CHANNEL_1);				// start timer operation on channel 1

		break;
		//--------------------------------------------//
		case CHANNEL_2:

		OCR2 = TIMER_1_MS_DELAY;			// make a compare match after 1ms
		
		//	timer 2 operation parameters
		timer2_delayTimeMs = delayed_time;
		ptr_timer2ISR = operation_pointer;
		timer2_prescaler = operation_type;
		
		// enabling interrupt
		SET_BIT(TIMSK, OCIE2);
		
		TIMER_START(CHANNEL_2);				// start timer operation on channel 2

		break;
	}
}

void TIMER_RUN_PWM(TIMER_CHANNEL channel, uint8_t duty_cycle)
{
	switch (channel)
	{
		case CHANNEL_0:
		
		OCR0 = duty_cycle;
		
		break;
		//--------------------------------------//
		case CHANNEL_1:
		
		OCR1A = (uint16_t) duty_cycle;
		
		break;
		//--------------------------------------//
		case CHANNEL_2:
		
		OCR2 = duty_cycle;
		
		break;
	}
}

void TIMER_START_PWM(TIMER_CHANNEL channel)
{
	switch (channel)
	{
		case CHANNEL_0:
		
		TIMER_START(CHANNEL_0);
		
		break;
		//--------------------------------------//
		case CHANNEL_1:
		
		TIMER_START(CHANNEL_1);

		break;
		//--------------------------------------//
		case CHANNEL_2:
		
		TIMER_START(CHANNEL_2);
		
		break;
	}
}

void TIMER_STOP_PWM(TIMER_CHANNEL channel)
{
	switch (channel)
	{
		case CHANNEL_0:
		
		TIMER_STOP(CHANNEL_0);
		
		break;
		//--------------------------------------//
		case CHANNEL_1:
		
		TIMER_STOP(CHANNEL_1);

		break;
		//--------------------------------------//
		case CHANNEL_2:
		
		TIMER_STOP(CHANNEL_2);
		
		break;
	}
}

void TIMER_GET_DUTY_CYCLE_AND_FREQUENCY(uint8_t * duty_cycle, uint32_t * frequency)
{
	uint8_t i;
	
	uint16_t capture_values[3] = {0};
	
	uint16_t ton = 0;
	uint16_t time = 0;
	
	SET_BIT(TCCR1, ICES1);
	TIMER_START(CHANNEL_1);
	
	for (i = 0; i < 3; i++)
	{
		while (!GET_BIT(TIFR, ICF1));
		
		capture_values[i] = ICR1;
		
		SET_BIT(TIFR, ICF1);
		
		TGL_BIT(TCCR1, ICES1);
	}
	
	TIMER_STOP(CHANNEL_1);
	
	ton  = capture_values[1] - capture_values[0];
	
	time = capture_values[2] - capture_values[0];
	
	*duty_cycle = (uint8_t) (((uint32_t) ton * 100) / time);
	*frequency	=  ICU_FREQ_4_US_DIVIDER / (uint32_t) time;
}

//--------------------------------------------------------------------------------------------//
// Timers ISRs

// Timer 0 ISR
ISR(TIMER0_COMP_vect)
{
	static uint32_t delay_time_temp = 0;
	delay_time_temp++;
	
	if (delay_time_temp == timer0_delayTimeMs)
	{
		if (ptr_timer0ISR != NULL)
		{
			if (timer0_delayTimeMs == 0)
			{
				ptr_timer0ISR();
				delay_time_temp = 0;
				
				if (timer0_operation_mode == (uint8_t) SINGLE_OPERATION)
					TIMER_STOP(CHANNEL_0);
			}
		}
	}
}

// Timer 1 ISR
ISR(TIMER1_COMPA_vect)
{
	static uint32_t delay_time_temp = 0;
	delay_time_temp++;
	
	if (delay_time_temp == timer1_delayTimeMs)
	{
		if (ptr_timer1ISR != NULL)
		{
			if (timer1_delayTimeMs == 0)
			{
				ptr_timer1ISR();
				delay_time_temp = 0;
				
				if (timer1_operation_mode == (uint8_t) SINGLE_OPERATION)
					TIMER_STOP(CHANNEL_1);
			}
		}
	}
}

// Timer 2 ISR
ISR(TIMER2_COMP_vect)
{
	static uint32_t delay_time_temp = 0;
	delay_time_temp++;
	
	if (delay_time_temp == timer2_delayTimeMs)
	{
		if (ptr_timer2ISR != NULL)
		{
			if (timer2_delayTimeMs == 0)
			{
				ptr_timer2ISR();
				delay_time_temp = 0;
				
				if (timer2_operation_mode == (uint8_t) SINGLE_OPERATION)
					TIMER_STOP(CHANNEL_2);
			}
		}
	}
}