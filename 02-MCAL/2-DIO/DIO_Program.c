/**
 * @name        RCC_Program.c
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        8/11/2022
 * @copyright   Belkasy, Wx
*/

#include " ../../01-LIB/BIT_MATH.h"
#include " ../../01-LIB/STD_TYPES.h"

/** @defgroup  *RCC Related Headers */
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "DIo_Interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                                     DIGITAL INPUT OUTPUT PROGRAM
----------------------------------------------------------------------------------------------------
*/

void DIO_voidSystemIntialization(void)
{
    /** @todo add system initalization */
}/** @end DIO_voidIntialize */

void DIO_voidSetPinDirection(u32 Copy_u32PortID, u32 Copy_u32PinID, u8 Copy_u8Direction)
{
    switch(Copy_u32PortID)
    {
        case PORTA_ID : 
            break;
        case PORTB_ID :
            break;
        case PORTC_ID :
            break;
        default :
            break;
    }

}/** @end DIO_voidSetPinDirection */

void DIO_voidSetPinValue(u32 Copy_u32PortID, u32 Copy_u32PinID, u8 Copy_u8Value)
{
    switch(Copy_u32PortID)
    {
        case PORTA_ID : 
            break;
        case PORTB_ID :
            break;
        case PORTC_ID :
            break;
        default :
            break;
    }
}/** @end DIO_voidSetPinValue */

void DIO_voidGetPinValue(u32 Copy_u32PortID, u32 Copy_u32PinID, u8 *Address_u8PinValue)
{
    switch(Copy_u32PortID)
    {
        case PORTA_ID : 
            break;
        case PORTB_ID :
            break;
        case PORTC_ID :
            break;
        default :
            break;
    }
}/** @end DIO_voidGetPinValue */