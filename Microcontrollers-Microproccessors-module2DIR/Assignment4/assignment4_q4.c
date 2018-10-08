/*4.Writea code to toggle LED 3 with a frequencyof ~ 1 kHzand a duty cycle of 75%.*/

// dout redo// 

#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>


int main(){
DDRB=0xFF;
DDRC=0xFF;
OCR0 = 94;
TCNT0 = 225;
TCCR0 = 0X0A;
TIMSK = (1<<OCIE0)|(1<<TOIE0);
sei ();

while(1);
}


ISR (TIMER0_COMP_vect)
{

PORTC &=(~(1<<2));
}

ISR (TIMER0_OVF_vect)
{

PORTC |=(1<<2);
}
