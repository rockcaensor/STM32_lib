#include "sys_tick.h"
#include "main.h"
//uint32_t sysTickCount = 0;
	
//	
//void SysTickConfig(void)
//	{
//		SysTick->LOAD = 249;
//		SysTick->VAL = 249;
//		
//		SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | 
//										SysTick_CTRL_TICKINT_Msk |
//										SysTick_CTRL_ENABLE_Msk;
//	}


//	
//void delayMks(uint32_t value)
//	{	
//		sysTickCount = value;		
//		while (sysTickCount != 0){}
//	}
//	
//	