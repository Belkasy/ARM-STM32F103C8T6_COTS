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

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

void DIO_voidSystemIntialization(void);
void DIO_voidSetPinDirection(u32 Copy_u32PortID, u32 Copy_u32PinID, u8 Copy_u8Direction);
void DIO_voidSetPinValue(u32 Copy_u32PortID, u32 Copy_u32PinID, u8 Copy_u8Value);
void DIO_voidGetPinValue(u32 Copy_u32PortID, u32 Copy_u32PinID, u8 *Address_u8PinValue);

#endif /* _DIO_INTERFACE_H */
