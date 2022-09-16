/*
 *@Name RCC_Config.h
 *@version v1.0
 *@authors: Abdelrahman Belkasy, Wx
 *Date: 8/11/2022
 *@copyright Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H


/**
 *	Some useful calculations
 *	- FOR MAX SLOW CLOCK
 *		SYS_CLK: HSI (8Mhz)	--
 *			- AHB_PS:  512
 *			- ABP1_PS: 16
 *			- ABP2_PS: 16
 *			SYS_CLK = (8Mhz/512/16) = 976Hz
 **/
/*
----------------------------------------------------------------------------------------------------
!-                                      AVAILABLE OPTIONS
----------------------------------------------------------------------------------------------------
*/

/* 
----------------------------------------------------------------------------------------------------
1.  Clock Type Configuration:
        SYSTEM_CLOCK_LSE  (X)                   |   SYSTEM_CLOCK_PLL
        SYSTEM_CLOCK_HSI                        |       - PLL_INPUT_HSI_DIV_2                                             
        SYSTEM_CLOCK_HSE                        |       - PLL_INPUT_HSE_DIRECT   
            - SYSTEM_CLOCK_HSE_RC               |       - PLL_INPUT_HSE_DIV_2
            - SYSTEM_CLOCK_HSE_CRYSTAL          |
----------------------------------------------------------------------------------------------------
*/

/** @def CHOOSE SYSTEM CLOCK */
#define RCC_CLOCK_TYPE      SYSTEM_CLOCK_PLL


#if (RCC_CLOCK_TYPE == SYSTEM_CLOCK_PLL)

    #define PLL_INPUT_TYPE      PLL_INPUT_HSE_DIV_2

#elif (RCC_CLOCK_TYPE == SYSTEM_CLOCK_HSE)

    #define HSE_INPUT_TYPE      SYSTEM_CLOCK_HSE_CRYSTAL

#endif

/* 
----------------------------------------------------------------------------------------------------
2. PLL Multiplication Factor:
        PLL_MUL_2       PLL_MUL_5       PLL_MUL_8       PLL_MUL_11      PLL_MUL_14
        PLL_MUL_3       PLL_MUL_6       PLL_MUL_9       PLL_MUL_12      PLL_MUL_15
        PLL_MUL_4       PLL_MUL_7       PLL_MUL_10      PLL_MUL_13      PLL_MUL_16
----------------------------------------------------------------------------------------------------
*/

#if (RCC_CLOCK_TYPE == SYSTEM_CLOCK_PLL)

    #define PLL_MULTIPLIER      PLL_MUL_2

#endif /* PLL_MUL */

/* 
----------------------------------------------------------------------------------------------------
3. Available Prescalers                     
    - AHB  Precsalers:  (x2)     |  - APB1 Prescalers:  (x2)  | - APB2 Prescalers:  (x2)
        - AHB_PRESCALER_1        |       - APB1_PRESCALER_1   |       - APB2_PRESCALER_1
        - AHB_PRESCALER_2        |       - APB1_PRESCALER_2   |       - APB2_PRESCALER_2 
        - AHB_PRESCALER_4        |       - APB1_PRESCALER_4   |       - APB2_PRESCALER_4 
        - AHB_PRESCALER_8        |       - APB1_PRESCALER_8   |       - APB2_PRESCALER_8 
        - AHB_PRESCALER_16       |       - APB1_PRESCALER_16  |       - APB2_PRESCALER_16
        - AHB_PRESCALER_64       |                            |
        - AHB_PRESCALER_128      |                            |               
        - AHB_PRESCALER_512      |                            |        
----------------------------------------------------------------------------------------------------
*/

/** @note Global Buses Prescaler */
#define AHB_PRESCALER   AHB_PRESCALER_1
#define APB1_PRESCALER  APB1_PRESCALER_1
#define APB2_PRESCALER  APB2_PRESCALER_1

#endif /* _RCC_CONFIG_H */
