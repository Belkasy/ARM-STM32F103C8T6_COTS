/**
 * @name        main.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/

/*
----------------------------------------------------------------------------------------------------
!-											HEADERS INCLUDED
----------------------------------------------------------------------------------------------------
*/

#include "../01-LIB/STD_TYPES.h"
#include "../01-LIB/BIT_MATH.h"

#include "../02-MCAL/1-RCC/RCC_Interface.h"
#include "../02-MCAL/2-DIO/DIO_Interface.h"
#include "../02-MCAL/3-NVIC/NVIC_Interface.h"
#include "../02-MCAL/4-EXTI/EXTI_Interface.h"
#include "../02-MCAL/5-AFIO/AFIO_Interface.h"
#include "../02-MCAL/6-SYSTICK/SYSTICK_Interface.h"
#include "../02-MCAL/7-TIMER/TIMER_Interface.h"
#include "../02-MCAL/USART/USART_Interface.h"
#include "../02-MCAL/SPI/SPI_Interface.h"

#define SEC 	(1000000U)
#define HALF 	(500000U)

int main(void)
{
	RCC_voidSystemClockInit(SYSTEM_CLOCK);	/* 8Mhz */
	RCC_voidEnableClock(APB2_ID, IOPAEN);
	RCC_voidEnableClock(APB2_ID, SPI1EN);
	RCC_voidEnableClock(APB2_ID, AFIOEN);
	SPI1_voidInit();
	SYSTICK_voidInit();
	
	DIO_voidSetPinStatus(PORTA_ID, PIN_5, DIO_AFIO_PUSHPULL_50MHZ);
	DIO_voidSetPinStatus(PORTA_ID, PIN_6, DIO_INPUT_FLOATING);
	DIO_voidSetPinStatus(PORTA_ID, PIN_7, DIO_AFIO_PUSHPULL_50MHZ);
	
	SPI1_voidTransmitDataSync(1);
	SPI1_voidTransmitDataSync(2);
	
	u8 counter = 0;
	
	while(True)
	{
		
		
	}

	return 0;
}

