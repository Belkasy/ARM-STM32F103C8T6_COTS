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

enum GPIOA_REGISTER_ID
{
    GPIOA_CRL_ID,
    GPIOA_CRH_ID,
    GPIOA_IDR_ID,
    GPIOA_ODR_ID,
    GPIOA_BSRR_ID,
    GPIOA_BRR_ID,
    GPIOA_LCKR_ID
};

enum GPIOB_REGISTER_ID
{
    GPIOB_CRL_ID,
    GPIOB_CRH_ID,
    GPIOB_IDR_ID,
    GPIOB_ODR_ID,
    GPIOB_BSRR_ID,
    GPIOB_BRR_ID,
    GPIOB_LCKR_ID
};

enum GPIOC_REGISTER_ID
{
    GPIOC_CRL_ID,
    GPIOC_CRH_ID,
    GPIOC_IDR_ID,
    GPIOC_ODR_ID,
    GPIOC_BSRR_ID,
    GPIOC_BRR_ID,
    GPIOC_LCKR_ID
};

enum PORT_REGISTER_PINS
{
    PIN_0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
    PIN_8,
    PIN_9,
    PIN_10,
    PIN_11,
    PIN_12,
    PIN_13,
    PIN_14,
    PIN_15,
    PIN_16,
    PIN_17,
    PIN_18,
    PIN_19,
    PIN_20,
    PIN_21,
    PIN_22,
    PIN_23,
    PIN_24,
    PIN_25,
    PIN_26,
    PIN_27,
    PIN_28,
    PIN_29,
    PIN_30,
    PIN_31
};

u32 volatile * const GPIOX_CRL[DIO_PORTS_NUM] = 
{
    (u32 *) (0x40010800),      /** @note GPIOA_CRL_REGISTER */
    (u32 *) (0x40010C00),      /** @note GPIOB_CRL_REGISTER */
    (u32 *) (0x40011000)       /** @note GPIOC_CRL_REGISTER */
};

u32 volatile * const GPIOX_CRH[DIO_PORTS_NUM] = 
{
    (u32 *) (0x40010804),      /** @note GPIOA_CRH_REGISTER */
    (u32 *) (0x40010C04),      /** @note GPIOB_CRH_REGISTER */
    (u32 *) (0x40011004)       /** @note GPIOC_CRH_REGISTER */
};

u32 volatile * const GPIOX_IDR[DIO_PORTS_NUM] = 
{
    (u32 *) (0x40010808),      /** @note GPIOA_IDR_REGISTER */
    (u32 *) (0x40010C08),      /** @note GPIOB_IDR_REGISTER */
    (u32 *) (0x40011008)       /** @note GPIOC_IDR_REGISTER */
};

u32 volatile * const GPIOX_ODR[DIO_PORTS_NUM] = 
{
    (u32 *) (0x4001080C),      /** @note GPIOA_ODR_REGISTER */
    (u32 *) (0x40010C0C),      /** @note GPIOB_ODR_REGISTER */
    (u32 *) (0x4001100C)       /** @note GPIOC_ODR_REGISTER */
};

u32 volatile * const GPIOX_BSRR[DIO_PORTS_NUM] = 
{
    (u32 *) (0x40010810),      /** @note GPIOA_BSRR_REGISTER */
    (u32 *) (0x40010C10),      /** @note GPIOB_BSRR_REGISTER */
    (u32 *) (0x40011010)       /** @note GPIOC_BSRR_REGISTER */
};

u32 volatile * const GPIOX_BRR[DIO_PORTS_NUM] = 
{
    (u32 *) (0x40010814),      /** @note GPIOA_BRR_REGISTER */
    (u32 *) (0x40010C14),      /** @note GPIOB_BRR_REGISTER */
    (u32 *) (0x40011014)       /** @note GPIOC_BRR_REGISTER */
};

u32 volatile * const GPIOX_LCKR[DIO_PORTS_NUM] = 
{
    (u32 *) (0x40010818),      /** @note GPIOA_LCKR_REGISTER */
    (u32 *) (0x40010C18),      /** @note GPIOB_LCKR_REGISTER */
    (u32 *) (0x40011018)       /** @note GPIOC_LCKR_REGISTER */
};


enum STM32F103C8T6_PORT_ID
{
    PORTA_ID,
    PORTB_ID,
    PORTC_ID
};

enum STM32F103C8T6_PIN_STATE
{
    DIO_LOW,
    DIO_HIGH
};

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

enum STM32F103C8T6_PIN_MODE
{
    DIO_INPUT              = 0b00,
    DIO_OUTPUT_2MHZ        = 0b10,
    DIO_OUTPUT_10MHZ       = 0b01,
    DIO_OUTPUT_50MHZ       = 0b11
};

enum STM32F103C8T6_PIN_INPUT_CONFIG
{   
    DIO_INPUT_ANALOG        = 0b00,     /** @note: */
    DIO_INPUT_FLOATING      = 0b01,     /** @note: */
    DIO_INPUT_PULLUPDOWN    = 0b10      /** @note: */
};

enum STM32F103C8T6_PIN_OUTPUT_CONFIG
{   
    DIO_OUTPUT_PUSHPULL     = 0b00,    /** @note: */
    DIO_OUTPUT_OPENDRAIN    = 0b01     /** @note: */
};

enum STM32F103C8T6_PIN_AFIO_CONFIG
{   
    DIO_AFIO_OPENDRAIN      = 0b11,     /** @note: */
    DIO_AFIO_PUSHPULL       = 0b10      /** @note: */
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

static void DIO_SetPinStatus(u8 Copy_u8RegisterID, u8 Copy_u8PinID, u8 Copy_u8PinConfig, u8 Copy_u8PinMode);
static void DIO_voidDecoder(u8 Copy_u8RegisterID, u8 Copy_u8PinID, u8 Copy_u8PinConfig, u8 Copy_u8PinMode);

#endif /* _DIO_PRIVATE_H */