#include "stm32f10x.h" 
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "misc.h"
#include "RCC_lib.h"

void RCC_Init(void){
   RCC_DeInit();
   RCC->CR |= RCC_CR_HSEON; //HSE on   
   while(RCC_CR_HSERDY == 0){}; //waiting while HSE is not ready
   
   
   FLASH->ACR |= FLASH_ACR_PRFTBE; 
   FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
   FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;
       
     RCC->CFGR |= RCC_CFGR_PLLSRC_HSE;  //PLL source HSE
     RCC->CFGR |= RCC_CFGR_PLLMULL9; // PLL MULL
     RCC->CR |= RCC_CR_PLLON;    //PLL ON
     while(RCC_CR_PLLRDY == 0){}; //waiting while PLL is not ready
   
   RCC->CFGR |= RCC_CFGR_PPRE1_DIV2; //APB1 clock divider
   RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; //APB2 clock divider
   RCC->CFGR |= RCC_CFGR_MCO_SYSCLK; //clock output from sys clock
   RCC->CFGR |= RCC_CFGR_SW_PLL; //system clock source from PLL
};
