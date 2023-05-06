/*
 * TIMER_Config.h
 *
 * Created: 5/5/2023 9:25:29 AM
 *  Author: NewVision
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#include "CPU_Config.h"
#include "TIMER_Address.h"
//------------------------------------------------------//
// Custom prescaler choice
#define TIMER_OPERATION_STOP            0xF8
#define TIMER1_OPERATION_STOP           0xFFF8

// ICU frequency value
#define ICU_FREQ_4_US_DIVIDER			250000
#define ICU_FREQ_0_5_US_DIVIDER			2000000

// Clear to compare mode 1 ms delay
#define TIMER_1_MS_DELAY                250
//------------------------------------------------------//

// Timer Channels
typedef enum
{
	CHANNEL_0,
	CHANNEL_1,
	CHANNEL_2
}TIMER_CHANNEL;

// Timer Prescaler
typedef enum
{
	PRESCALER_1		= 1,
	PRESCALER_8		= 2,
	PRESCALER_64	= 3,
	PRESCALER_256	= 4,
	PRESCALER_1024	= 5,
}TIMER_PRESCALER;

// Timer Modes
typedef enum
{
	DELAY_MODE	= 0x08,
	PWM_MODE	= 0x68,
	ICU_MODE	= 0x0000,
}TIMER_MODE ;

// Timer PWM Frequencies
typedef enum
{
	PH_CORRECT_OFFSET	= 50,
	FREQ_30_HZ			= PRESCALER_1024 + PH_CORRECT_OFFSET,
	FREQ_60_HZ			= PRESCALER_1024,
	FREQ_122_HZ			= PRESCALER_256  + PH_CORRECT_OFFSET,
	FREQ_244_HZ			= PRESCALER_256,
	FREQ_500_HZ			= PRESCALER_64	 + PH_CORRECT_OFFSET,
	FREQ_1_KHZ			= PRESCALER_64,
	FREQ_3_9_KHZ		= PRESCALER_8	 + PH_CORRECT_OFFSET,
	FREQ_7_8_KHZ		= PRESCALER_8,
	FREQ_31_25_KHZ		= PRESCALER_1	 + PH_CORRECT_OFFSET,
	FREQ_62_5_KHZ		= PRESCALER_1,
}TIMER_FREQ;

// Timer Asynchronous Modes
typedef enum
{
	SINGLE_OPERATION,
	PERIODIC_OPERATION,
}TIMER_ASYNCHRONOUS_MODE;

// Default Delay Prescaler
#define DELAY_PRESCALER		PRESCALER_64
// Default ICU Prescaler
#define ICU_PRESCALER		PRESCALER_64

// Correct phase offset
#define PH_CORRECT_MODE       (0x60)

//------------------------------------------------------//
// Global variables for timers

// Global variables used to set timer prescaler
static volatile uint8_t timer0_prescaler;
static volatile uint8_t timer1_prescaler;
static volatile uint8_t timer2_prescaler;

// Global variables used to store the delay time in ms
static volatile uint32_t timer0_delayTimeMs;
static volatile uint32_t timer1_delayTimeMs;
static volatile uint32_t timer2_delayTimeMs;

// Global pointers to function to store the timers callback functions
static void (*ptr_timer0ISR)(void) = NULL;
static void (*ptr_timer1ISR)(void) = NULL;
static void (*ptr_timer2ISR)(void) = NULL;

// Global variables used to set timer asynchronous operation mode
static volatile uint8_t timer0_operation_mode;
static volatile uint8_t timer1_operation_mode;
static volatile uint8_t timer2_operation_mode;

#endif /* TIMER_CONFIG_H_ */