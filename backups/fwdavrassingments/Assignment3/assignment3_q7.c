/*7. Write a C Program to drive the microcontroller to go in idle mode.
The microcontroller should be woken up by hardware interrupts
(Switches). Messages like “Microcontroller is going into idle mode”,
“Microcontroller woken up due h/w interrupt INT6 or INT7 “
should be printed on the serial console.*/

#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
int i=0;

int main(){
char st[5]={'s','l','e','e','p'};

MCUCR = 0x10; //idle mode
UBRR0L=12; 
    
    UCSR0B=(1<<TXEN0);
	UCSR0C=(3<<UCSZ10); 
	for(i=0;i<5;i++){
	UDR0 = st[i];
    PORTC = 0x00;
	}

 DDRC = (1<<3)|(1<<2);
 PORTC = 0x00;
 PORTE = 0b01000000; 
 EICRB = 0x30;
 EIMSK = 0x40;
 sei ();
 while(1){
 PORTA = 0xFF;}

   }

ISR (INT6_vect)
{
char st1[5]={' ','w','o','k','e'};
  for(i=0;i<5;i++){
	UDR0 = st1[i];
    PORTC = 0x00;
	}
}
