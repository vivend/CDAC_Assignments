/*2. Write a C Program to Print an ASCII value of ‘a’ continuously on the
serial terminal. Make use of serial interrupts. Baud rate can be set at 4800 bps.*/

#include<avr/io.h>
#include<avr/interrupt.h>
#define DATA 'A '
int main(void)
{
    
    //1. baud rate 
    UBRR1L=12;    //4800bps if fosc= 1MHz. CORRECT
        
    //enabling transmitter
    UCSR1B=(1<<TXEN1)|(1<<UDRIE1);
    
    UCSR1C=(3<<UCSZ10); //CORRECT

    sei ();/*set gobal interrupt enable*/
    while(1);
	
	 /* infinite while loop*/
}
ISR(USART1_UDRE_vect)
{
    /*PUT DATA INTO BUFFER*/
    UDR1=DATA;
   // return 0;

}
