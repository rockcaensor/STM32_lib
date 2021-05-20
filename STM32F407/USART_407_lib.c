#include "USART_lib.h"
#include "stm32f4xx.h"    

void UARTInit(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	//GPIO init 
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= 1<<7 // alt func GPIO 3
								 |1<<5; // alt func GPIO 2
	GPIOA->OSPEEDR |= 0x11<<6 // very high speed GPIO 3
								 | 0x11<<4;  // very high speed GPIO 2
	GPIOA->PUPDR |= 1<<6 | 1<<4; //pull-up 2 & 3
	GPIOA->AFR[0] |= 7<<12 | 7 <<8;
	//USART init
	USART2->CR1 = USART_CR1_UE;
	USART2->BRR = 3750;
	USART2->CR1 |=  USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE ;
	USART2->CR2=0;
	USART2->CR3=0;	
}	