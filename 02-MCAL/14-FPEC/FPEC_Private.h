/**
 * @name        FPEC_Private.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _FPEC_PRIVATE_H
#define _FPEC_PRIVATE_H


/*
----------------------------------------------------------------------------------------------------
!-                                          REGISTER FILE
----------------------------------------------------------------------------------------------------
*/

typedef struct
{
    u32 volatile ACR;
    u32 volatile KEYR;
    u32 volatile OPTKEYR;
    u32 volatile SR;
    u32 volatile CR;
    u32 volatile AR;
    u32 volatile OBR;
    u32 volatile WRPR;
}ST_FPECRegisters_t;

#define FPEC   ( (ST_FPECRegisters_t volatile * const) (0x40022000) )

/*
----------------------------------------------------------------------------------------------------
!-                                           Defines
----------------------------------------------------------------------------------------------------
*/

/** @defgroup: Keys used */
#define FPEC_ACCESS_KEY1    (0x45670123U)
#define FPEC_ACCESS_KEY2    (0xCDEF89ABU)
#define FPEC_ACCESS_RDPRT   (0x00A5U)


enum ACR_BITS
{
    LATENCY0,
    LATENCY1,
    LATENCY2,
    HLFCYA,
    PRFTBE,
    PRFTBS
};

enum SR_BITS
{
    BSY      = 0,
    PGERR    = 1,
    WRPRTERR = 2,
    EOP      = 3
};

enum CR_BITS
{
    PG      = 0,
    PER     = 1,
    MER     = 2,
    OPTPG   = 4,
    OPTER   = 5,
    STRT    = 6,
    LOCK    = 7,
    OPTWRE  = 9,
    ERRIE   = 10,
    EOPIE   = 12
};

enum OBR_BITS
{
    OPTERR     = 0,
    RDPRT      = 1,
    WDG_SW     = 2,
    nRST_STOP  = 3,
    nRST_STDBY = 4
};

/*
----------------------------------------------------------------------------------------------------
!-                                        FUNCTIONS PROTOTYPE
----------------------------------------------------------------------------------------------------
*/



#endif /* _FPEC_PRIVATE_H */
