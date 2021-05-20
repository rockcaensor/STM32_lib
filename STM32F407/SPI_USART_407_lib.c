#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"
#include "spi_407_lib.h"
#include "USART_lib.h"
#include "SPI_USART_407_lib.h"
#include "RCC_407_lib.h"
#include "main.h"
//#include "sys_tick.h"

//static volatile uint8_t sentDataStr[12] = {0x0D, 0x0A, 0x53, 0x65, 0x6E, 0x74, 0x20, 0x44, 0x61, 0x74, 0x61, 0x20};
//void Hex_To_Str(uint16_t hex_data)
//	{
//		uint8_t high = hex_data>>4 & 0xf;
//		uint8_t low;
//		low = hex_data & 0xf;
//		
//		uint8_t high_ancii;
//		uint8_t low_ancii;
//		
//		
//		switch(high){
//			case 0x0: {high_ancii = 0x30; break;}
//			case 0x1: {high_ancii = 0x31; break;}
//			case 0x2: {high_ancii = 0x32; break;}
//			case 0x3: {high_ancii = 0x33; break;}
//			case 0x4: {high_ancii = 0x34; break;}
//			case 0x5: {high_ancii = 0x35; break;}
//			case 0x6: {high_ancii = 0x36; break;}
//			case 0x7: {high_ancii = 0x37; break;}
//		  case 0x8: {high_ancii = 0x38; break;}
//			case 0x9: {high_ancii = 0x39; break;}
//			case 0xa: {high_ancii = 0x41; break;}
//			case 0xb: {high_ancii = 0x42; break;}
//			case 0xc: {high_ancii = 0x43; break;}
//			case 0xd: {high_ancii = 0x44; break;}
//			case 0xe: {high_ancii = 0x45; break;}
//			case 0xf: {high_ancii = 0x46; break;}
//			default: break;
//		}
//		
//		switch(low){
//			case 0x0: {low_ancii = 0x30; break;}
//			case 0x1: {low_ancii = 0x31; break;}
//			case 0x2: {low_ancii = 0x32; break;}
//			case 0x3: {low_ancii = 0x33; break;}
//			case 0x4: {low_ancii = 0x34; break;}
//			case 0x5: {low_ancii = 0x35; break;}
//			case 0x6: {low_ancii = 0x36; break;}
//			case 0x7: {low_ancii = 0x37; break;}
//		  case 0x8: {low_ancii = 0x38; break;}
//			case 0x9: {low_ancii = 0x39; break;}
//			case 0xa: {low_ancii = 0x41; break;}
//			case 0xb: {low_ancii = 0x42; break;}
//			case 0xc: {low_ancii = 0x43; break;}
//			case 0xd: {low_ancii = 0x44; break;}
//			case 0xe: {low_ancii = 0x45; break;}
//			case 0xf: {low_ancii = 0x46; break;}
//			default: break;
//		}
//		
//		
//		while ((USART2->SR & USART_SR_TXE) == 0) {}
//					USART2->DR = high_ancii;
//			
//		while ((USART2->SR & USART_SR_TXE) == 0) {}
//					USART2->DR = low_ancii;
//	}
//	
//void SPI_UART_send(uint8_t tx_data)
//	{
//		CS_RESET();
//		SPI1->DR = tx_data;
//		while(!(READ_BIT(SPI1->SR, SPI_SR_TXE) == (SPI_SR_TXE))) {}
//		
//		delayMks(10);
//			
//		CS_SET();
//		
//		for(uint8_t i = 0; i<12; i++)
//			{
//				while ((USART2->SR & USART_SR_TXE) == 0) {}
//				USART2->DR = sentDataStr[i];		
//			}
//		
//		Hex_To_Str(tx_data);	
//while ((USART2->SR & USART_SR_TXE) == 0) {}
//				USART2->DR = 0x20;					
//	}

//void SPI_UART_send_3_byte(uint32_t tx_data)
//	{
//		uint8_t byte_0 = tx_data>>16;
//		uint8_t byte_1 = tx_data>>8;
//		uint8_t byte_2 = tx_data;
//		
//		CS_RESET();
//		SPI1->DR = byte_0;
//		while(!(READ_BIT(SPI1->SR, SPI_SR_TXE) == (SPI_SR_TXE))) {}
//		
//		SPI1->DR = byte_1;
//		while(!(READ_BIT(SPI1->SR, SPI_SR_TXE) == (SPI_SR_TXE))) {}

//		SPI1->DR = byte_2;
//		while(!(READ_BIT(SPI1->SR, SPI_SR_TXE) == (SPI_SR_TXE))) {}
//			
//		
//		//CS_SET();
//		
//			
//			
//		for(uint8_t i = 0; i<10; i++)
//			{
//				while ((USART2->SR & USART_SR_TXE) == 0) {}
//				USART2->DR = sentDataStr[i];		
//			}
//			
//		while ((USART2->SR & USART_SR_TXE) == 0) {}
//					USART2->DR = 0x30;
//		
//		while ((USART2->SR & USART_SR_TXE) == 0) {}
//					USART2->DR = 0x78;	
//		
//		Hex_To_Str(byte_0);
//		Hex_To_Str(byte_1);
//		Hex_To_Str(byte_2);
//			
//		while ((USART2->SR & USART_SR_TXE) == 0) {}
//					USART2->DR = 0x0A;	
//	}


//void SPI_UART_send(uint8_t tx_data)
//	{
//		CS_RESET();
//		SPI1->DR = tx_data;
//		while(!(READ_BIT(SPI1->SR, SPI_SR_TXE) == (SPI_SR_TXE))) {}
//		
//		delayMks(10);
//			
//		CS_SET();
//		
//		for(uint8_t i = 0; i<12; i++)
//			{
//				while ((USART2->SR & USART_SR_TXE) == 0) {}
//				USART2->DR = sentDataStr[i];		
//			}
//		
//		Hex_To_Str(tx_data);	
//while ((USART2->SR & USART_SR_TXE) == 0) {}
//				USART2->DR = 0x20;					
//	}

//void SPI_UART_send_3_byte(uint32_t tx_data)
//	{
//		uint8_t byte_0 = tx_data>>16;
//		uint8_t byte_1 = tx_data>>8;
//		uint8_t byte_2 = tx_data;
//		
//		CS_RESET();
//		SPI1->DR = byte_0;
//		while(!(READ_BIT(SPI1->SR, SPI_SR_TXE) == (SPI_SR_TXE))) {}
//		
//		SPI1->DR = byte_1;
//		while(!(READ_BIT(SPI1->SR, SPI_SR_TXE) == (SPI_SR_TXE))) {}

//		SPI1->DR = byte_2;
//		while(!(READ_BIT(SPI1->SR, SPI_SR_TXE) == (SPI_SR_TXE))) {}
//			
//		
//		//CS_SET();
//		
//			
//			
//		for(uint8_t i = 0; i<10; i++)
//			{
//				while ((USART2->SR & USART_SR_TXE) == 0) {}
//				USART2->DR = sentDataStr[i];		
//			}
//			
//		while ((USART2->SR & USART_SR_TXE) == 0) {}
//					USART2->DR = 0x30;
//		
//		while ((USART2->SR & USART_SR_TXE) == 0) {}
//					USART2->DR = 0x78;	
//		
//		Hex_To_Str(byte_0);
//		Hex_To_Str(byte_1);
//		Hex_To_Str(byte_2);
//			
//		while ((USART2->SR & USART_SR_TXE) == 0) {}
//					USART2->DR = 0x0A;	
//	}
//	


	