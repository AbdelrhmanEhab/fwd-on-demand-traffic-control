#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(PortNumber,PinNumber)			((PortNumber)|=(1<<(PinNumber)))
#define CLR_BIT(PortNumber,PinNumber)			((PortNumber) &= (~(1<<(PinNumber))))
#define TOGGLE_BIT(PortNumber,PinNumber)		((PortNumber) ^= (1<<(PinNumber)))
#define GET_BIT(PortNumber,PinNumber)			(((PortNumber)>>(PinNumber))&1)

#endif