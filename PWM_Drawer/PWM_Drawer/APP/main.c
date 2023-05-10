/*
 * PWM_Drawer.c
 *
 * Created: 5/4/2023 5:34:52 PM
 * Author : NewVision
 */ 

#include "main.h"

uint8_t duty;

int main(void)
{
    fint32_t time;
    uint32_t freq;
	DIO_SET_PIN_DIR(DIO_PORTB, DIO_PIN3, DIO_OUT);
	DIO_SET_PIN_DIR(DIO_PORTD, DIO_PIN6, DIO_IN);
	
	TIMER_INIT(CHANNEL_0, PWM_MODE, FREQ_1_KHZ);
	TIMER_START_PWM(CHANNEL_0);
	TIMER_RUN_PWM(CHANNEL_0, 128);
	
	TIMER_INIT(CHANNEL_1, ICU_MODE, ICU_PRESCALER);
	
	TIMER_GET_DUTY_CYCLE_AND_FREQUENCY(&duty, &freq);
	_delay_ms(1000);
	
	time = ((1 / ((fint32_t) freq)) * 1000000);
	
	LCD_INIT();
	LCD_CLR();
	// duty = 0;
    while (1) 
    {
		LCD_CLR();
		
		
		LCD_WRITE_STR((uint8_t *) "freq= ");
		LCD_WRITE_NUM(freq);
		LCD_WRITE_STR((uint8_t *) " Hz");
		
		LCD_WRITE_STR((uint8_t *) "	,duty= ");
		LCD_WRITE_NUM(duty);
		LCD_WRITE_CHAR('%');
		
		LCD_WRITE_STR((uint8_t *) "	,time = ");
		LCD_WRITE_NUM((uint32_t) time);
		LCD_WRITE_STR((uint8_t *) "us");
		
		LCD_NEXT_LINE();
		
		uint8_t i, j;
		uint16_t up = duty / 10;
		uint16_t down = 10 - up;
		
		uint8_t loop_count = 40 / (up + down);
		for (i = 0; i < loop_count; i++)
		{
			for (j = 0; j < down; j++)
			{
				LCD_WRITE_CHAR('_');
				_delay_ms(250);
			}
			for (j = 0; j < up; j++)
			{
				LCD_WRITE_CHAR('-');
				_delay_ms(250);
			}
		}
		_delay_ms(750);
					
	}
}

ISR(INT0_vect)
{
	
}

ISR(INT1_vect)
{
	
}