/*
 * application.h
 *
 * Created: 1/7/2023 2:37:42 PM
 *  Author:Abdelrhman Ehab
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "..\MCAL\INTERRUPTS_DRIVER\INTERRUPT.h"
#include "..\MCAL\TIMER0_DRIVER\TIMER0.h"
#include "..\ECUAL\BUTTON_DRIVER\BUTTON.h"
#include "..\ECUAL\LED_DRIVER\LED.h"

#include "application_config.h"

void APP_init();
void APP_start();


#endif /* APPLICATION_H_ */