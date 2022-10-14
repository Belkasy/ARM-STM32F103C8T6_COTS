/**
 * @authors     Abdelrahman Belkasy, Wx
 * @date: Oct  4 2022
 * @dersion: V0.0
 * @copyrights: Copyrights (c) Mohamed Wx, Abdelrahman Elbelkasy 2022
 */
/** @defgroup: Header Guards */ 
#ifndef __BTL_BTL_CONFIG_H__
#define __BTL_BTL_CONFIG_H__


/*									 
-------------------------------------------------------------- 
!-				 Available Options 
-------------------------------------------------------------- 
*/ 
/**
 * @brief: Bootloader communication channel for flashing.
 * @defgroup: Configuration Parameters.
 *  @arg: BTL_COMM_USART
 *  @arg: BTL_COMM_SPI
 *  @arg: BTL_COMM_I2C
 *  @arg: BTL_COMM_CAN
 */
#define BTL_COMM_CH         (BTL_COMM_USART)

/** @brief: Size of the bootloader in pages */
#define BTL_SIZE    (4u)

#endif /* __BTL_BTL_CONFIG_H__ */
