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
#define FLASH_START_ADDRESS (0x08000000)

#define FLASH_MEMORY_PAGE_SIZE (64u)

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

void FPEC_voidInit(void);

u8
FPEC_u8FlashMassErase(void);

u8
FPEC_u8FlashPageErase(u8 Copy_u8PageNumber);

u8
FPEC_u8WriteFlash(u32 Copy_u32MemoryAddress,
                  u16 *Address_u16Data,
                  u16 Copy_u16DataLength);

#endif /* _FPEC_INTERFACE_H */
