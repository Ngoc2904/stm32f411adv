#include <stdint.h>
#include <stdio.h>
#include "rcc.h"
#include "gpio.h"
#include "systick.h"
#include "uart.h"
#include <string.h>
#include "exti.h"
//char Rx_Buff[64]={0};
//int  Rx_index=0;
void My_UART_Callback(char *Rx_buff, int Rx_index) {
    UART_Send_String(Rx_buff, Rx_index);
}
int main(){
	EXTI0_init();
    PLL_Clock_100Mhz_init();
    Led_init();
    Sys_tick_init();
    UART2_init();
    uart_RX_set_callback(My_UART_Callback);
    char data[]="get_temperature\n";
	while(1){
	UART_Send_String(data, sizeof(data));
    BlinkLED(LED1, LED_ON);
    BlinkLED(LED2, LED_ON);
    delay_ms(1000);
    BlinkLED(LED1, LED_OFF);
    BlinkLED(LED2, LED_OFF);
    delay_ms(1000);
	}
}
