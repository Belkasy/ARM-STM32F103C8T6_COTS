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

#include "../02-MCAL/01-RCC/RCC_Interface.h"
#include "../02-MCAL/02-DIO/DIO_Interface.h"
#include "../02-MCAL/03-NVIC/NVIC_Interface.h"
#include "../02-MCAL/04-EXTI/EXTI_Interface.h"
#include "../02-MCAL/05-AFIO/AFIO_Interface.h"
#include "../02-MCAL/06-SYSTICK/SYSTICK_Interface.h"
#include "../02-MCAL/USART/USART_Interface.h"
#include "../02-MCAL/SPI/SPI_Interface.h"
#include "../02-MCAL/12-WATCHDOG/WATCHDOG_Interface.h"

#define SEC 	(1000000U)
#define HALF 	(500000U)

u8 BufferRx[32] = "Works! ";

int main(void)
{
	RCC_voidSystemClockInit(SYSTEM_CLOCK);	/* 1Mhz */
	RCC_voidEnableClock(APB2_ID, IOPAEN);
	RCC_voidEnableClock(APB2_ID, AFIOEN);
	RCC_voidEnableClock(APB2_ID, USART1EN);
	SYSTICK_voidInit();

	DIO_voidSetPinStatus(PORTA_ID, PIN_9, DIO_AFIO_OPENDRAIN_50MHZ);
	DIO_voidSetPinStatus(PORTA_ID, PIN_9, DIO_INPUT_FLOATING);
	
	ST_USARTConfig_t myConfig = 
	{
		.UsartID = USART1_ID,
		.Baudrate = 9600,
		.DataBits = DATA_WORD_8,
		.Parity = Parity_NONE,
		.FlowCtrlMode = FlowCtrl_Disable,
		.StopBits = STOP_BITS_1,
		.UsartMode = USART_Enable
	};
	
	USART_voidInit(&myConfig);
	
	USART1_voidTransmitDataSync(BufferRx, 10);
	
	while(True)
	{
		
	}

	return 0;
}
