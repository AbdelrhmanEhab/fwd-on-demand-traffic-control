/*
 * INTERRUPT.h
 *
 * Created: 1/7/2023 1:48:31 PM
 *  Author: compucity
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "INTERRUPT_config.h"

void INT_VECT(void);


void INTERRUPT_GLOBAL_EN();

void INT0_init();

void INTERRUPT0_EN();

void INTERRUPT_TIMER0_EN();




#endif /* INTERRUPT_H_ */