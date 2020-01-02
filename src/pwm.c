#include "pwm.h"
#include <avr/interrupt.h>

void Timer1_Init()
{
    cli();
    // // Wave Generation Mode : Fast PWM
    TCCR1A |= (1<<WGM10);
    TCCR1B |= (1<<WGM12);
    
    // Interrupt Compare Match
    TIMSK1 |= (1<<OCIE1B);

    // Prescaler 8
    TCCR1B |= (1<<CS11);
    sei();

}

void Timer2_Init()
{
    cli();
    // // Wave Generation Mode: Fast PWM Mode
    TCCR2A |= (1<<WGM20) | (1<<WGM21);
    // Prescalar 8
    TCCR2B |= (1<<CS21);
    // Interrupt on Overflow
    TIMSK2 |= (1<<TOIE2);
    sei();
}

void pwm1_enableHigh()
{
    TCCR1A |= (1<<COM1A1);
    TCCR1A &= ~(1<<COM1A0);
}

void pwm1_enableLow()
{
    TCCR1A |= (1<<COM1A1);
}

void pwm1_disable()
{
    TCCR1A &= ~(1<<COM1A0) & ~(1<<COM1A1);
}

void pwm2_enableHigh()
{
    TCCR1A |= (1<<COM1B1);
    TCCR1A &= ~(1<<COM1B0);
}

void pwm2_enableLow()
{
    TCCR1A |= (1<<COM1B1);
}

void pwm2_disable()
{
    TCCR1A &= ~(1<<COM1B0) & ~(1<<COM1B1);
}


void pwm3_enableHigh()
{
    TCCR2A |= (1<<COM2A1);
    TCCR2A &= ~(1<<COM2A0);
}

void pwm3_enableLow()
{
    TCCR2A |= (1<<COM2A1);
}

void pwm3_disable()
{
    TCCR2A &= ~(1<<COM2A0) & ~(1<<COM2A1);
}


void pwm1_setDuty(uint8_t val)
{
    OCR1A = val;
}

void pwm2_setDuty(uint8_t val)
{
    OCR1B = val;
}

void pwm3_setDuty(uint8_t val)
{
    OCR2A = val;
}