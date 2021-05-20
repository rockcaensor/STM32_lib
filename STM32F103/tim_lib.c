#include "stm32f10x.h" 
#include "tim_lib.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
void tim4Init(void)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
		TIM4->SMCR &= ~TIM_SMCR_SMS;
		TIM4->PSC = 7200;
		TIM4->ARR = 9999;
		TIM4->DIER |= TIM_DIER_UIE;
	 	TIM4->CR1 = TIM_CR1_CEN;
		NVIC_EnableIRQ (TIM4_IRQn);
	}
	
