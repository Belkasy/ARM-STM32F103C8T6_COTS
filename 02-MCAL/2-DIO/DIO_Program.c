/**
 * @name        RCC_Program.c

 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        8/11/2022
 * @copyright   Belkasy, Wx
*/

#include "../../01-LIB//STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

/** @defgroup  *RCC Related Headers */
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                                     DIGITAL INPUT OUTPUT PROGRAM
----------------------------------------------------------------------------------------------------
*/

void DIO_voidSystemIntialization(void)
{
    /** @todo add system initalization */
}/** @end DIO_voidIntialize */

void DIO_voidSetPinStatus(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinStatus)
{

    switch(Copy_u8PortID)
    {
        case PORTA_ID:
                    if( (Copy_u8PinID < 8) )
                    {
                        GPIOA->CRL &= ~(0xF << (Copy_u8PinID * 4)); /* Clear the nibble  */
                        GPIOA->CRL |= (Copy_u8PinStatus << (Copy_u8PinID * 4)); /* 4: because the shifted nibble */
                    }
                    else if( (Copy_u8PinID < 16) )
                    {
                        Copy_u8PinID -= 8; /* Map to low bit level */

                        GPIOA->CRH &= ~(0xF << (Copy_u8PinID * 4)); /* Clear the nibble  */
                        GPIOA->CRH |= (Copy_u8PinStatus << (Copy_u8PinID * 4)); /* 4: because the shifted nibble */
                    }else;
            break;
        case PORTB_ID:
                    if( (Copy_u8PinID < 8) )
                    {
                        GPIOB->CRL &= ~(0xF << (Copy_u8PinID * 4)); /* Clear the nibble  */
                        GPIOB->CRL |= (Copy_u8PinStatus << (Copy_u8PinID * 4)); /* 4: because the shifted nibble */
                    }
                    else if( (Copy_u8PinID < 16) )
                    {
                        Copy_u8PinID -= 8; /* Map to low bit level */

                       GPIOB->CRH &= ~(0xF << (Copy_u8PinID * 4)); /* Clear the nibble  */
                       GPIOB->CRH |= (Copy_u8PinStatus << (Copy_u8PinID * 4)); /* 4: because the shifted nibble */
                    }else;
            break;
        case PORTC_ID:
                    if( (Copy_u8PinID < 8) )
                    {
                        GPIOC->CRL &= ~(0xF << (Copy_u8PinID * 4)); /* Clear the nibble  */
                        GPIOC->CRL |= (Copy_u8PinStatus << (Copy_u8PinID * 4)); /* 4: because the shifted nibble */
                    }
                    else if( (Copy_u8PinID < 16) )
                    {
                        Copy_u8PinID -= 8; /* Map to low bit level */

                        GPIOC->CRH &= ~(0xF << (Copy_u8PinID * 4)); /* Clear the nibble  */
                        GPIOC->CRH |= (Copy_u8PinStatus << (Copy_u8PinID * 4)); /* 4: because the shifted nibble */
                    }else;
            break;
        default:    break; /* Error handler */
    }

}/** @end DIO_SetPinStatus */

void DIO_voidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortValue)
{
    switch(Copy_u8PortID)
    {
        case PORTA_ID : REG_WRT(GPIOA->ODR, Copy_u8PortValue);   break;
        case PORTB_ID : REG_WRT(GPIOB->ODR, Copy_u8PortValue);   break;
        case PORTC_ID : REG_WRT(GPIOC->ODR, Copy_u8PortValue);   break;
        default :   break; /* Error handler */
    }
}/** @end DIO_voidSetPinValue */

void DIO_voidSetPin(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
    switch(Copy_u8PortID)
    {
        case PORTA_ID : GPIOA->BSRR = (BIT_ACTIVATE << Copy_u8PinID);   break;
        case PORTB_ID : GPIOB->BSRR = (BIT_ACTIVATE << Copy_u8PinID);   break;
        case PORTC_ID : GPIOC->BSRR = (BIT_ACTIVATE << Copy_u8PinID);   break;
        default :   break; /* Error handler */
    }
}/** @end DIO_voidPinSet */

void DIO_voidClrPin(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
    switch(Copy_u8PortID)
    {
        case PORTA_ID : GPIOA->BRR = (BIT_ACTIVATE << Copy_u8PinID);   break;
        case PORTB_ID : GPIOB->BRR = (BIT_ACTIVATE << Copy_u8PinID);   break;
        case PORTC_ID : GPIOC->BRR = (BIT_ACTIVATE << Copy_u8PinID);   break;
        default :   break; /* Error handler */
    }
}/** @end DIO_voidPinSet */

void DIO_voidTogPin(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
    switch(Copy_u8PortID)
    {
        case PORTA_ID : BIT_TOG(GPIOA->ODR, Copy_u8PinID);   break;
        case PORTB_ID : BIT_TOG(GPIOA->ODR, Copy_u8PinID);   break;
        case PORTC_ID : BIT_TOG(GPIOA->ODR, Copy_u8PinID);   break;
        default :   break; /* Error handler */
    }
}/** @end DIO_voidTogPin */

void DIO_voidGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 *Address_u8PinValue)
{
    u8 L_u8PinValue = 0;

    switch(Copy_u8PortID)
    {
        case PORTA_ID : L_u8PinValue = BIT_GET(GPIOA->IDR, Copy_u8PinID);   break;
        case PORTB_ID : L_u8PinValue = BIT_GET(GPIOB->IDR, Copy_u8PinID);   break;
        case PORTC_ID : L_u8PinValue = BIT_GET(GPIOC->IDR, Copy_u8PinID);   break;
        default :   break; /* Error handler */
    }
    /* Assign the value */
    *Address_u8PinValue = L_u8PinValue;
}/** @end DIO_voidGetPinValue */

void DIO_voidLockPin(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
    switch(Copy_u8PortID)
    {
        case PORTA_ID: BIT_SET (GPIOA->LCKR, Copy_u8PinID);     break;
        case PORTB_ID: BIT_SET (GPIOB->LCKR, Copy_u8PinID);     break;
        case PORTC_ID: BIT_SET (GPIOC->LCKR, Copy_u8PinID);     break;
        default :                       /*Error Code */     break;
    } /* Switch to Ports To Lock the mode*/;
}/** @end DIO_voidGetPinValue */

/*
----------------------------------------------------------------------------------------------------
!-  PRIVATE FUNCTIONS IMPLEMENTATION
----------------------------------------------------------------------------------------------------
*/
