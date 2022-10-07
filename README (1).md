# ARM-Microcontrollers-Driver
___
MCU: STM32F103C8T6

Driver Type: Personal Developed
___
## Drivers
Set of microcontroller drivers internally / externally for easy to use for normal user.

Architecture: Static Layered - Basic.

![BSL_ARCHITECTURE](https://j.top4top.io/p_24398ww7i1.png)


Folder structure:
```
project
└───STM32F103C8T6-Driver
│   └───APP
│       │   main.c
│   └───HAL
│   └───MCAL
│       └───RCC
|           | RCC_Private.h
|           | RCC_Config.h
|           | RCC_Interface.h
|           | RCC_Program.c
│       └───DIO
|           | DIO_Private.h
|           | DIO_Config.h
|           | DIO_Interface.h
|           | DIO_Program.c
│       └───NVIC
|           | NVIC_Private.h
|           | NVIC_Config.h
|           | NVIC_Interface.h
|           | NVIC_Program.c
│       └───EXTI
|           | EXTI_Private.h
|           | EXTI_Config.h
|           | EXTI_Interface.h
|           | EXTI_Program.c
│       └───AFIO
|           | AFIO_Private.h
|           | AFIO_Config.h
|           | AFIO_Interface.h
|           | AFIO_Program.c
│       └───SYSTICK
|           | SYSTICK_Private.h
|           | SYSTICK_Config.h
|           | SYSTICK_Interface.h
|           | SYSTICK_Program.c
│       └───USART
|           | USART_Private.h
|           | USART_Config.h
|           | USART_Interface.h
|           | USART_Program.c
|   └───LIB
|       | bit_math.h
|       | std_types.h
|       | std_libs.h
```
___               
|Driver|Type|State|
|----------|--------|------|
|RCC|Internal|Done|
|DIO|Internal|Done|
|NVIC|Internal|Done|
|EXTI|Internal|Done|
|AFIO|Internal|Half|
|SYSTICK|Internal|Done|
|USART|Internal|Half|
