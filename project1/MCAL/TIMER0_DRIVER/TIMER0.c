/*
 * TIMER0.c
 *
 * Created: 1/7/2023 1:48:43 PM
 *  Author: Abdelrhman Ehab
 */ 

#include "../../MCAL/INTERRUPTS_DRIVER/INTERRUPT.h"
#include "TIMER0.h"
#include "../../Utilites/typedefs.h"
#include "../../Utilites/Bit_Menpulation.h"
#include <math.h>

#define NUMBER_OF_OVERFLOWS 20
#define start_value 11

void static(*ovfCallback)(uint8_t port,uint8_t pin);
void setOvfCallback(void(*Callback)(uint8_t port,uint8_t pin)){
	ovfCallback=Callback;
}
extern uint8_t carledState;
extern uint8_t pedledState;
extern uint8_t normalMode;
extern uint8_t overflowsCounter=0;
uint8_t clicked;

void TIMER0_init()
{
	
	#if(TIMER0_MODE == TIMER0_NORMAL)
	CLR_BIT(TCCR0 , 6);
	CLR_BIT(TCCR0 , 3);
	
	#elif(TIMER0_MODE == TIMER0_CTC)
	CLR_BIT(TCCR0 , 6);
	SET_BIT(TCCR0 , 3);
	
	#elif(TIMER0_MODE == TIMER0_FAST_PWM )
	SET_BIT(TCCR0 , 6);
	SET_BIT(TCCR0 , 3);
	
	#elif(TIMER0_MODE == TIMER0_PHASE_PWM )
	SET_BIT(TCCR0 , 6);
	CLR_BIT(TCCR0 , 3);
	
	#endif
	
	#if(TIMER0_PRESCALER == TIMER0_DIV_BY_1)
	SET_BIT(TCCR0 , 0);
	CLR_BIT(TCCR0 , 1);
	CLR_BIT(TCCR0 , 2);
	
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_8)
	CLR_BIT(TCCR0 , 0);
	SET_BIT(TCCR0 , 1);
	CLR_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_64 )
	SET_BIT(TCCR0 , 0);
	SET_BIT(TCCR0 , 1);
	CLR_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_256 )
	CLR_BIT(TCCR0 , 0);
	CLR_BIT(TCCR0 , 1);
	SET_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_1024 )
	SET_BIT(TCCR0 , 0);
	CLR_BIT(TCCR0 , 1);
	SET_BIT(TCCR0 , 2);
	
	#endif
	
	#if(TIMER0_COM_EVENT == TIMER0_NO_ACTION)
	CLR_BIT(TCCR0 , 4);
	CLR_BIT(TCCR0 , 5);
	
	
	#elif(TIMER0_COM_EVENT == TIMER0_TOGGLE)
	SET_BIT(TCCR0 , 4)
	CLR_BIT(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER0_CLEAR )
	CLR_BIT(TCCR0 , 4);
	SET_BIT(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER0_SET )
	SET_BIT(TCCR0 , 4);
	SET_BIT(TCCR0 , 5);

	
	#endif
	/*Disable Interrupts*/
	CLR_BIT(TIMSK , 0);
	CLR_BIT(TIMSK , 1);
	/*CLEAR FLAGS*/
	SET_BIT(TIFR , 0);
	SET_BIT(TIFR , 1);
	/*Clear register*/
	TCNT0 = 0 ;
	OCR0 = 0 ;
}
void TIMER0_start()
{
	//setting prescaler to 1024
	TCCR0|=(1<<0)|(1<<2);
	//every time overflow happens ISR executed which increases the number of overflowcounter by 1
	//counting 20 overflows
	while(overflowsCounter<NUMBER_OF_OVERFLOWS);
}
void TIMER0_stop()
{
	//when setting no prescaler timer stops
	TCCR0=0x00;
	//now timer stopped so we need to set overflowscounter to 0 to start over again
	overflowsCounter=0;
}
void TIMER0_delay(uint16_t millisec)
{
	uint16_t Noverflows,TimerInitial;
	double Tmaxdelay,Ttick;
	uint32_t overFlowcnt=0;
	//max delay 256 micro second
	//at 1MHz no prescaler
	// 256 prescaler
	Ttick = 256.0/1000.0; //ms    Ttick = Presc/FCPU
	Tmaxdelay= 65.536; //ms		Tmaxdelay = Ttick * 2^8
	if(millisec<Tmaxdelay){
		TimerInitial = (Tmaxdelay-millisec)/Ttick;
		Noverflows = 1;
		
		}else if(millisec == (int)Tmaxdelay){
		TimerInitial=0;
		Noverflows=1;
		}else{
		Noverflows = ceil((double)millisec/Tmaxdelay);
		TimerInitial = (1<<8) - ((double)millisec/Ttick)/Noverflows;
		
	}
	TCNT0 = TimerInitial;
	TCCR0 |= (1<<2); //set 256 prescaler
	while(overFlowcnt<Noverflows){
		//busy wait
		while(GET_BIT(TIFR,0)==0);
		//clear overflow flag
		SET_BIT(TIFR,0);
		//increment counter
		overFlowcnt++;
	}
	//Timer stop
	TCCR0 = 0x00;
}
//setting the initial value
void TIMER0_set_value(uint8_t value)
{
	TCNT0=value;
}
void TIMER0_reset()
{
	//this function resets the 5 second timer to begin from very first time
	TIMER0_set_value(start_value);
	overflowsCounter=0;
}
