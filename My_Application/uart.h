#ifndef UART_H_
#define UART_H_
#include <stdint.h>
typedef void (*uart_handle_t)(char *Rx_buff,int Rx_index);
void UART2_init();
void UART_Send_byte(char data);
void UART_Send_String(char *arr,int size);
void uart_RX_set_callback(void *ptr);
void uart_revice();
void uart_hand();
#endif
