/**
 * @name        NVIC_Interface.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        23 Aug 2022
*/
/** @def Header Guard */
#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H

/*
    Naming:
        RetType XXXX_RetTypeXXXX(DataType PTR/VALUE_DataTypeXXXX);
*/

/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/

/**
 * @brief: Imporatnt general defines
 */
/* Disable global interrupts */
#define _disable_irqs_()    STM32F103C8Tx_DisableGlobalInterrupts
/* Enable global interrupts */
#define _enable_irqs_()     STM32F103C8Tx_EnableGlobalInterrupts


enum EXTIx_ID
{   			  /* System ID */
	NVIC_WWDG_ID		= 0,
	NVIC_PVD_ID			= 1,
	NVIC_TAMPER_ID		= 2,
	NVIC_RTC_ID			= 3,
	NVIC_FLASH_ID		= 4,
	NVIC_RCC_ID			= 5,
    NVIC_EXTI0_ID		= 6,
    NVIC_EXTI1_ID		= 7,
    NVIC_EXTI2_ID		= 8,
    NVIC_EXTI3_ID		= 9,
    NVIC_EXTI4_ID		= 10,
	NVIC_DMA_Channel1	= 11,
	NVIC_DMA_Channel2	= 12,
	NVIC_DMA_Channel3	= 13,
	NVIC_USART1 		= 37,
	NVIC_USART2 		= 38,
	NVIC_USART3 		= 39
};

/** @def Groubing Inexies */
#define _4BITS_GROUP_0BITS_SUB (0x05FA0300ul)
#define _3BITS_GROUP_1BITS_SUB (0x05FA0400ul)
#define _2BITS_GROUP_2BITS_SUB (0x05FA0500ul)
#define _1BITS_GROUP_3BITS_SUB (0x05FA0600ul)
#define _0BITS_GROUP_4BITS_SUB (0x05FA0700ul)

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

void NVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);
void NVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);

void NVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
void NVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
void NVIC_voidGetActiveFlag(u8 Copy_u8IntNumber, u8 *Address_u8ActiveFlag);

void NVIC_voidSetPriorityBits(u8 Copy_u8PriorityBitsSettings);
void NVIC_voidSetPriority(u8 Copy_u8IntNumber, u8 Copy_u8GroupPriorityID, u8 Copy_u8SubPriorityID);


#endif /* _NVIC_INTERFACE_H */
 
