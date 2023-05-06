/*
 * TIMER_Address.h
 *
 * Created: 5/5/2023 9:25:18 AM
 *  Author: NewVision
 */ 


#ifndef TIMER_ADDRESS_H_
#define TIMER_ADDRESS_H_

/*
//-----------------------------------------------------------------//

// General timer registers

// TIMSK register address
#define TIMSK			(*(volatile uint8_t*)(0x59))
// TIFR register bits
#define OCIE0			1
#define OCIE1A			4
#define OCIE1B			3
#define OCIE2			7

// TIFR register address
#define TIFR			(*(volatile uint8_t*)(0x58))
// TIFR register bits
#define OCF0			1	
#define OCF1A			4
#define OCF1B			3
#define OCF2			7
#define ICF1			5
//-----------------------------------------------------------------//

// Timer0 registers 
#define TCCR0           (*(volatile uint8_t*)(0x53))
#define TCNT0           (*(volatile uint8_t*)(0x52))
#define OCR0            (*(volatile uint8_t*)(0x5C))

//-----------------------------------------------------------------//

// Timer1 registers
#define TCCR1           (*(volatile uint16_t*)(0x4E))
#define ICES1			6

#define TCNT1           (*(volatile uint16_t*)(0x4C))
#define OCR1A           (*(volatile uint16_t*)(0x4A))
#define OCR1B           (*(volatile uint16_t*)(0x48))
#define ICR1            (*(volatile uint16_t*)(0x46))

//-----------------------------------------------------------------//

// Timer2 registers
#define TCCR2           (*(volatile uint8_t*)(0x45))
#define TCNT2           (*(volatile uint8_t*)(0x44))
#define OCR2            (*(volatile uint8_t*)(0x43))

*/
#define TCCR1           (*(volatile uint16_t*)(0x4E))



#endif /* TIMER_ADDRESS_H_ */