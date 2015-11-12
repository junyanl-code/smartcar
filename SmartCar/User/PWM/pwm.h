#ifndef __PWM_H
#define __PWM_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
/*配置选项*/
#define PWM_NUM 4	   //配置PWM使用路数，PWM_NUM范围1-4
/*
频率	Fpwm = 72M/（（arr+1）*（psc+1））
占空比	duty circle = TIMx->CCRx/arr
设置频率为 50Hz 故取 arr=10000 psc=143
*/

/*
若想设置频率为1K的PWM，则取arr=999，psc=71 即可
*/
#define USER_ARR 99
#define USER_PSC 35

#define FORWARD 1
#define BACKWARD 0

#define DIR1 GPIO_Pin_4
#define DIR2 GPIO_Pin_5
#define DIR3 GPIO_Pin_6
#define DIR4 GPIO_Pin_7

void PWM_Init_TIM2(u16 arr, u16 psc);
void PWM_Configuration(void);
void PWM_SetArr(u8 channel,u16 value);//value: 0 -  USER_ARR	 channel： 1 - 4
void Set_Speed(uint8_t channel, uint8_t speed, uint8_t direction);


#endif /* __USART_H */
