/**
 * @name        SYSTICK_Private.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _SYSTICK_PRIVATE_H
#define _SYSTICK_PRIVATE_H


/*
----------------------------------------------------------------------------------------------------
!-                                          REGISTER FILE
----------------------------------------------------------------------------------------------------
*/

#define SYSTICK_BASE_ADDRESS  ( (0xE000E010U) )

typedef struct
{
    u32 volatile CTRL;
    u32 volatile LOAD;
    u32 volatile VAL;
    u32 volatile CALIB;
}ST_SYSTICK_REGISTERS_t;

#define SYSTICK ( ((ST_SYSTICK_REGISTERS_t volatile * const) (SYSTICK_BASE_ADDRESS)) )

/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/
typedef void (*SYSTICK_CallBackFunctionFormat)(void);

#define MASK_VALUE_24BIT    (0xFFFFFFU)

enum STK_CTRL
{
	EN     		= 0,
    TICKINT     = 1,
    CLKSOURCE   = 2,
    COUNTFLAG   = 16
};

#define SYSTICK_AHB_DIV_8    (0U)
#define SYSTICK_AHB_DIRECT   (1U)

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/



#endif /* _SYSTICK_PRIVATE_H */
