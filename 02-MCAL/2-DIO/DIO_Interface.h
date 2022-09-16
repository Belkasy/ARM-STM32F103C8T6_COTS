/**
 * @name        DIO_Interface.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

/*
    Naming:
        RetType XXXX_RetTypeXXXX(DataType PTR/VALUE_DataTypeXXXX);
*/
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

enum PIN_STATUS
{
    DIO_INPUT_ANALOG              = 0b0000,     /** @note: */
    DIO_INPUT_FLOATING            = 0b0100,     /** @note: */
    DIO_INPUT_PULLUPDOWN          = 0b1000,     /** @note: */
    DIO_OUTPUT_PUSHPULL_2MHZ      = 0b0010,     /** @note: */
    DIO_OUTPUT_OPENDRAIN_2MHZ     = 0b0110,     /** @note: */
    DIO_OUTPUT_PUSHPULL_10MHZ     = 0b0001,     /** @note: */
    DIO_OUTPUT_OPENDRAIN_10MHZ    = 0b0101,     /** @note: */
    DIO_OUTPUT_PUSHPULL_50MHZ     = 0b0011,     /** @note: */
    DIO_OUTPUT_OPENDRAIN_50MHZ    = 0b0111,     /** @note: */
    DIO_AFIO_OPENDRAIN_2MHZ       = 0b1110,     /** @note: */
    DIO_AFIO_PUSHPULL_2MHZ        = 0b1010,     /** @note: */
    DIO_AFIO_OPENDRAIN_10MHZ      = 0b1101,     /** @note: */
    DIO_AFIO_PUSHPULL_10MHZ       = 0b1001,     /** @note: */
    DIO_AFIO_OPENDRAIN_50MHZ      = 0b1111,     /** @note: */
    DIO_AFIO_PUSHPULL_50MHZ       = 0b1011      /** @note: */
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

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

void DIO_voidSystemIntialization(void);
void DIO_voidSetPinStatus(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinStatus);
void DIO_voidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortValue);
void DIO_voidSetPin(u8 Copy_u8PortID, u8 Copy_u8PinID);
void DIO_voidClrPin(u8 Copy_u8PortID, u8 Copy_u8PinID);
void DIO_voidTogPin(u8 Copy_u8PortID, u8 Copy_u8PinID);
void DIO_voidGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 *Address_u8PinValue);
void DIO_voidLockPin(u8 Copy_u8PortID, u8 Copy_u8PinID);

#endif /* _DIO_INTERFACE_H */
