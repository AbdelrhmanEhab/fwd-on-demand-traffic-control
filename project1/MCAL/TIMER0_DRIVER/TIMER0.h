/*
 * TIMER0.h
 *
 * Created: 1/7/2023 1:48:55 PM
 *  Author: Abdelrhman Ehab
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "TIMER0_config.h"
#include "../INTERRUPTS_DRIVER/INTERRUPT.h"
#include "../../Utilites/typedefs.h"

void TIMER0_init();
void TIMER0_start();
void TIMER0_stop();
void TIMER0_delay(uint16_t millisec);
//setting the initial value
void TIMER0_set_value(uint8_t value);
void TIMER0_reset();


#endif /* TIMER0_H_ */