/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */  

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "led.h"
#include "systick.h"
#include "usart.h"
#include "buzzer.h"
#include "pwm.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
 uint16_t instruction=0;
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f10x_xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f10x.c file
     */ 
	LED_Configuration();
	SysTick_Configuration();
	USART_Configuration();
	Buzzer_Configuration();
	LED_Interrupt();//开启定时器中断
	PWM_Configuration();

	LED_Set(0x00);
  /* Infinite loop */
  while (1)										 
  {
// 	Set_Speed(1,50,0);
//	Set_Speed(2,50,0);
//	Buzzer_ON();
//	delay_ms(1000);
//	Set_Speed(1,50,1);
//	Set_Speed(2,50,1);
//	Buzzer_ON();
//	delay_ms(1000);
	switch(instruction)
	{
		case 'a': 
			Set_Speed(1,50,1);
			Set_Speed(2,50,1);
			break;
		case 'b': 
			Set_Speed(1,50,1);
			Set_Speed(2,50,0);
			break;	
		case 'c': 
			Set_Speed(1,50,0);
			Set_Speed(2,50,1);
			break;
		case 'd': 
			Set_Speed(1,50,0);
			Set_Speed(2,50,0);
			break;
		case 's': 
			Set_Speed(1,0,0);
			Set_Speed(2,0,0);
			break;
		case 'z':
				Buzzer_ON();
				break;
		case 'y':
				Buzzer_OFF();
				break;
		 default: break;
										
	}


  }
}







#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
