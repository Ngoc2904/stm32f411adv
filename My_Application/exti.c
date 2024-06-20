#include <stdint.h>
#include <exti.h>
void EXTI0_init(){
	uint32_t *RCC_AHB1ENR =(uint32_t*)(0x40023830);
	*RCC_AHB1ENR|=(1<<0);
	uint32_t *GPIOA_MODER =(uint32_t*)(0x40020000);
	uint32_t *GPIOA_PUPDR =(uint32_t*)(0x40020000+0x0C);
	*GPIOA_MODER&=~(0b11<<0);
	*GPIOA_PUPDR&=~(0b11<<0);
	uint32_t *SYSCFG_EXTICR1 =(uint32_t*)(0x40013808);
	*SYSCFG_EXTICR1&=~(0b1111<<0);
	uint32_t *EXTI_RTSR =(uint32_t*)(0x40013c08);
	*EXTI_RTSR|=(1<<0);
	uint32_t *EXTI_IMR =(uint32_t*)(0x40013c00);
    *EXTI_IMR |=(1<<0);
    uint32_t *NVIC_ISER0 =(uint32_t*)(0xe000e100);
    *NVIC_ISER0|=(1<<6);
}


