#include "adc.h"

void ADC_Init()
{
    // AVCC with external capacitor at AREF pin
    ADMUX |= (1<<REFS0);
    // Data left adjusted   
    ADMUX |= (1<<ADLAR);  
    // Prescalar 4
    ADCSRA |= (1<<ADPS1);  
    // Enable ADC
    ADCSRA |= (1<<ADEN);
}

void ADC0_Read(uint8_t* data)
{
    ADMUX &= 0b11110000;
    ADCSRA |= (1<<ADSC);
    while(!(ADCSRA&(1<<ADSC)));
    *data = ADCH;
}

void ADC1_Read(uint8_t* data)
{
    ADMUX &= 0b11110000;
    ADMUX |= (1<<MUX0);
    ADCSRA |= (1<<ADSC);
    while(!(ADCSRA&(1<<ADSC)));
    *data = ADCH;
    
}

void ADC2_Read(uint8_t* data)
{
    ADMUX &= 0b11110000;
    ADMUX |= (1<<MUX1);
    ADCSRA |= (1<<ADSC);
    while(!(ADCSRA&(1<<ADSC)));
    *data = ADCH;
}

void ADC3_Read(uint8_t* data)
{
    ADMUX &= 0b11110000;
    ADMUX |= (1<<MUX0) | (1<<MUX1);
    ADCSRA |= (1<<ADSC);
    while(!(ADCSRA&(1<<ADSC)));
    *data = ADCH;
}



void ADC5_Read(uint8_t* data)
{
    ADMUX &= 0b11110000;
    ADMUX |= (1<<MUX0) | (1<<MUX2);
    ADCSRA |= (1<<ADSC);
    while(!(ADCSRA&(1<<ADSC)));
    *data = ADCH;
}