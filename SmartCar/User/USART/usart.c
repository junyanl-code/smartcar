#include "usart.h"

void USART_Configuration(void)
{
  		USART_InitTypeDef USART_InitStructure;
  		USART_ClockInitTypeDef  USART_ClockInitStructure;
	    GPIO_InitTypeDef GPIO_InitStructure;
		#ifdef USART1_INTERRUPT
			NVIC_InitTypeDef NVIC_InitStructure;
   		#endif
		 /* Enable USART1 and GPIOA clock */
		  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);
  		/* Configure USART1 Tx (PA.09) as alternate function push-pull */
  		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
 		 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  		GPIO_Init(GPIOA, &GPIO_InitStructure);
    
  		/* Configure USART1 Rx (PA.10) as input floating */
  		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  		GPIO_Init(GPIOA, &GPIO_InitStructure);

				/* Configure USART1 Interrupt*/
		#ifdef USART1_INTERRUPT
			
			NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);//选择分组方式0
			  
			  /* 使能 USART1 中断 */
			NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
			NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
			NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
			NVIC_Init(&NVIC_InitStructure);

			USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

		#endif
		/* USART1 configuration ------------------------------------------------------*/

		
  		/* USART1 configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
        - USART Clock disabled
        - USART CPOL: Clock is active low
        - USART CPHA: Data is captured on the middle 
        - USART LastBit: The clock pulse of the last data bit is not 
		output to the SCLK pin 			 */
		USART_ClockInitStructure.USART_Clock = USART_Clock_Disable;
		USART_ClockInitStructure.USART_CPOL = USART_CPOL_Low;
		USART_ClockInitStructure.USART_CPHA = USART_CPHA_2Edge;
		USART_ClockInitStructure.USART_LastBit = USART_LastBit_Disable;
		/* Configure the USART1 synchronous paramters */
		USART_ClockInit(USART1, &USART_ClockInitStructure);

		USART_InitStructure.USART_BaudRate = 9600;
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		USART_InitStructure.USART_StopBits = USART_StopBits_1;
		USART_InitStructure.USART_Parity = USART_Parity_No ;
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
		/* Configure USART1 basic and asynchronous paramters */
		USART_Init(USART1, &USART_InitStructure);
    
  		/* Enable USART1 */
  		USART_Cmd(USART1, ENABLE);
}

//void USART_Configuration(void)
//{
//  		USART_InitTypeDef USART_InitStructure;
//  		USART_ClockInitTypeDef  USART_ClockInitStructure;
//	    GPIO_InitTypeDef GPIO_InitStructure;
//		#ifdef USART1_INTERRUPT
//			NVIC_InitTypeDef NVIC_InitStructure;
//   		#endif
//		 /* Enable USART1 and GPIOA clock */
//		  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);
//		 
//	
//	  	/* Configure USART1 Tx (PA.09) as alternate function push-pull */
//	  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
//	 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	  	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	    
//	  	/* Configure USART1 Rx (PA.10) as input floating */
//	  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//	  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//	  	GPIO_Init(GPIOA, &GPIO_InitStructure);
//
//
//				/* Configure USART1 Interrupt*/
//		#ifdef USART1_INTERRUPT
//			
//			NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);//选择分组方式0
//			  
//			  /* 使能 USART1 中断 */
//			NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
//			NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//			NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//			NVIC_Init(&NVIC_InitStructure);
//
//			USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
//
//		#endif
//			/* USART1 configuration ------------------------------------------------------*/ 			
//	  		/* USART1 configured as follow:
//	        - BaudRate = 115200 baud  
//	        - Word Length = 8 Bits
//	        - One Stop Bit
//	        - No parity
//	        - Hardware flow control disabled (RTS and CTS signals)
//	        - Receive and transmit enabled
//	        - USART Clock disabled
//	        - USART CPOL: Clock is active low
//	        - USART CPHA: Data is captured on the middle 
//	        - USART LastBit: The clock pulse of the last data bit is not 
//			output to the SCLK pin 			 */
//			USART_ClockInitStructure.USART_Clock = USART_Clock_Disable;
//			USART_ClockInitStructure.USART_CPOL = USART_CPOL_Low;
//			USART_ClockInitStructure.USART_CPHA = USART_CPHA_2Edge;
//			USART_ClockInitStructure.USART_LastBit = USART_LastBit_Disable;
//			/* Configure the USART1 synchronous paramters */
//			USART_ClockInit(USART1, &USART_ClockInitStructure);
//	
//			USART_InitStructure.USART_BaudRate = 115200;
//			USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//			USART_InitStructure.USART_StopBits = USART_StopBits_1;
//			USART_InitStructure.USART_Parity = USART_Parity_No ;
//			USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//			USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
//			/* Configure USART1 basic and asynchronous paramters */
//			USART_Init(USART1, &USART_InitStructure);
//	    
//	  		/* Enable USART1 */
//	  		USART_Cmd(USART1, ENABLE);
//}


void USART1_SendData(uint16_t Data)
{
  USART_SendData(USART1,Data);
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET); 
}
uint16_t USART1_ReceiveData(void)
{
	return USART_ReceiveData(USART1);
}




/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
/*******************************************************************************
* Function Name  : fputc
* Description    : Retargets the C library printf function to the USART.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
int fputc(int ch, FILE *f)
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  USART_SendData(USART1, (u8) ch);

  /* Loop until the end of transmission */
  while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
  {
  }

  return ch;
}



