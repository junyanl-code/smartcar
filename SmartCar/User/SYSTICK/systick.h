#ifndef __SYSTICK_H
#define __SYSTICK_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

void SysTick_Configuration(void);
void delay_ms(__IO uint32_t nTime);

#endif /* __USART_H */
