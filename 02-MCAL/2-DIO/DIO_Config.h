/**
 * @name        DIO_Config.h
 * @version     v1.0
 * @authors     Abdelrahman Belkasy, Wx
 * @date        19 Aug 2022
 * @copyright   Belkasy, Wx
*/
/** @def Header Guard */
#ifndef _DIO_CONFIG_H
#define _DIO_CONFIG_H

/*
----------------------------------------------------------------------------------------------------
!-                                      AVAILABLE OPTIONS
----------------------------------------------------------------------------------------------------
*/
/**
 * @todo Add port's pins config parameters.
 * @todo Finish the config file.
 * @todo Finish the driver functions.
 * @todo Finish the "DIO_voidSystemIntialization".

 * @todo Organize the files. (What / Where to put things (Config?Interface?Private?) )

 * @todo TEST THE FCKN CODE IN ANY IDE. <<====<<====<< !- IMPORTANT
 **/

/**
 * Available options:
 * 
 * OUTPUT_PIN_2MHZ -- OUTPUT_PIN_10MHZ -- OUTPUT_PIN_50MHZ
 * 
*/
#define OUTPUT_PIN_SPEED    OUTPUT_PIN_2MHZ

ST_ConfigParameters_t GPIOA_ConfigParametersTable[] = 
{
/*   Channel - PinType - Direction    - Mode -        Function       */
    { 0x00, DIO_DIGITAL, DIO_INPUT, DIO_INPUT_FLOATING, GPIO }, /** @note GPIOA_PINA0  */
    {}, /** @note GPIOA_PINA1  */
    {}, /** @note GPIOA_PINA2  */
    {}, /** @note GPIOA_PINA3  */
    {}, /** @note GPIOA_PINA4  */
    {}, /** @note GPIOA_PINA5  */
    {}, /** @note GPIOA_PINA6  */
    {}, /** @note GPIOA_PINA7  */
    {}, /** @note GPIOA_PINA8  */ 
    {}, /** @note GPIOA_PINA9  */
    {}, /** @note GPIOA_PINA10 */
    {}, /** @note GPIOA_PINA11 */
    {}, /** @note GPIOA_PINA12 */
    {}, /** @note GPIOA_PINA13 */
    {}, /** @note GPIOA_PINA14 */
    {}  /** @note GPIOA_PINA15 */
};

ST_ConfigParameters_t GPIOB_ConfigParametersTable[] =
{
/*   Channel - PinType - Direction - Data -  Function       */
    {}, /** @note GPIOB_PINB0  */
    {}, /** @note GPIOB_PINB1  */
    {}, /** @note GPIOB_PINB2  */
    {}, /** @note GPIOB_PINB3  */
    {}, /** @note GPIOB_PINB4  */
    {}, /** @note GPIOB_PINB5  */
    {}, /** @note GPIOB_PINB6  */
    {}, /** @note GPIOB_PINB7  */
    {}, /** @note GPIOB_PINB8  */ 
    {}, /** @note GPIOB_PINB9  */
    {}, /** @note GPIOB_PINB10 */
    {}, /** @note GPIOB_PINB11 */
    {}, /** @note GPIOB_PINB12 */
    {}, /** @note GPIOB_PINB13 */
    {}, /** @note GPIOB_PINB14 */
    {}  /** @note GPIOB_PINB15 */
};

ST_ConfigParameters_t GPIOC_ConfigParametersTable[] = 
{
/*   Channel - PinType - Direction - Data -  Function       */
    {}, /** @note GPIOC_PINC0 */
    {}, /** @note GPIOC_PINC1 */
    {}  /** @note GPIOC_PINC2 */
};

#endif /* _DIO_CONFIG_H */
