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

void TIMER_init();//initialize Timer0
void TIMER_delay(uint16_t millisec); //delay of specific amount default uses 256 prescalar


#endif /* TIMER0_H_ */