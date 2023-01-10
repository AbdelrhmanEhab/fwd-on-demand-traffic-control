/*
 * application.c
 *
 * Created: 1/6/2023 3:06:38 PM
 *  Author: Abdelrhman Ehab
 */ 

#include "application.h"

uint8_t carLED=0; //0 green 1 yellow 2 red
uint8_t prevcarLED=1;
uint8_t normalmode = 1; //1 normal 0 pedestrian

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
	
	if(normalmode || carLED==0 || carLED==1){
		if(!normalmode){
			carLED=1;
		}
		
	switch(carLED)
	{
		case 0:
			LED_on(car_Traffic,LED_green_C);
			LED_off(car_Traffic,LED_yellow_C);
			LED_off(car_Traffic,LED_red_C);
		
			LED_on(pedestrains_Traffic,LED_red_P);
			LED_off(pedestrains_Traffic,LED_yellow_P);
			LED_off(pedestrains_Traffic,LED_green_P);
		
			for(i=0;i<50;i++){
				TIMER0_delay(68);
				if(!normalmode)break;//check if ISR was called
				}
			
			carLED=1;
			prevcarLED=0;
		break;
		//Case YELLOW LED
		case 1:
			//if not normalmode then we need to blink both
		
			if(!normalmode){
				if(prevcarLED!=2){
					LED_on(pedestrains_Traffic,LED_red_P);
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
				}
				prevcarLED=1;//to go to Ped lights logic
				carLED=2;
				LED_on(car_Traffic,LED_red_C);
				LED_on(pedestrains_Traffic,LED_green_P);
				}
				else
				{
				//blink car yellow led
				for(i=0;i<5;i++){
					LED_on(car_Traffic,LED_yellow_C);
					LED_on(pedestrains_Traffic,LED_yellow_P);
					TIMER0_delay(380);
					LED_off(car_Traffic,LED_yellow_C);
					LED_off(pedestrains_Traffic,LED_yellow_P);
					TIMER0_delay(180);
					LED_on(car_Traffic,LED_yellow_C);
					LED_on(pedestrains_Traffic,LED_yellow_P);
					TIMER0_delay(380);
					if(!normalmode){//check if ISR was called
						prevcarLED=1;
						break;
					}
				}
			}
			LED_off(car_Traffic,LED_yellow_C);
			LED_off(pedestrains_Traffic,LED_yellow_P);
			//Configure variables for correct switching
			if(prevcarLED==0){
				carLED=2;
				prevcarLED=1;
				}else if(prevcarLED==2){
				carLED=0;
				prevcarLED=1;
			}
		break;
		
		//Case RED LED
		case 2:
			LED_off(car_Traffic,LED_green_C);
			LED_off(car_Traffic,LED_yellow_C);
			LED_on(car_Traffic,LED_red_C);
			LED_on(pedestrains_Traffic,LED_green_P);
			LED_off(pedestrains_Traffic,LED_yellow_P);
			LED_off(pedestrains_Traffic,LED_red_P);
			for(i=0;i<50;i++){
				TIMER0_delay(68);
				if(!normalmode)break;
			}
			prevcarLED=2;
			carLED=1;
			break;
			
		default:
			carLED=2;
			prevcarLED=1;
			break;
			}
		
			}else{
			//Configure PED LEDs
			LED_on(pedestrains_Traffic,LED_green_P);
			LED_off(pedestrains_Traffic,LED_yellow_P);
			LED_off(pedestrains_Traffic,LED_red_P);
		
			//Configure CAR LEDs
			LED_off(car_Traffic,LED_green_C);
			LED_off(car_Traffic,LED_yellow_C);
			LED_on(car_Traffic,LED_red_C);
			TIMER0_delay(5000);//5 sec delay
		
			//make sure car red light is off
			LED_off(car_Traffic,LED_red_C);
		
			//blink both yellow while ped green is on
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
			//Turn off yellow LEDs
			LED_off(car_Traffic,LED_yellow_C);
			LED_off(pedestrains_Traffic,LED_yellow_P);
			//turn on PED red LED
			LED_on(pedestrains_Traffic,LED_red_P);
			//reset normalmode
			normalmode=1;
			//Configure carLED variables
			carLED=0;
			prevcarLED=1;
	}
}


ISR(EXT_INT_0)
{
	normalmode=0;
}


