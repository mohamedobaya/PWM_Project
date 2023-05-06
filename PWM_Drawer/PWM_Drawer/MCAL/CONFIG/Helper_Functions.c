/*
 * Helper_Functions.c
 *
 * Created: 5/5/2023 9:21:15 AM
 *  Author: NewVision
 */ 

#include "Helper_Functions.h"

void IntegerToString(uint8_t * str, uint32_t num)
{
	uint32_t i, rem, len = 0, n;
	
	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
}
