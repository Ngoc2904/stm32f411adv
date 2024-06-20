#include <stdint.h>
#include "rcc.h"
void PLL_Clock_100Mhz_init() {
	    uint32_t *RCC_CR = (uint32_t *)0x40023800;
	    uint32_t *RCC_PLLCFGR = (uint32_t *)0x40023804;
	    uint32_t *RCC_CFGR = (uint32_t *)0x40023808;
	    uint32_t *FLASH_ACR = (uint32_t *)0x40023C00;
	    *FLASH_ACR|=(5)|(0b111<<8);
	    *RCC_CR |= (1 << 0);
	    while (!(*RCC_CR & (1 << 1)));
	    *RCC_PLLCFGR &= ~(1 << 22);
	    *RCC_PLLCFGR &= ~(0x3F);
	    *RCC_PLLCFGR |= (16 << 0);
	    *RCC_PLLCFGR &= ~(0x1FF << 6);
	    *RCC_PLLCFGR |= (200 << 6);
	    *RCC_PLLCFGR &= ~(0b11 << 16);
	    *RCC_PLLCFGR |= (0b00 << 16);
	    *RCC_CR |= (1 << 24);
	    while (((*RCC_CR>>25 )&1)==0);
	    *RCC_CFGR &= ~(0b11 << 0);
	    *RCC_CFGR |= (0b10 << 0);
	    *RCC_CFGR |= (0b100 << 10);
	    *RCC_CFGR |= (0b101 << 13);
	    while ((*RCC_CFGR & (0b11 << 2)) != (0b10 << 2));
}


