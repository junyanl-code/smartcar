#include "systick.h"

 __IO uint32_t TimingDelay;
/*��ʼ��ʱ��*/
void SysTick_Configuration(void)
{
  if(SysTick_Config(SystemCoreClock / 1000)) //ע�⣺3.5���� SystemFrequency �� SystemCoreClock ȡ����
  while(1);
}

/*��ʱ1ms����*/

void delay_ms(__IO uint32_t nTime)
{
  TimingDelay = nTime;
  while(TimingDelay != 0);

}
