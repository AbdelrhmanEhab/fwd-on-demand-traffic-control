/*
 * LED.h
 *
 * Created: 1/6/2023 2:54:39 PM
 *  Author: Abdelrhman Ehab
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_DRIVER/DIO.h"

void LED_init(uint8_t LEDPort, uint8_t LEDPin);

void LED_on(uint8_t LEDPort, uint8_t LEDPin);

void LED_off(uint8_t LEDPort, uint8_t LEDPin);

void LED_toggle(uint8_t LEDPort, uint8_t LEDPin);

void LED_blink(uint8_t LEDPort, uint8_t LEDPin, uint8_t delay);

#endif /* LED_H_ */