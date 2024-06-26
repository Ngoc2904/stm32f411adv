#include <stdint.h>
#include "pwm.h"
void PWM_Init(){
	uint32_t *RCC_AHB1ENR =(uint32_t*)(0x40023830);
	*RCC_AHB1ENR|=(1<<3);
	uint32_t *RCC_APB1ENR =(uint32_t*)(0x40023840);
	*RCC_APB1ENR|=(1<<2);
	uint32_t *GPIOD_MODER =(uint32_t*)(0x40020c00);
	uint32_t *GPIOD_AFRH =(uint32_t*)(0x40020c24);
	*GPIOD_MODER|=(0b10<<28)|(0b10<<30);
	*GPIOD_AFRH|=(0b0010<<24)|(0b0010<<28);
	uint16_t *TIM4_CR1 =(uint16_t*)(0x40000800);
	uint16_t *TIM4_ARR =(uint16_t*)(0x4000082c);
	uint16_t *TIM4_PSC =(uint16_t*)(0x40000828);
	uint16_t *TIM4_CCER =(uint16_t*)(0x40000820);
	uint16_t *TIM4_CCMR2_out =(uint16_t*)(0x40000818+0x04);
	*TIM4_PSC=500-1;
	*TIM4_ARR=99;
	*TIM4_CCMR2_out&=~(0b11);
	*TIM4_CCMR2_out|=(0b110<<4)|(0b110<<12);
	*TIM4_CCER|=(1<<8)|(1<<12);
	*TIM4_CR1|=1;
}

void PWM_channelx_duty(channel_t channel ,uint8_t duty){
	if(channel==channel_3){
	uint32_t *TIM4_CCR1 =(uint32_t*)(0x4000083c);
	    *TIM4_CCR1=duty;
	}else if(channel==channel_4){
		uint32_t *TIM4_CCR4 =(uint32_t*)(0x40000840);
		*TIM4_CCR4=duty;
	}
}



