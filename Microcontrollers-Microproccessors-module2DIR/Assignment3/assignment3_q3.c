 /*3. Write a C program to do loop back operation on the serial terminal using
interrupts. The microcontroller board should send back the data received.*/


#include<avr/io.h>
#include<avr/interrupt.h>
int main(void)
{
    
    UBRR1L=12;    //4800bps if fosc= 1MHz. CORRECT
        UBRR0L=12;
    //enabling transmitter
    UCSR1B=(1<<TXEN1);
	UCSR0B=(1<<RXEN0)|(1<<UDRIE0);
    UCSR0C=(3<<UCSZ00);
    UCSR1C=(3<<UCSZ10);
    //CORRECT
//-----------------------------------------------------
    sei();/*set gobal interrupt enable*/
    while(1); /* infinite while loop*/
}
ISR(USART0_UDRE_vect)
{
    /*PUT DATA INTO BUFFER*/
    PORTB=UDR0;
	UDR1=PORTB;
    return 0;

}
