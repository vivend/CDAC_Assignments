/*3. Write a code to toggle LED 2 with a constant delay of 200 us and use watchdog timer to glow LED 3 every 2 seconds.*/


#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>


int main()
{

PORTC^=(0x08); //watchdog rest toggles portc
PORTC &=(0b00001000);
DDRC=0xFF;
WDTCR = 0b00001000;// watch dog timer counter value value just give the countervalue to set the watchdog
OCR0 = 200;
TCCR0 = 0X09;
TIMSK = (1<<OCIE0);
sei ();

while(1);
}


ISR (TIMER0_COMP_vect)
{

PORTC ^= (0x04);
}

