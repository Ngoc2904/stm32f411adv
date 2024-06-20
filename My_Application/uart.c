#include "uart.h"
#include <stdint.h>
#include <stdio.h>
static uart_handle_t uart_handler=UART_Send_String;
void UART2_init(){
	uint32_t *RCC_APB1ENR =(uint32_t*)(0x40023840);
	*RCC_APB1ENR|=(1<<17);
	uint32_t *GPIOA_MODER =(uint32_t*)(0x40020000);
	*GPIOA_MODER&=~(0b1111<<4);
	*GPIOA_MODER|=(0b10<<4)|(0b10<<6);
	uint32_t *GPIOA_AFRL =(uint32_t*)(0x40020020);
	*GPIOA_AFRL&=~(0xff<<8);
	*GPIOA_AFRL |=(0b0111<<8)|(0b0111<<12);
	uint32_t *USART2_BRR =(uint32_t*)(0x40004408);
	*USART2_BRR|=(325<<4)|(9<<0);
	uint32_t *USART2_CR1 =(uint32_t*)(0x4000440c);
	*USART2_CR1|=(0b11<<2)|(1<<13);
//	uint32_t *CR3 =(uint32_t*)(0x40004414);
//	*CR3 |=(1<<6);
	*USART2_CR1|=(1<<5);
	uint32_t *NVIC_ISER1 =(uint32_t*)(0xe000e100+0x04);
	*NVIC_ISER1|=(1<<6);
}
void UART_Send_byte(char data){
    uint32_t *DR =(uint32_t*)(0x40004404);
    uint32_t *SR =(uint32_t*)(0x40004400);
    while(((*SR>>7)&1)!=1);
    *DR=data;
    while(((*SR>>6)&1)!=1);
}
void UART_Send_String(char *arr,int size){
	for(int i=0;i<size;i++){
		UART_Send_byte(*(arr+i));
	}
}
char rx_buf[64]={0};
int rx_index=0;
void USART2_IRQHandler(){
    uint32_t *DR = (uint32_t*)(0x40004404);
    rx_buf[rx_index] = *DR;
    rx_index++;
    if (rx_index >= 64) {
        rx_index = 0; // Reset index if buffer is full
    }
    uart_handler(rx_buf, rx_index);
}
void uart_RX_set_callback(void *ptr){
	ptr=uart_handler;
}


