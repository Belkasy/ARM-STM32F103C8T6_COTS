/**
 * @name        EXTI_Private.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H


/*
----------------------------------------------------------------------------------------------------
!-                                          REGISTER FILE
----------------------------------------------------------------------------------------------------
*/

#define EXTI_BASE_ADDRESS  ( (0x40010400) )

typedef struct
{
    u32 volatile IMR;
    u32 volatile EMR;
    u32 volatile RTSR;
    u32 volatile FTSR;
    u32 volatile SWIER;
    u32 volatile PR;
}ST_EXTI_REGISTERS_t;

#define EXTI    ( ((ST_EXTI_REGISTERS_t volatile *) (EXTI_BASE_ADDRESS)) )

/*
----------------------------------------------------------------------------------------------------
!-                                          Defines
----------------------------------------------------------------------------------------------------
*/

#define MAX_REGISTER_USED_BITS   (18)
#define NUM_OF_EXTI              (16)

typedef void (*EXTI_CallBackFunctionFormat) (void);

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/



#endif /* _NVIC_PRIVATE_H */
