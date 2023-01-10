/*
 * INTERRUPT_config.h
 *
 * Created: 1/7/2023 1:50:35 PM
 *  Author:Abdelrhman Ehab
 */ 


#ifndef INTERRUPT_CONFIG_H_
#define INTERRUPT_CONFIG_H_

#include "../../Utilites/REGESTERS.h"

#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2

//defining timer 0 overflow vector
#define TIMER0_OF_VECT __vector_9

#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));


#endif /* INTERRUPT_CONFIG_H_ */