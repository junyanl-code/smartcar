#include "pwm.h"



/*******************************************************************************
* Function Name  : PWM_Init_TIM2
* Description    : PWM_TIM2初始化
* Input          : arr 计数器自动重装值
				   psc 预分频系数，0为不分频
* Output         : None
* Return         : None
*******************************************************************************/
void PWM_Init_TIM2(u16 arr, u16 psc)
{
    RCC->APB1ENR |= 1 << 0;//使能TIM2时钟
    RCC->APB2ENR |= 1 << 2;//使能A口时钟

    TIM2->ARR = arr;//设定计数器自动重装值(决定PWM的频率)
    TIM2->PSC = psc;//预分频器 0为不分频
	
	if(PWM_NUM>=1)
	{
		GPIOA->CRL &= 0XFFFFFFF0;//PA0清0
	    GPIOA->CRL |= 0X0000000B;//复用功能输出(推挽50MHz输出)
	    GPIOA->ODR |= 1 << 0;//PA0上拉 
		TIM2->CCMR1 |= 6 << 4;//CH1 PWM1模式 
	    TIM2->CCMR1 |= 1 << 3;//CH1预装载使能 
		TIM2->CCER  |= 1 << 0;//输入/捕获1输出使能 
	}

	if(PWM_NUM>=2)
	{
		GPIOA->CRL &= 0XFFFFFF0F;//PA1清0
	    GPIOA->CRL |= 0X000000B0;//复用功能输出(推挽50MHz输出)
	    GPIOA->ODR |= 1 << 1;//PA1上拉 
	    TIM2->CCMR1 |= 6 << 12;//CH2 PWM1模式
	    TIM2->CCMR1 |= 1 << 11;//CH2预装载使能
		TIM2->CCER  |= 1 << 4;//输入/捕获2输出使能
	}

	if(PWM_NUM>=3)
	{
		GPIOA->CRL &= 0XFFFFF0FF;//PA2清0
	    GPIOA->CRL |= 0X00000B00;//复用功能输出(推挽50MHz输出)
	    GPIOA->ODR |= 1 << 2;//PA2上拉
		TIM2->CCMR2 |= 6 << 4;//CH3 PWM1模式 
	    TIM2->CCMR2 |= 1 << 3;//CH3预装载使能 
		TIM2->CCER  |= 1 << 8;//输入/捕获3输出使能 
	}
	if(PWM_NUM>=4)
	{
		GPIOA->CRL &= 0XFFFF0FFF;//PA3清0
	    GPIOA->CRL |= 0X0000B000;//复用功能输出(推挽50MHz输出)
	    GPIOA->ODR |= 1 << 3;//PA3上拉 
	    TIM2->CCMR2 |= 6 << 12;//CH4 PWM1模式
	    TIM2->CCMR2 |= 1 << 11;//CH4预装载使能
	    TIM2->CCER  |= 1 << 12;//输入/捕获4输出使能
	}

    TIM2->CR1 = 0X0080;//ARPE使能
    TIM2->CR1 |= 0X01;//使能定时器3
}
/*******************************************************************************
* Function Name  : PWM_Init
* Description    : PWM_Init初始化
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/

 void PWM_Configuration(void)
{	   	
	int i=0;
	/*初始化所有PWM输出管脚为低，防止相互耦合*/
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	GPIO_ResetBits(GPIOA,GPIO_Pin_3);
 	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
	GPIO_ResetBits(GPIOA,GPIO_Pin_6);
	GPIO_ResetBits(GPIOA,GPIO_Pin_7);


	if(PWM_NUM>0&&PWM_NUM<5)
	{
		PWM_Init_TIM2(USER_ARR, USER_PSC);
	}
	
	for(i=0;i<4;i++)
	{
		PWM_SetArr(i,0);
	}
}

void PWM_SetArr(u8 channel,u16 value)
{
	{
		switch(channel)
		{
			case 1: TIM2->CCR1 = value;break;
			case 2:	TIM2->CCR2 = value;break;
			case 3: TIM2->CCR3 = value;break;
			case 4:	TIM2->CCR4 = value;break;
			default: break;
		}
	}
}

void Set_Speed(uint8_t channel, uint8_t speed, uint8_t direction)
{
	if(direction == 0)
	{
	  PWM_SetArr(channel,speed);
	  switch(channel)
	  {
	  	 case 1:   GPIO_ResetBits(GPIOA,DIR1); break;
		 case 2:   GPIO_ResetBits(GPIOA,DIR2); break;
		 case 3:   GPIO_ResetBits(GPIOA,DIR3); break;
		 case 4:   GPIO_ResetBits(GPIOA,DIR4); break;
		 default: break;
	  }
	}
	else
	{
	  PWM_SetArr(channel,99-speed);
	  switch(channel)
	  {
	  	 case 1:   GPIO_SetBits(GPIOA,DIR1);break;
		 case 2:   GPIO_SetBits(GPIOA,DIR2);break;
		 case 3:   GPIO_SetBits(GPIOA,DIR3);break;
		 case 4:   GPIO_SetBits(GPIOA,DIR4);break;
		 default: break;
	  }
	}
}
			 


