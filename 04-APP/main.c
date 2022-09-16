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
#include "../02-MCAL/USART/USART_Interface.h"
#include "../02-MCAL/6-SYSTICK/SYSTICK_Interface.h"

#define SEC 	(1000000U)
#define HALF 	(500000U)

u8 BufferRx[32] = "Works! ";

int main(void)
{
	RCC_voidSystemClockInit(SYSTEM_CLOCK);	/* 1Mhz */
	RCC_voidEnableClock(APB2_ID, IOPBEN);
	RCC_voidEnableClock(APB2_ID, AFIOEN);
	RCC_voidEnableClock(APB1_ID, USART3EN);
	SYSTICK_voidInit();

	DIO_voidSetPinStatus(PORTB_ID, PIN_10, DIO_AFIO_PUSHPULL_50MHZ);

	ST_USARTConfig_t myCfgTx = {USART3_ID, 9600, STOP_BITS_1, DATA_WORD_8, Parity_NONE, FlowCtrl_Disable, USART_Transmitter};
	USART_voidInit(&myCfgTx);
	
 	NVIC_voidEnableInterrupt(NVIC_USART3);

	while(True)
	{
		USART3_voidTransmitDataAsync(BufferRx);
		SYSTICK_voidBusyWait(SEC);
	}

	return 0;
}

