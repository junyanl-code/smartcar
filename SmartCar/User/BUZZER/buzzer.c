#include "buzzer.h"

void Buzzer_Configuration(void)
{
	    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB,GPIO_Pin_10);

}

void Buzzer_OFF(void)
{
   GPIO_ResetBits(GPIOB,GPIO_Pin_10);
}

void Buzzer_ON(void)
{
   GPIO_SetBits(GPIOB,GPIO_Pin_10);
}
