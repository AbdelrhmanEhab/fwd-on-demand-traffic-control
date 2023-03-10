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



void TIMER0_init(){
	TCCR0 = 0x00; //normal mode
}
void TIMER0_delay(uint16_t millisec){
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