// CPU Clock Frequency
#ifndef F_CPU
#define F_CPU 16000000UL
#endif	

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include "bldc.h"

uint8_t poti;

/* --------------------------------  Timers  ------------------------------------ */

// void Timer0_Init()
// {
//     cli(); 
//     // TCCR0B |= (1<<CS00);                    // Prescalar: fcpu/1
//     // TCCR0B |= (1<<CS01);                    // Prescalar: fcpu/8
//     TCCR0B |= (1<<CS00)| (1<<CS01);         // Prescalar: fcpu/64
//     // TCCR0B |= (1<<CS02);                    // Prescalar: fcpu/256
//     // TCCR0B |= (1<<CS00)| (1<<CS02);         // Prescalar: fcpu/1024
//     TIMSK0 |= (1<<TOIE0);     // Interrupt: Overflow; Compare
//     TCNT0 = 0x00;                           // set timer counter to 0
//     sei();
// }



int main()
{
    BLDC_Init();

    while(1)
    { 
        pwm1_setDuty(duty);
        pwm2_setDuty(duty);
        pwm3_setDuty(duty);

        if(startUp == 1)
            forwardComutate();
        else
            comutate();
    }
    return 0;

}


ISR(TIMER1_COMPB_vect)
{   
    getStateFromBEMF();
}

ISR(TIMER2_OVF_vect)
{
    static int cnt = 0;
    cnt ++;
    ADC5_Read(&poti);
    if(poti > 10 && poti < 200)
        duty = poti;

    
    // if(cnt > 100)
    // {
    //     UART_TxChar(duty);
    //     cnt = 0;
    // }
    
}


// ISR(TIMER0_OVF_vect)
// {
//     if(startUp == 1)
//         forwardComutate();
//     else
//         comutate();
// }

