/*
 *@Name: STD_Types.h
 *@authors: Abdelrahman Belkasy, Wx
 *Date: 8/11/2022
 *@copyright Belkasy, Wx
*/

/** @def header guard */
#ifndef __STD_TYPES_H__
#define __STD_TYPES_H__

/*
--------------------------------------------------------------------------------------------------
!-                                      Standard Types                                          -
--------------------------------------------------------------------------------------------------
*/

/** @defgroup signed */
typedef signed char         s8;
typedef signed short int    s16;
typedef signed long  int    s32;
typedef signed long         s64;
/** @defgroup const signed */
typedef const signed char         cs8;
typedef const signed short int    cs16;
typedef const signed long  int    cs32;
typedef const signed long         cs64;
/** @defgroup unsigned */
typedef unsigned char       u8;
typedef unsigned short int  u16;
typedef unsigned long  int  u32;
typedef unsigned long       u64;
/** @defgroup const unsigned */
typedef const unsigned char       cu8;
typedef const unsigned short int  cu16;
typedef const unsigned long  int  cu32;
typedef const unsigned long       cu64;
/** @defgroup decimal point */
typedef float               f32;
typedef double              f64;
typedef long double         f128;
/** @defgroup const decimal point */
typedef const float               cf32;
typedef const double              cf64;
typedef const long double         cf128;

/** @def boolean types */
typedef enum BOOLEAN_TYPES
{
    False = 0,
    True  = 1
}bool_t;

/** @def bit states */
typedef enum BIT_STATE
{
    BIT_DEACTIVATE,
    BIT_ACTIVATE
}bit_t;

/** @defgroup basic building block structs */
/**
 * @brief basic union type for the generic register.
 */
typedef union STM32_REGISTERS_TYPE
{
    /** @def register bits struct */
    struct BIT_LEVEL
    {
        /** @defgroup LOW BYTE */
        volatile u8 BIT0    : 1; /** @def LSB */
        volatile u8 BIT1    : 1;
        volatile u8 BIT2    : 1;
        volatile u8 BIT3    : 1;
        volatile u8 BIT4    : 1;
        volatile u8 BIT5    : 1;
        volatile u8 BIT6    : 1;
        volatile u8 BIT7    : 1;
        /** @defgroup MID BYTES */
        volatile u8 BIT8    : 1;
        volatile u8 BIT9    : 1;
        volatile u8 BIT10   : 1;
        volatile u8 BIT11   : 1;
        volatile u8 BIT12   : 1;
        volatile u8 BIT13   : 1;
        volatile u8 BIT14   : 1;
        volatile u8 BIT15   : 1;
        volatile u8 BIT16   : 1;
        volatile u8 BIT17   : 1;
        volatile u8 BIT18   : 1;
        volatile u8 BIT19   : 1;
        volatile u8 BIT20   : 1;
        volatile u8 BIT21   : 1;
        volatile u8 BIT22   : 1;
        volatile u8 BIT23   : 1;
        /** @defgroup HIGH BYTE */
        volatile u8 BIT24   : 1;
        volatile u8 BIT25   : 1;
        volatile u8 BIT26   : 1;
        volatile u8 BIT27   : 1;
        volatile u8 BIT28   : 1;
        volatile u8 BIT29   : 1;
        volatile u8 BIT30   : 1;
        volatile u8 BIT31   : 1; /** @def MSB */
    }BIT_st;
    /** @def register level */
    volatile u32 REG;
}REG_ut;

/** @defgroup peripheral register block structs */

#endif /* __STD_TYPES_H__ */
