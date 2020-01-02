#include "bldc.h"
#include <avr/interrupt.h>


void BLDC_Init()
{
    startUp = 1;
    duty = 0;
    i = 250;
    threshold = 2000;
    PORTB_Init();
    ADC_Init();
    Timer1_Init();
    Timer2_Init();
}


void PORTB_Init()
{
    DDRB |= 0xFF;
}

/* ------------------ */
/* Commutation States */
/* ------------------ */
void state1()
{
    cli();
    pwm1_enableLow();
    pwm3_disable();
    PORTB = 0b00010101;
    sei();
}

void state2()
{
    cli();
    pwm1_enableLow();
    pwm2_disable();
    PORTB = 0b00101001;
    sei();
}

void state3()
{
    cli();
    pwm2_enableLow();
    pwm1_disable();
    PORTB = 0b00111000;
    sei();
}


void state4()
{
    cli();
    pwm2_enableLow();
    pwm3_disable();
    PORTB = 0b00010011;
    sei();
}


void state5()
{
    cli();
    pwm3_enableLow();
    pwm2_disable();
    PORTB = 0b00100011;
    sei();  
}


void state6()
{
    cli();
    pwm3_enableLow();
    pwm1_disable();
    PORTB = 0b00110100;
    sei();
}

void comutate()
{
    switch(state)
    {
        case 1:
            state1();
            break;
        case 2:
            state2();
            break;
        case 3:
            state3();
            break;
        case 4:
            state4();
            break;
        case 5:
            state5();
            break;
        case 6:
            state6();
            break;
        default:
            break;
    }
}

void forwardComutate()
{
    static int cnt;
    cli();
    cnt++;
    if(cnt == i)
    {
        cnt = 0;
        comutate();
        state++;
        if(state == 7)
            state = 1; 
        if(i == 250 && duty == 0)
        {
            startUp = 0;  
        }
    }
}

void hallComutate()
{
    cli();
    uint8_t portCValues = PINC & 0b00111000;
    switch(portCValues)
        {
            case 0b00101000:
                state1();
                break;
            case 0b00001000:        // 0b00001000
                state2();
                break;
            case 0b00011000:
                state3();
                break;
            case 0b00010000:
                state4();
                break;
            case 0b00110000:
                state5();
                break;
            case 0b00100000:
                state6();
                break;
            default:
                break;
        }           
    sei();          
}


void getStateFromBEMF()
{
    static int cnt = 0;
    if(!startUp)
    {
        switch(state)
        {
            case 1:
                if(cnt > 3)
                    ADC2_Read(&temp);
                else 
                    cnt++;
                bemf = bemf + temp;
                if(bemf > threshold)
                {
                    state = 2;
                    bemf = 0;
                    cnt = 0;
                }
                break;
            case 2:
                if(cnt > 3)
                    ADC1_Read(&temp);
                else 
                    cnt++;
                bemf = bemf + temp;
                if(bemf > threshold)
                {
                    state = 3;
                    bemf = 0;
                    cnt = 0;
                }
                break;
            case 3:
                if(cnt > 3)
                    ADC0_Read(&temp);
                else 
                    cnt++;
                bemf = bemf + temp;
                if(bemf > threshold)
                {
                    state = 4;
                    bemf = 0;
                    cnt = 0;
                }
                break;
            case 4:
                if(cnt > 3)
                    ADC2_Read(&temp);
                else 
                    cnt++;
                bemf = bemf + temp;
                if(bemf > threshold)
                {
                    state = 5;
                    bemf = 0;
                    cnt = 0;
                }
                break;
            case 5:
                if(cnt > 3)
                    ADC1_Read(&temp);
                else
                    cnt++;
                bemf = bemf + temp;
                if(bemf > threshold)
                {
                    state = 6;
                    bemf = 0;
                    cnt = 0;
                } 
                break;
            case 6:
                if(cnt > 3)
                    ADC0_Read(&temp);
                else 
                    cnt++;
                bemf = bemf + temp;
                if(bemf > threshold)
                {
                    state = 1;
                    bemf = 0;
                    cnt = 0;
                }  
                break;
            default:
                break;
        }
    }
}

    