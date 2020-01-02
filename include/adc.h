#ifndef F_CPU
#define F_CPU 16000000UL
#endif	

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>

void ADC_Init();
void ADC0_Read(uint8_t* data);
void ADC1_Read(uint8_t* data);
void ADC2_Read(uint8_t* data);
void ADC3_Read(uint8_t* data);
void ADC5_Read(uint8_t* data);