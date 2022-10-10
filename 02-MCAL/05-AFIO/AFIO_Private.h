/**
 * @name        AFIO_Private.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _AFIO_PRIVATE_H
#define _AFIO_PRIVATE_H


/*
----------------------------------------------------------------------------------------------------
!-                                          REGISTER FILE
----------------------------------------------------------------------------------------------------
*/
#define MAX_REGISTER_USED_BITS   (18)

#define AFIO_BASE_ADDRESS  ( (0x40010000) )

typedef struct
{
    u32 volatile EVCR;
    u32 volatile MAPR;
    u32 volatile EXTICR[4];
    u32 volatile MAPR2;
}ST_AFIO_REGISTERS_t;

#define AFIO   ( ((ST_AFIO_REGISTERS_t volatile *) (AFIO_BASE_ADDRESS)) )

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/


#endif /* _AFIO_PRIVATE_H */
