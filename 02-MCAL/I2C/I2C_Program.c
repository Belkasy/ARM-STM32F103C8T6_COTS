/**
 * @name        I2C_Program.c
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        23 Aug 2022
*/

#include "../../01-LIB//STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

/** @defgroup  USART1 Related Headers */
#include "I2C_Config.h"
#include "I2C_Private.h"
#include "I2C_Interface.h"

/*
----------------------------------------------------------------------------------------------------
!-                                  Global Variables
----------------------------------------------------------------------------------------------------
*/

I2C_CallBackFunctionFormat I2C_CallBackFunction[NUM_OF_I2C] = {NULL};


/*
----------------------------------------------------------------------------------------------------
!-                                  I2C Function  PROGRAM
----------------------------------------------------------------------------------------------------
*/

void I2C_voidInit(const ST_I2CConfig_t *I2CConfig)
{
//   /** @defgroup: Config the peripheral */
//   voidSetBusSpeed(I2CConfig->I2C_ID, I2CConfig->BUS_SPEED);
//   voidSetMode(I2CConfig->I2C_ID, I2CConfig->I2C_MODE);
//   voidSetAddressMode(I2CConfig->I2C_ID, I2CConfig->ADDR_MODE);
//   voidSetSpeedMode(I2CConfig->I2C_ID, I2CConfig->SPEED_MODE);
//   voidSetACK(I2CConfig->I2C_ID, I2CConfig->ACK);
//   voidSetPEC(I2CConfig->I2C_ID, I2CConfig->PEC);
//   voidSetARP(I2CConfig->I2C_ID, I2CConfig->ARP);
//   voidSetSTRETCH(I2CConfig->I2C_ID, I2CConfig->STRETCH);
//   /** @def: Enable the peripheral after the config */
//   voidSetState(I2CConfig->I2C_ID, I2C_ENABLE);
}/** @end I2C_voidInit */

/*
----------------------------------------------------------------------------------------------------
!-                                  I2C Function  PRIVATE
----------------------------------------------------------------------------------------------------
*/

