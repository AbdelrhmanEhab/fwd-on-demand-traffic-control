/*
 * DIO.h
 *
 * Created: 1/6/2023 2:06:14 PM
 *  Author: Abdelrhman Ehab
 */ 


#ifndef DIO_H_
#define DIO_H_


#include "DIO_config.h"

void DIO_int(uint8_t PortNumber, uint8_t PinNumber, uint8_t direction);
void DIO_write(uint8_t PortNumber, uint8_t PinNumber, uint8_t value);
void DIO_toggle(uint8_t PortNumber, uint8_t PinNumber);
void DIO_read(uint8_t PortNumber, uint8_t PinNumber, uint8_t* value);


#endif /* DIO_H_ */