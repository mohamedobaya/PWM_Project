/*
 * LCD.c
 *
 * Created: 4/28/2023 9:00:35 AM
 *  Author: NewVision
 */ 

#include "LCD.h"

void LCD_INIT(void)
{
	// Pins Direction
	DIO_SET_PIN_DIR(LCD_CNTRL_PORT, LCD_RS, LCD_OUT);
	DIO_SET_PIN_DIR(LCD_CNTRL_PORT, LCD_RW, LCD_OUT);
	DIO_SET_PIN_DIR(LCD_CNTRL_PORT, LCD_EN, LCD_OUT);
	
	DIO_SET_PIN_DIR(LCD_DATA_PORT, LCD_D4, LCD_OUT);
	DIO_SET_PIN_DIR(LCD_DATA_PORT, LCD_D5, LCD_OUT);
	DIO_SET_PIN_DIR(LCD_DATA_PORT, LCD_D6, LCD_OUT);
	DIO_SET_PIN_DIR(LCD_DATA_PORT, LCD_D7, LCD_OUT);
	
	_delay_ms(2);
	LCD_WRITE_CMD(0x33);	// for initialization
	LCD_WRITE_CMD(0x32);	// for initialization
	LCD_WRITE_CMD(0x28);	// for initialization
	LCD_WRITE_CMD(0x01);	// Clear LCD
	LCD_WRITE_CMD(0x0C);	// display On, cursor off
	//LCD_WRITE_CMD(0x0E);	// display On, cursor on
	LCD_WRITE_CMD(0x06);	//	shift cursor right
	_delay_ms(5);
}

void LCD_WRITE_CMD(uint8_t cmd)
{
	// Register select will select control register
	DIO_SET_PIN_VAL(LCD_CNTRL_PORT, LCD_RS, LCD_LOW);
	// Write on LCD
	DIO_SET_PIN_VAL(LCD_CNTRL_PORT, LCD_RW, LCD_LOW);
	// Set enable pin as low, to ensure logic(0)
	DIO_SET_PIN_VAL(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	
	// Send high nibble first
	LCD = (cmd & 0xF0) | (LCD & 0x0F);
	// Send High to low pulse
	DIO_SET_PIN_VAL(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SET_PIN_VAL(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	// Send low nibble last
	LCD = ((cmd & 0x0F) << 4) | (LCD & 0x0F);
	// Send High to low pulse
	DIO_SET_PIN_VAL(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SET_PIN_VAL(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	_delay_ms(5);
}

void LCD_WRITE_CHAR(uint8_t ch)
{
	// Register select will select control register
	DIO_SET_PIN_VAL(LCD_CNTRL_PORT, LCD_RS, LCD_HIGH);
	// Write on LCD
	DIO_SET_PIN_VAL(LCD_CNTRL_PORT, LCD_RW, LCD_LOW);
	// Set enable pin as low, to ensure logic(0)
	DIO_SET_PIN_VAL(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	
	// Send high nibble first
	LCD = (ch & 0xF0) | (LCD & 0x0F);
	// Send High to low pulse
	DIO_SET_PIN_VAL(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SET_PIN_VAL(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	// Send low nibble last
	LCD = ((ch & 0x0F) << 4) | (LCD & 0x0F);
	// Send High to low pulse
	DIO_SET_PIN_VAL(LCD_CNTRL_PORT, LCD_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SET_PIN_VAL(LCD_CNTRL_PORT, LCD_EN, LCD_LOW);
	_delay_ms(5);
}

void LCD_WRITE_STR(uint8_t * s)
{
	while (*s != '\0')
	{
		LCD_WRITE_CHAR(*s);
		_delay_ms(10);
		s++;
	}
}

void LCD_WRITE_NUM(uint32_t num)
{
	if (num == 0)
	{
		LCD_WRITE_CHAR('0');
		return;
	}
	uint8_t num_str[10];
	IntegerToString(num_str, num);
	LCD_WRITE_STR(num_str);
}

void LCD_CLR(void)
{
	LCD_WRITE_CMD(0x01);
}

void LCD_NEXT_LINE(void)
{
	LCD_WRITE_CMD(0xC0);	// move cursor to the 2nd line
}