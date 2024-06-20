
#ifndef GPIO_H_
#define GPIO_H_
typedef enum {
	LED1=12,LED2=13
}Led_nums_t;
typedef enum{
	LED_ON=1,LED_OFF=0
}Led_status_t;
void Led_init();
void BlinkLED(Led_nums_t nums,Led_status_t status );
#endif
