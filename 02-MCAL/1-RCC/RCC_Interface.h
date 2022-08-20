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


/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

void RCC_voidSystemClockInit(void);
void RCC_voidEnableClock(cu8 Copy_cu8BusID, cu8 Copy_cu8PeripheralID);
void RCC_voidDisableClock(cu8 Copy_cu8BusID, cu8 Copy_cu8PeripheralID);


#endif /* _RCC_INTERFACE_H */
