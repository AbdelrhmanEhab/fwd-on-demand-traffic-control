/*
 * DIO_REGESTERS.h
 *
 * Created: 1/6/2023 1:50:03 PM
 *  Author: Abdelrhman Ehab
 */ 


#ifndef REGESTERS_H_
#define REGESTERS_H_

#include"typedefs.h"

/************************************************************************/
/*						DIO Registers                                   */
/************************************************************************/

//PORTA registers
#define PORTA		*((volatile uint8_t*) 0X3B)//8-BIT REGISTER
#define DDRA		*((volatile uint8_t*) 0X3A)//8-BIT REGISTER
#define PINA		*((volatile uint8_t*) 0X39)//8-BIT REGISTER

//PORTB registers
#define PORTB		*((volatile uint8_t*) 0X38)//8-BIT REGISTER
#define DDRB		*((volatile uint8_t*) 0X37)//8-BIT REGISTER
#define PINB		*((volatile uint8_t*) 0X36)//8-BIT REGISTER

//PORTC registers
#define PORTC		*((volatile uint8_t*) 0X35)//8-BIT REGISTER
#define DDRC		*((volatile uint8_t*) 0X34)//8-BIT REGISTER
#define PINC		*((volatile uint8_t*) 0X33)//8-BIT REGISTER

//PORTD registers
#define PORTD		*((volatile uint8_t*) 0X32)//8-BIT REGISTER
#define DDRD		*((volatile uint8_t*) 0X31)//8-BIT REGISTER
#define PIND		*((volatile uint8_t*) 0X30)//8-BIT REGISTER


/************************************************************************/
/*                       TIMER 0 REGISTERS                              */
/************************************************************************/

#define  TCCR0 *((volatile uint8_t*)0x53)//8-BIT REGISTER
#define  TCNT0 *((volatile uint8_t*)0x52) //8-BIT REGISTER
#define  TIFR *((volatile uint8_t*)0x58) //8-BIT REGISTER
#define  OCR0 *((volatile uint8_t*)0x5C) //8-BIT REGISTER
/************************************************************************/
/*                      STATUS REGISTER                                 */
/************************************************************************/

#define SREG *((volatile uint8_t*)0x5F)



/************************************************************************/
/*						INTERRUPTS REGIESTERS                           */
/************************************************************************/

//REGISTER RESBONSIBLE FOR CHOOSING INTERRUPT SENSE
#define MCUCR *((volatile uint8_t*)0x55)

#define MCUCSR *((volatile uint8_t*)0x54)

//FOR ENABLING THE INTERRUPT
#define GICR *((volatile uint8_t*)0x5B)
//INTERRUPT FLAG REGISTER
#define GIFR *((volatile uint8_t*)0x5A)

/************************************************************************/
/*		REGIESTER RESBONSIBLE FOR TIMER INTERRUPTS                      */
/************************************************************************/

#define TIMSK *((volatile uint8_t*)0x59)

#endif /* REGESTERS_H_ */