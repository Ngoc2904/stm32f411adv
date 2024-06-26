#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "pwm.h"
#include "adc.h"
#include "exti.h"
#include "gpio.h"
#include "rcc.h"
#include "systick.h"
#include "uart.h"
#include "tempperature_cli.h"
#include "pwm.h"
int main(){
	EXTI0_init();
    PLL_Clock_100Mhz_init();
    Led_init();
    Sys_tick_init();
    UART2_init();
    ADC_init();
    PWM_Init();
	while(1){
		uart_hand();
		BlinkLED(LED1, LED_ON);
		BlinkLED(LED2, LED_ON);
		delay_ms(500);
		BlinkLED(LED1, LED_OFF);
		BlinkLED(LED2, LED_OFF);
		delay_ms(500);
	}
}
