// CPU Clock Frequency
#ifndef F_CPU
#define F_CPU 16000000UL
#endif	

#include <avr/io.h>
#include <stddef.h>

// #define USART_BAUDRATE 9600
#define USART_BAUDRATE 19200
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)


void UART_init( void );
unsigned char UART_RxChar();
void UART_TxChar(unsigned char ch);
void UART_SendString(unsigned char *str, size_t len);