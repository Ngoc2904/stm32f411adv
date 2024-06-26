#include "adc.h"
#include "tempperature_cli.h"
#include "stdarg.h"
#include "uart.h"
#include "string.h"
#include "stdio.h"
#include "pwm.h"
void response_print( char* str,...){
	char stringArray[100];
	va_list args;
	va_start(args,str);
	vsprintf(stringArray,str,args);
	va_end(args);
	UART_Send_String(stringArray, strlen(stringArray));
}
void get_tempperature(char ** arr,int arg_num){
	if(arg_num<2){
		response_print("don't enough arg ,arg=%d\n",arg_num);
		return;
	}
	if(arg_num>2){
		response_print("too much arg ,arg=%d\n",arg_num);
		return;
	}
	char str[100];
	sprintf(str,"tempperature=%.2f*C\n",tempearture());
	UART_Send_String(str, strlen(str));
}
void set_tempperaturemax(char ** arr,int arg_num){
	if(arg_num<2){
		response_print("don't enough arg ,arg=%d\n",arg_num);
		return;
	}
	if(arg_num>2){
		response_print("too much arg ,arg=%d\n",arg_num);
		return;
	}
	response_print("success,arg=%d\n",arg_num);
	float data=0;
    data=atoi(arr[1]);
	if(tempearture()<=data){
     PWM_channelx_duty(channel_3, 30);
     PWM_channelx_duty(channel_4, 99);
	}
}
void set_tempperaturemin(char ** arr,int arg_num){
	if(arg_num<2){
		response_print("don't enough arg ,arg=%d\n",arg_num);
		return;
	}
	if(arg_num>2){
		response_print("too much arg ,arg=%d\n",arg_num);
		return;
	}
	response_print("success,arg=%d\n",arg_num);
	float data=0;
    data=atoi(**(arr+1));
	if(tempearture()>=data){
     PWM_channelx_duty(channel_3, 99);
     PWM_channelx_duty(channel_4, 30);
	}
}



