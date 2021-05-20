#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_rcc.h"
#include "RCC_407_lib.h"


void RCC_init(void){
	RCC_DeInit();	
	RCC->CR |= RCC_CR_HSEON; //HSE on
	while(RCC_CR_HSERDY==0){}  //waiting while HSE is not ready
	RCC-> PLLCFGR = 0x00000000; //reset PLLCFGR register	
	RCC-> PLLCFGR = 0x24000000;
	RCC-> PLLCFGR |= 76<<6;
	RCC->PLLCFGR |= 4;
	RCC->PLLCFGR |= 0x00400000;
	RCC-> CR |= RCC_CR_PLLON; //PLL ON 
	while(RCC_CR_PLLRDY == 0){} //waiting while PLL is not ready
	
	FLASH->ACR |= FLASH_ACR_PRFTEN;
	FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
	FLASH->ACR |= (uint32_t) FLASH_ACR_LATENCY_2WS;
	
	//RCC-> CFGR |= RCC_CFGR_HPRE_1;
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV4; //APB1 pre
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2; //APB2 pre
	RCC->CFGR |= RCC_MCO1Source_PLLCLK;	
	RCC->CFGR |= RCC_MCO2Source_SYSCLK;	
	RCC->CFGR |= RCC_CFGR_SW_PLL;
}


