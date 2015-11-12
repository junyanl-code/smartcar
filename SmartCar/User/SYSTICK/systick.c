#include "systick.h"

 __IO uint32_t TimingDelay;
/*初始化时钟*/
void SysTick_Configuration(void)
{
  if(SysTick_Config(SystemCoreClock / 1000)) //注意：3.5库中 SystemFrequency 被 SystemCoreClock 取代。
  while(1);
}

/*延时1ms函数*/

void delay_ms(__IO uint32_t nTime)
{
  TimingDelay = nTime;
  while(TimingDelay != 0);

}
