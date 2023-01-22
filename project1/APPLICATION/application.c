/*
 * application.c
 *
 * Created: 1/6/2023 3:06:38 PM
 *  Author: Abdelrhman Ehab
 */ 

#include "application.h"

uint8_t switcher=0; 
uint8_t button_flag=0; 


void APP_init()
{
	//initializing leds as outputs
	LED_init(car_Traffic,LED_green_C);
	LED_init(car_Traffic,LED_red_C);
	LED_init(car_Traffic,LED_yellow_C);
	
	LED_init(pedestrains_Traffic,LED_green_P);
	LED_init(pedestrains_Traffic,LED_red_P);
	LED_init(pedestrains_Traffic,LED_yellow_P);
	
	//initializing button as input
	BUTTON_init(BUTTON_PORT_P,BUTTON_PIN_P);
	
	//selecting timer mode
	TIMER0_init();
	
	//enable global interrupts
	INTERRUPT_GLOBAL_EN();
	
	//enable timer 0 interrupts
	INTERRUPT_TIMER0_EN();
	
	//selecting the interrupt sense to rising edge
	INT0_init();
	
	//start listening for the interrupt
	INTERRUPT0_EN();
	
	//set address of call back function
	setOvfCallback(LED_toggle);
	
	
}



void APP_start()
{
	int i;
	//start with green car on
	LED_on(car_Traffic,LED_green_C);
	LED_off(car_Traffic,LED_yellow_C);
	LED_off(car_Traffic,LED_red_C);
	//satart with red ped on
	LED_on(pedestrains_Traffic,LED_red_P);
	LED_off(pedestrains_Traffic,LED_yellow_P);
	LED_off(pedestrains_Traffic,LED_green_P);
	
	if (button_flag==1)
	{
		switcher=1;
		
	}
	switch(switcher)
	{
		//1-car led green and peds. led red for 5 sec
		case 0:
		
		LED_on(car_Traffic,LED_green_C);
		LED_off(car_Traffic,LED_yellow_C);
		LED_off(car_Traffic,LED_red_C);
		
		LED_on(pedestrains_Traffic,LED_red_P);
		LED_off(pedestrains_Traffic,LED_yellow_P);
		LED_off(pedestrains_Traffic,LED_green_P);
		for(i=0;i<50;i++){
			TIMER0_delay(68);
			if(button_flag)break;//check if ISR was called
		}
		
		switcher=1;
		break;
		
		case 1:
		
		LED_on(car_Traffic,LED_green_C);
		LED_off(car_Traffic,LED_yellow_C);
		LED_off(car_Traffic,LED_red_C);
		
		LED_on(pedestrains_Traffic,LED_red_P);
		LED_off(pedestrains_Traffic,LED_yellow_P);
		LED_off(pedestrains_Traffic,LED_green_P);
		//blink both yellow leds
		for(i=0;i<5;i++){
			LED_on(car_Traffic,LED_yellow_C);
			LED_on(pedestrains_Traffic,LED_yellow_P);
			TIMER0_delay(390);
			LED_off(car_Traffic,LED_yellow_C);
			LED_off(pedestrains_Traffic,LED_yellow_P);
			TIMER0_delay(190);
			LED_on(car_Traffic,LED_yellow_C);
			LED_on(pedestrains_Traffic,LED_yellow_P);
			TIMER0_delay(390);
		}
		button_flag=0;
		switcher=2;
		break;
		
		case 2:
		LED_on(car_Traffic,LED_red_C);
		LED_off(car_Traffic,LED_yellow_C);
		LED_off(car_Traffic,LED_green_C);
		
		LED_on(pedestrains_Traffic,LED_green_P);
		LED_off(pedestrains_Traffic,LED_yellow_P);
		LED_off(pedestrains_Traffic,LED_red_P);
		
		for(i=0;i<50;i++){
			TIMER0_delay(68);
			if(button_flag)break;//check if ISR was called
		}
		
		switcher=3;
		break;
		
		case 3:
		LED_on(car_Traffic,LED_red_C);
		LED_off(car_Traffic,LED_yellow_C);
		LED_off(car_Traffic,LED_green_C);
		
		LED_on(pedestrains_Traffic,LED_green_P);
		LED_off(pedestrains_Traffic,LED_yellow_P);
		LED_off(pedestrains_Traffic,LED_red_P);
		//blink both yellow leds
		for(i=0;i<5;i++){
			LED_on(car_Traffic,LED_yellow_C);
			LED_on(pedestrains_Traffic,LED_yellow_P);
			TIMER0_delay(390);
			LED_off(car_Traffic,LED_yellow_C);
			LED_off(pedestrains_Traffic,LED_yellow_P);
			TIMER0_delay(190);
			LED_on(car_Traffic,LED_yellow_C);
			LED_on(pedestrains_Traffic,LED_yellow_P);
			TIMER0_delay(390);
		}
		switcher=0;
		
		
	}
	
}


ISR(EXT_INT_0)
{
	
	
	if(button_flag==0)
	{
		switcher=1;
		
	}
	else
	{
		//do nothing
	}
}


