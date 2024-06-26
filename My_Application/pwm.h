#ifndef PWM_H_
#define PWM_H_
typedef enum{
	channel_3=3,
	channel_4=4,
}channel_t;
void PWM_Init();
void PWM_channelx_duty(channel_t channel ,uint8_t duty);

#endif
