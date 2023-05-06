/*
 * GRAPH_LCD.h
 *
 * Created: 5/4/2023 6:00:50 PM
 *  Author: NewVision
 */ 


#ifndef GRAPH_LCD_H_
#define GRAPH_LCD_H_

#include "GRAPH_LCD_Config.h"

void GRAPH_LCD_INIT(void);

void GRAPH_LCD_CLR(void);

void GRAPH_LCD_WRITE_CHAR(uint8_t data, uint8_t location);

void GRAPH_LCD_WRITE_STR(void);

#endif /* GRAPH_LCD_H_ */