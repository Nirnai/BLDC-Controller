#ifndef F_CPU
#define F_CPU 16000000UL
#endif	

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>

void Timer1_Init();
void Timer2_Init();

void pwm1_enableHigh();
void pwm1_enableLow();
void pwm1_disable();

void pwm2_enableHigh();
void pwm2_enableLow();
void pwm2_disable();

void pwm3_enableHigh();
void pwm3_enableLow();
void pwm3_disable();

void pwm1_setDuty(uint8_t val);
void pwm2_setDuty(uint8_t val);
void pwm3_setDuty(uint8_t val);