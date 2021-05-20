#include "spi_407_lib.h"
#include "stm32f4xx.h"  



void CS_SET(void)
{
GPIOA -> BSRRL |= 1<<4;
}

void CS_RESET(void)
{
GPIOA -> BSRRH |= 1<<4;
}

void spiSlaveInit(void)
{	
	RCC->AHB1ENR |= 0x1;
  GPIOA->MODER |= 0xa800;
	GPIOA->OSPEEDR |= 0xff00;
	GPIOA->PUPDR |= 0x5600;
	
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	SPI1->CR1 = 0x00000000;
	SPI1->CR1 = 0<<11  //DFF  8-bit
	  | 0<<15	//BIDIMODE 0-2 line unidirectional data mode selected
	  | 0<<14 // BIDIOE out disabled (not used)
	  | 1<<13 //CRCEN 1-CRC calculation enabled
    | 0<<7     //MSB first
    | 0<<9          //software SS disabled
    | 1<<8          //not used
    | 0x0<<3        // F_CLK/8
    | 0<<2         //1-Master 0-Slave
	| 0<<1 | 0<<0; //CPOL: 0-when idle 
	
	SPI1->CR2  = 0	<< 2; //SS/ not used when slave
	SPI1->CR1 |= 1<< 6; // SPI enabled
	SPI1->CR2 |= SPI_CR2_RXNEIE;	//set interrupt by rx not empty

}

void spiMasterInit(void)
{
	//spi init GPIO
	RCC->AHB1ENR |= 0x1;
  GPIOA->MODER |= 0x8900;
	GPIOA->OSPEEDR |= 0xff00;
	GPIOA->PUPDR |= 0x0000;
	GPIOA-> AFR[0] = 0x55550000;
//spi init SPI1
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
SPI1->CR1 |= 0<<15;
SPI1->CR1 |= 1<<8;
SPI1->CR1 |= 7<<3;
SPI1->CR1 |= 1<<2;	
	  /*| 0<<11  //DFF 8-bit    
    | 0<<9          //??????????? ?????????? SS
    | 1<<8          //SS ? ??????? ?????????
	  | 0<<7     //MSB first
    | 0x11<<3        //BR
    | 1<<2         //????? Master (???????)
    | 0<<1 | 0<<0; //????? ?????? SPI: 0
*/
SPI1->CR2 |= SPI_CR2_RXNEIE;	//set interrupt by rx not empty
SPI1->CR2 |= 1	<< 2;	
	
SPI1->CR1 |= 1<< 6;
NVIC_EnableIRQ(SPI1_IRQn);
}
