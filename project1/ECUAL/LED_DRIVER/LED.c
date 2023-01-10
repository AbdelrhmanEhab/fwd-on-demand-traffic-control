/*
 * LED.c
 *
 * Created: 1/6/2023 2:54:47 PM
 *  Author:  Abdelrhman Ehab
 */ 

#include "LED.h"
#include "../../Utilites/Bit_Menpulation.h"

void LED_init(uint8_t LEDPort, uint8_t LEDPin)
{
	DIO_int(LEDPort,LEDPin,OUTPUT);
}
void LED_on(uint8_t LEDPort, uint8_t LEDPin)
{
	DIO_write(LEDPort,LEDPin,HIGH);
}
void LED_off(uint8_t LEDPort, uint8_t LEDPin)
{
	DIO_write(LEDPort,LEDPin,LOW);
}
void LED_toggle(uint8_t LEDPort, uint8_t LEDPin)
{
	DIO_toggle(LEDPort,LEDPin);
}
void LED_blink(uint8_t LEDPort, uint8_t LEDPin, uint8_t delay)
{
	DIO_write(LEDPort,LEDPin,HIGH);
	DIO_write(LEDPort,LEDPin,LOW);
}