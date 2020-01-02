#ifndef F_CPU
#define F_CPU 16000000UL
#endif	

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include "pwm.h"
#include "adc.h"

volatile uint8_t state;
uint8_t temp;
volatile uint8_t startUp;
volatile uint8_t duty;

unsigned int i;
unsigned int threshold;
unsigned int bemf;

void BLDC_Init();
void PORTB_Init();
void state1();
void state2();
void state3();
void state4();
void state5();
void state6();

void comutate();
void forwardComutate();
void hallComutate();

void getStateFromBEMF();