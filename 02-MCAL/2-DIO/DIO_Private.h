/**
 * @name        DIO_Private.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/

/** @def Header Guard */
#ifndef _DIO_PRIVATE_H
#define _DIO_PRIVATE_H

/*
----------------------------------------------------------------------------------------------------
!-											REGISTER FILE                                    
----------------------------------------------------------------------------------------------------
*/

/** @def DIO physical memory boundaries */
#define GPIO_PORTA_BASE_ADDRESS    ( (0x40010800ul) )
#define GPIO_PORTB_BASE_ADDRESS    ( (0x40010C00ul) )
#define GPIO_PORTC_BASE_ADDRESS    ( (0x40011000ul) )
#define DIO_REGISTERS_NUM	       ( (cu8) (0x0A)   )
#define DIO_PORTS_NUM              ( (cu8) (0x03)   )

/** @def Bus speed limitations */
typedef struct
{
	u32 volatile CRL;
	u32 volatile CRH;
	u32 volatile IDR;
	u32 volatile ODR;
	u32 volatile BSRR;
	u32 volatile BRR;
	u32 volatile LCKR;
}ST_GPIO_REGISTERS_t;

#define GPIOA	( ((ST_GPIO_REGISTERS_t volatile * const) (GPIO_PORTA_BASE_ADDRESS)) )
#define GPIOB	( ((ST_GPIO_REGISTERS_t volatile * const) (GPIO_PORTB_BASE_ADDRESS)) )
#define GPIOC	( ((ST_GPIO_REGISTERS_t volatile * const) (GPIO_PORTC_BASE_ADDRESS)) )

enum STM32F103C8T6_PIN_CHANNEL
{
    DIO_DIGITAL,
    DIO_ANALOG
};

enum STM32F103C8T6_PIN_FUNCTION
{   
    GPIO,
    SPI,
    I2C,
    CAN,
    USART
};


/*
----------------------------------------------------------------------------------------------------
!-                                    CONFIG FILE PARAMETERS
----------------------------------------------------------------------------------------------------
*/

/** @def generic struct for the ports */
typedef struct
{
    u8 Channel;     /** @note: */
    u8 PinConfig;   /** @note: Digital/Analog */
    u8 PinMode;     /** @note: Input/Output */
    u8 Function;    /** @note: */
}ST_ConfigParameters_t;

/*
----------------------------------------------------------------------------------------------------
!-                                   PRIVATE FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

#endif /* _DIO_PRIVATE_H */
