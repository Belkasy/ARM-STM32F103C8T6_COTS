/**
 * @name        AFIO_Interface.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _AFIO_INTERFACE_H
#define _AFIO_INTERFACE_H

/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/

enum AFIO_EXTI_PORT_LINE
{
    AFIO_EXTI_PORTA    = 0b0000,
    AFIO_EXTI_PORTB    = 0b0001,
    AFIO_EXTI_PORTC    = 0b0010
};

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

void AFIO_voidEXTILineConfig(u8 Copy_u8LineID, u8 Copy_u8LinePortID);


#endif /* _AFIO_INTERFACE_H */
