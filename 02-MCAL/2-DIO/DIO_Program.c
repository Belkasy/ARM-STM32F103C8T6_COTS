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

void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Direction)
{
    switch(Copy_u8PortID)
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

void DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
    switch(Copy_u8PortID)
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

void DIO_voidGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 *Address_u8PinValue)
{
    switch(Copy_u8PortID)
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


/*
----------------------------------------------------------------------------------------------------
!-  PRIVATE FUNCTIONS IMPLEMENTATION
----------------------------------------------------------------------------------------------------
*/

static void DIO_SetPinStatus(u8 Copy_u8RegisterID, u8 Copy_u8PinID, u8 Copy_u8PinConfig, u8 Copy_u8PinMode)
{
    /* Write to CRL */
    if( (Copy_u8PinID < 8) )
    {
        DIO_voidDecoder(Copy_u8RegisterID, Copy_u8PinID, Copy_u8PinConfig, Copy_u8PinMode);
    }
    /* Write to CRH */
    else
    {
        /* Map the High level to low level */
        Copy_u8PinID -= 8;

        DIO_voidDecoder(Copy_u8RegisterID, Copy_u8PinID, Copy_u8PinConfig, Copy_u8PinMode);
    }
}/** @end DIO_SetPinStatus */

static void DIO_voidDecoder(Copy_u8RegisterID, Copy_u8PinID, Copy_u8PinConfig, Copy_u8PinMode)
{
    /**
     * Algorithm:
     *              7      6     5      4     3     2     1    0
     * Register: 0b[0000][0000][0000][0000][0000][0000][0000][0000]
     * Pin: PIN_2
     * Config: 0b01
     * Mode: 0b11
     * 1. Concatenate Config-Mode
     * 2. Shift right the nibble x PIN_2 
     * 3. Algorithm assign.
     */

    u8 L_ConcatenatedNibble = 0;

    L_ConcatenatedNibble |= (Copy_u8PinMode);
    L_ConcatenatedNibble |= (Copy_u8PinConfig << 2);

    Copy_u8RegisterID    |= (L_ConcatenatedNibble << Copy_u8PinID);
    
}/** @end DIO_voidDecoder */