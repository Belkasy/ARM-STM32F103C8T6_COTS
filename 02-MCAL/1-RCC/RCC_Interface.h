/*
 *@Name: RCC_Interface.h
 *@version v1.0
 *@authors: Abdelrahman Belkasy, Wx
 *Date: 8/11/2022
 *@Aright Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

/*
    Naming:
        RetType XXXX_RetTypeXXXX(DataType PTR/VALUE_DataTypeXXXX);
*/

enum SYS_BUS
{
	AHB_ID,
	APB1_ID,
	APB2_ID
};

enum RCC_AHBENR_BITS
{
    DMA1EN      = 0,         /* R/W, Enable DMA1  Clock */
    DMA2EN      = 1,         /* R/W, Enable DMA2  Clock */
    SRAMEN      = 2,         /* R/W, Enable SRAM  Clock */
    FLITFEN     = 3,         /* R/W, Enable FLITF Clock */
    CRCEN       = 6,         /* R/W, Enable CRC   Clock */
    FSMCEN      = 8,         /* R/W, Enable FSMC  Clock */
    SDIOEN      = 10         /* R/W, Enable SDIO  Clock */
};

enum RCC_APB1ENR_BITS
{
    TIM2EN      = 0,       /* R,W Enable TIMER2 Clock */
    TIM3EN      = 1,       /* R,W Enable TIMER3 Clock */
    TIM4EN      = 2,       /* R,W Enable TIMER4 Clock */
    SPI2EN      = 14,      /* R,W Enable SPI2 Clock */
    SPI3EN      = 15,      /* R,W Enable SPI3 Clock */
    USART2EN    = 17,      /* R,W Enable USART2 Clock */
    USART3EN    = 18,      /* R,W Enable USART3 Clock */
    I2C1EN      = 21,      /* R,W Enable I2C1 Clock */
    I2C2EN      = 22,      /* R,W Enable I2C2 Clock */
    USBEN       = 23,      /* R,W Enable USB Clock */
    CANE1N      = 25,      /* R,W Enable CAN Clock */
    PWREN       = 28,      /* R,W Enable Power Clock */
    DACEN       = 29
};

enum RCC_APB2ENR_BITS
{
    AFIOEN      = 0,       /* R,W Enable AFIO Clock */
    IOPAEN      = 2,       /* R,W Enable IO PORTA Clock */
    IOPBEN      = 3,       /* R,W Enable IO PORTB Clock */
    IOPCEN      = 4,       /* R,W Enable IO PORTC Clock */
    IOPDEN      = 5,       /* R,W Enable IO PORTD Clock */
    ADC1EN      = 9,       /* R,W Enable ADC1 Clock */
    ADC2EN      = 10,      /* R,W Enable ADC2 Clock */
    TIM1EN      = 11,      /* R,W Enable TIMER1 Clock */
    SPI1EN      = 12,      /* R,W Enable SPI1   Clock */
    USART1EN    = 14,      /* R,W Enable USART1 Clock */
    ADC3EN      = 15,      /* R,W Enable ADC3   Clock */
};

enum MCO_CLOCK
{
	NO_CLOCK,
	SYSTEM_CLOCK,
	HSI_CLOCK,
	HSE_CLOCK,
	PLL_DIV_2_CLOCK
};

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

void RCC_voidSystemClockInit(u8 Copy_u8SystemClockID);
void RCC_voidEnableClock(cu8 Copy_cu8BusID, cu8 Copy_cu8PeripheralID);
void RCC_voidDisableClock(cu8 Copy_cu8BusID, cu8 Copy_cu8PeripheralID);

void RCC_voidSetMCO(u8 Copy_u8ClockType);

#endif /* _RCC_INTERFACE_H */
