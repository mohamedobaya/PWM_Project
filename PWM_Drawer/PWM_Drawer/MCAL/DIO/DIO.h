/*
 * DIO.h
 *
 * Created: 5/5/2023 9:23:19 AM
 *  Author: NewVision
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "DIO_Config.h"

void	DIO_SET_PIN_DIR(DIO_PORT port, DIO_PIN pin, DIO_DIR dir);
void	DIO_SET_PIN_VAL(DIO_PORT port, DIO_PIN pin, DIO_VAL val);
uint8_t	DIO_GET_PIN_VAL(DIO_PORT port, DIO_PIN pin);
void	DIO_TGL_PIN_VAL(DIO_PORT port, DIO_PIN pin);
void	DIO_SET_PIN_PULLUP(DIO_PORT port, DIO_PIN pin);

#endif /* DIO_H_ */