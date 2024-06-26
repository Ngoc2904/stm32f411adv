#include "../My_Application/systick.h"

#include <stdint.h>
int tick=0;
void Sys_tick_init(){
	uint32_t *STK_CTRL = (uint32_t *)0xe000e010;
	uint32_t *STK_LOAD = (uint32_t *)0xe000e014;
	*STK_LOAD=100000/8-1;
	*STK_CTRL|=(1<<0)|(1<<1);
}
void SysTick_Handler(){
	uint32_t *STK_CTRL = (uint32_t *)0xe000e010;
	tick++;
	*STK_CTRL&=~(0b1<<16);
}
void delay_ms(int time){
	tick=0;
	while(tick<time);
}
