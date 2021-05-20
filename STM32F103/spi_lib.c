#include "stm32f10x.h" 
#include "stm32f10x_gpio.h"
#include "misc.h"
#include "spi_lib.h"

void spiMasterInit_103(void)
{
	//spi init GPIO
	RCC->APB2ENR |= 1<<12;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIOA-> CRL &= 0x00000000;
  GPIOA-> CRL |= 0xB4B10000;
//spi init SPI1
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
  SPI1->CR1 =  0<<11  //DFF 8-bit
    | 0<<7     //MSB first
    | 0<<9          //??????????? ?????????? SS
    | 1<<8          //SS ? ??????? ?????????
    | 0x02<<3        //BR
    | 1<<2         //????? Master (???????)
    | 0<<1 | 0<<0; //????? ?????? SPI: 0

  SPI1->CR2 = 1 << 0 | 1	<< 2 | 1<<6;
	NVIC_EnableIRQ(SPI1_IRQn);
  SPI1->CR1 |= 1<< 6;

}

void spiSlaveInit_103(void)
{
	//spi init GPIO
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIOA-> CRL &= 0x00000000;
  GPIOA-> CRL |= 0x4B440000;
//spi init SPI1
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
  SPI1->CR1 = 0<<11  //DFF  8-bit	 
    | 0<<9          //software SS disabled
    | 0<<8          //not used
	  | 0<<7     //MSB first
    | 0<<3        // F_CLK/8
    | 0<<2         //1-Master 0-Slave
	| 0<<1 | 0<<0; //CPOL: 0-when idle 
	
	SPI1->CR2 = 0	<< 2; //SS/ not used when slave
//	SPI1->CR2 |= 0xc3;
	SPI1->CR2 |= SPI_CR2_RXNEIE;	//set interrupt by rx not empty
	SPI1->CR2 |= SPI_CR2_TXEIE;
	//SPI1->CR2 = 1 << 1 | 1 << 0;

	
	SPI1->CR1 |= SPI_CR1_SPE; // SPI enabled

	

}
