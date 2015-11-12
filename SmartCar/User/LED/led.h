#ifndef __LED_H
#define __LED_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

void LED_Configuration(void);
void LED_Set(u8 value);//设置8位
void LED_SetBit(u8 num,u8 value);//设置一位
void LED_Interrupt(void);

#endif /* __LED_H */
