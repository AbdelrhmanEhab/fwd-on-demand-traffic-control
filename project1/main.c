/*
 * DIO_DRIVER.c
 *
 * Created: 1/6/2023 1:45:51 PM
 * Author : Abdelrhman Ehab
 */ 

//#include <avr/io.h>
// #include "ECUAL/BUTTON_DRIVER/BUTTON.h"
// #include "ECUAL/LED_DRIVER/LED.h"
// #include "MCAL/TIMER0_DRIVER/TIMER0.h"
// #include "MCAL/INTERRUPTS_DRIVER/INTERRUPT.h"
#include "APPLICATION/application.h"

uint8_t i=0,vel=0;

int main(void)
{
   APP_init();
   
    while (1) 
    {
	APP_start();
	
	
}

}
	
// ISR(EXT_INT_0){
// 	
// i++;
// }