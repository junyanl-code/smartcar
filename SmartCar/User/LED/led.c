#include "led.h"

void LED_Configuration(void)
{
	    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
  		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  		GPIO_Init(GPIOC, &GPIO_InitStructure);
	  	GPIO_SetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
}

void LED_Set(u8 value)
{
	GPIO_Write(GPIOC,value);
}

void LED_SetBit(u8 num,BitAction value)
{
	GPIO_WriteBit(GPIOC,1<<num,value);
}

void LED_Interrupt(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	
    TIM_TimeBaseStructure.TIM_Period=10000;//ARR��ֵ
	TIM_TimeBaseStructure.TIM_Prescaler=3600-1;
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM3, ENABLE); //����ʱ��

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);   // ��ռʽ���ȼ��� 
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;//ָ���ж�Դ
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 10;// ָ����Ӧ���ȼ���1
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}
