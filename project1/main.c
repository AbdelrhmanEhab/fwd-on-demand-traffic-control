/*
 * DIO_DRIVER.c
 *
 * Created: 1/6/2023 1:45:51 PM
 * Author : Abdelrhman Ehab
 */ 

//#include <avr/io.h>
#include "APPLICATION/application.h"

int main(void)
{
   APP_init();
    while (1) 
    {
		APP_start();
    }
}

