#ifndef __USART_H
#define __USART_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stdio.h"

#define USART1_INTERRUPT

void USART_Configuration(void);
uint16_t USART1_ReceiveData(void);


#endif /* __USART_H */
