/*
 * BUTTON.c
 *
 * Created: 1/6/2023 3:13:33 PM
 *  Author: Abdelrhman Ehab
 */ 


#include "BUTTON.h"
#include "../../MCAL/INTERRUPTS_DRIVER/INTERRUPT.h"

uint8_t carledState;
uint8_t overflowsCounter;
extern uint8_t clicked;

void BUTTON_init(uint8_t BUTTONPort, uint8_t BUTTONPin)
{
	DIO_int(BUTTONPort, BUTTONPin, INPUT);
}

void BUTTON_read(uint8_t BUTTONPort, uint8_t BUTTONPin, uint8_t* value)
{
	DIO_read(BUTTONPort, BUTTONPin, value);
}





