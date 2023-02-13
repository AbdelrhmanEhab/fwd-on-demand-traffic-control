/*
 * BUTTON.h
 *
 * Created: 1/6/2023 3:13:51 PM
 *  Author: compucity
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO_DRIVER/DIO.h"
#include "BUTTON_config.h"
#include "../../Utilites/typedefs.h"
// #include "G:\udacity atmel work\project1\MCAL\INTERRUPTS_DRIVER\INTERRUPT.h"
// #include "G:\udacity atmel work\project1\MCAL\TIMER0_DRIVER\TIMER0.h"

void BUTTON_init(uint8_t BUTTONPort, uint8_t BUTTONPin);

void BUTTON_read(uint8_t BUTTONPort, uint8_t BUTTONPin, uint8_t* value);


#endif /* BUTTON_H_ */