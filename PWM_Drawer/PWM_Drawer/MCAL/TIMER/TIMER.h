/*
 * TIMER.h
 *
 * Created: 5/5/2023 9:25:08 AM
 *  Author: NewVision
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "TIMER_Config.h"

void TIMER_INIT(TIMER_CHANNEL channel, uint16_t mode, uint8_t prescaler);

void TIMER_START(TIMER_CHANNEL channel);

void TIMER_STOP(TIMER_CHANNEL channel);

void TIMER_DELAYms_SYNCHRONOUS(TIMER_CHANNEL channel, uint32_t delayed_time);

void TIMER_DELAYms_ASYNCHRONOUS(TIMER_CHANNEL channel, uint32_t delayed_time, void (*operation_pointer)(void), uint8_t operation_type);

void TIMER_RUN_PWM(TIMER_CHANNEL channel, uint8_t duty_cycle);

void TIMER_START_PWM(TIMER_CHANNEL channel);

void TIMER_STOP_PWM(TIMER_CHANNEL channel);

void TIMER_GET_DUTY_CYCLE_AND_FREQUENCY(uint8_t * duty_cycle, uint32_t * frequency);

#endif /* TIMER_H_ */