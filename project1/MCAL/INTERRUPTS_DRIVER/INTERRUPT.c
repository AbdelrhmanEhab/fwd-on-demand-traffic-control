/*
 * INTERRUPT.c
 *
 * Created: 1/7/2023 1:48:19 PM
 *  Author: compucity
 */ 

#include "INTERRUPT.h"
#include "../../Utilites/Bit_Menpulation.h"
#include "../../Utilites/typedefs.h"

void INTERRUPT_GLOBAL_EN(){
	SET_BIT(SREG,7);
}

//select interrupt sense
void INT0_init(){
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
}

//enable external interrupt of INT0
void INTERRUPT0_EN(){
	SET_BIT(GICR,6);
}

//enabling interrupt of timer0 when over flow happens
void INTERRUPT_TIMER0_EN(){
	SET_BIT(TIMSK,0);
}