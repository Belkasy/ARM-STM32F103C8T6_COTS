/**
 * @name        SYSTICK_Program.c
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        23 Aug 2022
*/

#include "../../01-LIB//STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

/** @defgroup  USART Related Headers */
#include "SYSTICK_Config.h"
#include "SYSTICK_Private.h"
#include "SYSTICK_Interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                                  Global Variables
----------------------------------------------------------------------------------------------------
*/

SYSTICK_CallBackFunctionFormat SYSTICK_CallBackFunction = NULL;

u8 G_u8IntervalMode = 0;

enum Interval_Modes
{
	Interval_Single,
	Interval_Periodic
};

/*
----------------------------------------------------------------------------------------------------
!-                                  BROWNOUT Function  PROGRAM
----------------------------------------------------------------------------------------------------
*/

/** @defgroup Systick Main Functions */
void SYSTICK_voidInit(void)
{
    SYSTICK_voidSetClockSource(SYSTICK_CLOCK);
    SYSTICK_voidDisableInterrupt();
    SYSTICK_voidDisableCounter();
}/** @end SYSTICK_voidInit */

void SYSTICK_voidBusyWait(u32 Copy_u32DelayTime)
{
    /** @def: Load the wanted time into the systick load register */
    Copy_u32DelayTime &= MASK_VALUE_24BIT;  /** @note: Get only the first 24 bits */
    REG_WRT(SYSTICK->LOAD, Copy_u32DelayTime);

	SYSTICK_voidEnableCounter();
    /** @def: Wait for the counter to finish */
    while( !(BIT_GET(SYSTICK->CTRL, COUNTFLAG)) ) {;}
    /** @def: Stop the timer */
    SYSTICK_voidDisableCounter();
    REG_WRT(SYSTICK->LOAD, (u32) 0);
    REG_WRT(SYSTICK->VAL, (u32) 0);
}/** @end SYSTICK_voidSetBusyWait */

void SYSTICK_voidIntervalSingle(u32 Copy_u32DelayTime)
{
	/** @def: Overwrite the previous operation */
	SYSTICK_voidStopTimer();

	G_u8IntervalMode = Interval_Single;
    /** @def: Load the wanted time into the systick load register */
    Copy_u32DelayTime &= MASK_VALUE_24BIT;  /** @note: Get only the first 24 bits */
    REG_WRT(SYSTICK->LOAD, Copy_u32DelayTime);

    SYSTICK_voidEnableInterrupt();
	SYSTICK_voidEnableCounter();
}/** @end SYSTICK_voidIntervalSingle */

void SYSTICK_voidIntervalPeriodic(u32 Copy_u32DelayTime)
{
	G_u8IntervalMode = Interval_Periodic;
    /** @def: Load the wanted time into the systick load register */
    Copy_u32DelayTime &= MASK_VALUE_24BIT;  /** @note: Get only the first 24 bits */
    REG_WRT(SYSTICK->LOAD, Copy_u32DelayTime);

	SYSTICK_voidEnableInterrupt();
	SYSTICK_voidEnableCounter();
}/** @end SYSTICK_voidIntervalPeriodic */

void SYSTICK_voidStopTimer(void)
{
    /** @def: Disable systick counter */
    SYSTICK_voidDisableCounter();
    /** @def: Set load regiter value by 0*/
    REG_WRT(SYSTICK->LOAD, (u32) 0);
    REG_WRT(SYSTICK->VAL, (u32) 0);
    /** @def: Disable systick interrupts */
    SYSTICK_voidDisableInterrupt();
}/** @end SYSTICK_voidStopTimer */

u32 SYSTICK_u32GetElapsedTime(void)
{
    u32 L_u32ElapsedTime = (REG_GET(SYSTICK->LOAD) - REG_GET(SYSTICK->VAL));

    return L_u32ElapsedTime;
}/** @end SYSTICK_u32GetElapsedTime */

u32 SYSTICK_u32GetRemainingTime(void)
{
    u32 L_u32RemainingTime = (REG_GET(SYSTICK->VAL));

    return L_u32RemainingTime;
}/** @end SYSTICK_u32GetRemainingTime */

void SYSTICK_voidSetCallBack(SYSTICK_CallBackFunctionFormat Copy_CallBackFunction)
{
    if((Copy_CallBackFunction != NULL))
    {
        SYSTICK_CallBackFunction = Copy_CallBackFunction;
    }else {;}
}/** @end SYSTICK_SetCallBack */


/** @defgroup Systick Sub Functions */
void SYSTICK_voidEnableCounter(void)
{
    BIT_SET(SYSTICK->CTRL, EN);
}/** @end SYSTICK_voidEnable */
void SYSTICK_voidDisableCounter(void)
{
    BIT_CLR(SYSTICK->CTRL, EN);
}/** @end SYSTICK_voidDisable */

void SYSTICK_voidEnableInterrupt(void)
{
    BIT_SET(SYSTICK->CTRL, TICKINT);
}/** @end SYSTICK_voidEnableInterrupt */
void SYSTICK_voidDisableInterrupt(void)
{
    BIT_CLR(SYSTICK->CTRL, TICKINT);
}/** @end SYSTICK_voidDisableInterrupt */
void SYSTICK_voidSetClockSource(u8 Copy_u8ClockSource)
{
    switch(Copy_u8ClockSource)
    {
      case SYSTICK_AHB_DIRECT: BIT_SET(SYSTICK->CTRL, CLKSOURCE);   break;
      case SYSTICK_AHB_DIV_8:  BIT_CLR(SYSTICK->CTRL, CLKSOURCE);   break;
      default: break; /* Error handler */
    }
}/** @end SYSTICK_voidSetClockSource */

/*
----------------------------------------------------------------------------------------------------
!-                                  SYSTICK Function  PRIVATE
----------------------------------------------------------------------------------------------------
*/

void SysTick_Handler(void)
{
	u8 L_u8ReadClearFlag = 0;

	if( (G_u8IntervalMode == Interval_Single) )
	{
		SYSTICK_voidStopTimer();
	}else {;}

    if((SYSTICK_CallBackFunction != NULL))
    {
        SYSTICK_CallBackFunction();
    }else {;}

    L_u8ReadClearFlag = BIT_GET(SYSTICK->CTRL, COUNTFLAG);
}/** @end SYSTICK_IRQHandler */
