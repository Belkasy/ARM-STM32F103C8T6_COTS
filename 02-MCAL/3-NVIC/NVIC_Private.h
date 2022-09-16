/**
 * @name        NVIC_Private.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        23 Aug 2022
*/

/** @def Header Guard */
#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H

/*
----------------------------------------------------------------------------------------------------
!-											REGISTER FILE                                    
----------------------------------------------------------------------------------------------------
*/

/** @def DIO physical memory boundaries */
#define NVIC_BASE_ADDRESS     ( (0xE000E100ul)  )
#define SCB_AIRCR_LOCK_KEY	  ( (0x05FAU) 	    )
#define NUM_OF_REGISTERS 	  (	(2U)		    )

/** @note Interrupt Set Enable Register */
#define NVIC_ISER	( ((u32 volatile * const) (NVIC_BASE_ADDRESS + 0x000)) )
/** @note Interrupt Clear Enable Register */
#define NVIC_ICER	( ((u32 volatile * const) (NVIC_BASE_ADDRESS + 0x080)) )
/** @note Interrupt Set Pending Register */
#define NVIC_ISPR	( ((u32 volatile * const) (NVIC_BASE_ADDRESS + 0x100)) )
/** @note Interrupt Clear Pending Register */
#define NVIC_ICPR	( ((u32 volatile * const) (NVIC_BASE_ADDRESS + 0x180)) )
/** @note Interrupt Active Register */
#define NVIC_IABR	( ((u32 volatile * const) (NVIC_BASE_ADDRESS + 0x200)) )
/** @note Interrupt Priority Register */
#define NVIC_IPR	( ((u8  volatile * const) (NVIC_BASE_ADDRESS + 0x300)) )

/** @todo to be chaned to other file */
#define SCB_AIRCR 	( *((u32 volatile * const) (NVIC_BASE_ADDRESS + 0x200)) )

/*
----------------------------------------------------------------------------------------------------
!-                                     MACROS
----------------------------------------------------------------------------------------------------
*/


/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/

#endif /* _NVIC_PRIVATE_H */
