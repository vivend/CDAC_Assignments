/*1. Demonstrate working of the LDR sensor by continuously scanning the sensor value on the HyperTerminal.*/


#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
int i=0;


int main(){
DDRB=0xFF;
DDRD=0xFF;
DDRA=0;
sei ();
ADCSRA = 0x8F;
ADMUX = 0xC0;
ADCSRA |=(1<<ADSC);
UBRR0L=12; 
    
    UCSR0B=(1<<TXEN0);
	UCSR0C=(3<<UCSZ10);
while(1);
}


ISR (ADC_vect)
{

PORTD = ADCL;
 
	UDR0 = PORTD;
    PORTB = ADCH;
	UDR0 = PORTB;
	ADCSRA|=(1<<ADSC);
	UDR0 = ' ';
}
