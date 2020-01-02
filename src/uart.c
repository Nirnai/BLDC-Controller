#include "uart.h"

void UART_init( void )
{
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);   // Turn on the transmission and reception circuitry 
    UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01); // Use 8-bit character sizes 

    UBRR0H = (BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register 
    UBRR0L = BAUD_PRESCALE; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register 

}



unsigned char UART_RxChar()
{
    while ((UCSR0A & (1 << RXC0)) == 0); // Do nothing until data have been received and is ready to be read from UDR 
    return(UDR0); // Fetch the received byte value into the variable "ByteReceived"
}

void UART_TxChar(unsigned char ch)
{
    while ((UCSR0A & (1 << UDRE0)) == 0) {}; // Do nothing until UDR is ready for more data to be written to it 
    UDR0 = ch;
} 

void UART_SendString(unsigned char *str, size_t len)
{
    unsigned char j=0;

    for(j = 0; j<len; j++)
    {
        UART_TxChar(str[j]);
    }
}