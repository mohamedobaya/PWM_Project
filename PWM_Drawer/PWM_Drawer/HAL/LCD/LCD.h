/*
 * LCD.h
 *
 * Created: 4/28/2023 9:01:06 AM
 *  Author: NewVision
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_Config.h"

void LCD_INIT(void);
void LCD_WRITE_CMD(uint8_t cmd);
void LCD_WRITE_CHAR(uint8_t ch);
void LCD_WRITE_STR(uint8_t * s);
void LCD_WRITE_NUM(uint32_t num);
void LCD_CLR(void);
void LCD_NEXT_LINE(void);



#endif /* LCD_H_ */