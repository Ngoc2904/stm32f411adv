#include "gpio.h"
#include <stdint.h>
void Led_init(){
	uint32_t *RCC_AHB1ENR =(uint32_t*)(0x40023830);
	*RCC_AHB1ENR|=(1<<3);
	uint32_t *GPIOD_MODER=(uint32_t*)0x40020c00;
	*GPIOD_MODER&=~(0xff<<24);
	*GPIOD_MODER|=(0b01<<24)|(0b01<<26);
}
void BlinkLED(Led_nums_t nums,Led_status_t status ){
	uint32_t *GPIOD_ODR =(uint32_t*)(0x40020c14);
	if(status==LED_ON){
		*GPIOD_ODR&=~(0xff);
		*GPIOD_ODR|=(1<<nums);
	}else{
		*GPIOD_ODR&=~(1<<nums);
	}
}
