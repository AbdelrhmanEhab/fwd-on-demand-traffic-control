/*
 * DIO.c
 *
 * Created: 1/6/2023 2:05:37 PM
 *  Author:  Abdelrhman Ehab
 */ 
#include "DIO_config.h"
#include "../../Utilites/typedefs.h"
#include "../../Utilites/Bit_Menpulation.h"

void DIO_int(uint8_t PortNumber, uint8_t PinNumber, uint8_t direction)
{
	switch(PortNumber)
	{
		case PORT_A:
		if(direction == INPUT)
		{
			DDRA &= ~(1<<PinNumber);	//set as input
		}
		else if(direction == OUTPUT)
		{
			DDRA |= (1<<PinNumber);		//set as output
		}
		else
		{
			//error_handling
		}
		
		break;
		
		case PORT_B:
		if(direction == INPUT)
		{
			DDRB &= ~(1<<PinNumber);	//set as input
		}
		else if(direction == OUTPUT)
		{
			DDRB |= (1<<PinNumber);		//set as output
		}
		else
		{
			//error_handling
		}
		
		break;
		
		case PORT_C:
		if(direction == INPUT)
		{
			DDRC &= ~(1<<PinNumber);	//set as input
		}
		else if(direction == OUTPUT)
		{
			DDRC |= (1<<PinNumber);		//set as output
		}
		else
		{
			//error_handling
		}
		
		break;
		
		case PORT_D:
		if(direction == INPUT)
		{
			DDRD &= ~(1<<PinNumber);	//set as input
		}
		else if(direction == OUTPUT)
		{
			DDRD |= (1<<PinNumber);		//set as output
		}
		else
		{
			//error_handling
		}
		
		break;
		
		default:
		//error_handling
		break;
	}
}
void DIO_write(uint8_t PortNumber, uint8_t PinNumber, uint8_t value)
{
	switch(PortNumber)
	{
	case PORT_A:
	if(value == LOW)
	{
		PORTA &= ~(1<<PinNumber);	//Write 0 
	}
	else if(value == HIGH)
	{
		PORTA |= (1<<PinNumber);		//write 1
	}
	else
	{
		//error_handling
	}
	
	break;
	
	case PORT_B:
	if(value == LOW)
	{
		PORTB &= ~(1<<PinNumber);	//Write 0
	}
	else if(value == HIGH)
	{
		PORTB |= (1<<PinNumber);		//write 1
	}
	else
	{
		//error_handling
	}
	
	break;
	case PORT_C:
	if(value == LOW)
	{
		PORTC &= ~(1<<PinNumber);	//Write 0
	}
	else if(value == HIGH)
	{
		PORTC |= (1<<PinNumber);		//write 1
	}
	else
	{
		//error_handling
	}
	
	break;
	case PORT_D:
	if(value == LOW)
	{
		PORTD &= ~(1<<PinNumber);	//Write 0
	}
	else if(value == HIGH)
	{
		PORTD |= (1<<PinNumber);		//write 1
	}
	else
	{
		//error_handling
	}
	
	break;
	
	default:
	//error_handling
	break;
	
	}
}
void DIO_toggle(uint8_t PortNumber, uint8_t PinNumber)
{
	TOGGLE_BIT(PortNumber,PinNumber);
}
void DIO_read(uint8_t PortNumber, uint8_t PinNumber, uint8_t* value)
{
	switch(PortNumber)
	{
		case PORT_A:
		//*value=((PORTA &(1<<PinNumber))>>PinNumber);
		*value=GET_BIT(PINA,PinNumber);
		break;
		case PORT_B:
		//*value=((PORTB &(1<<PinNumber))>>PinNumber);
		*value=GET_BIT(PINB,PinNumber);
		break;
		case PORT_C:
		//*value=((PORTC &(1<<PinNumber))>>PinNumber);
		*value=GET_BIT(PINC,PinNumber);
		break;
		case PORT_D:
		//*value=((PORTD &(1<<PinNumber))>>PinNumber);
		*value=GET_BIT(PIND,PinNumber);
		break;
		default:
		//error_handling
		break;
	}
}

