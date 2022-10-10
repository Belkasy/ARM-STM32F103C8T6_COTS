/**
 * @author: Mohamed Ashraf
 * @date: Oct  5 2022
 * @dersion: V0.0
 * @copyrights: Copyrights (c) Mohamed Wx 2022
 */
/** @defgroup: Header Guards */ 
#ifndef __ADC_ADC_INTERFACE_H__
#define __ADC_ADC_INTERFACE_H__


/*									 
-------------------------------------------------------------- 
!-				 Public Defines 
-------------------------------------------------------------- 
*/ 
void ADC_voidInit(void);

void ADC_voidGetValue(u8 Channel);
void AWD_voidInit(void); /** Analoge WatchDog*/
/*									 
-------------------------------------------------------------- 
!-				 Public Functions Declaration 
-------------------------------------------------------------- 
*/ 


#endif /* __ADC_ADC_INTERFACE_H__ */
