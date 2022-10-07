/**
 * @name        FPEC_Interface.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _FPEC_INTERFACE_H
#define _FPEC_INTERFACE_H

/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/

/**
 * @brief: Genera notes
 * @note1: FPEC working with HSI only.
 * @note2: To write at any address it must be erased first.
 * @note3:
 *
 */

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

void FPEC_voidInit(void);
void FPEC_voidFlashMassErase(void);
void FPEC_voidFlashPageErase(const u8 Copy_u8PageNumber);
void FPEC_voidFlashWrite(const u32 Copy_u32Address,
                         u16 * const Address_u16Data,
                         const u8 Copy_u8DataLength);

#endif /* _FPEC_INTERFACE_H */
