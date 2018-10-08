/*4. Write a C Program to read the Switches SW1, SW2, SW3 and SW4 and
display the corresponding read message on the hyper terminal.
Make use of Interrupts.*/

#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
int i=0;

int main(){
UBRR0L=12; 
    
    UCSR0B=(1<<TXEN0)|(1<<UDRIE0);
	UCSR0C=(3<<UCSZ10); 
 DDRC = (1<<3)|(1<<2);
 PORTC = 0x00;
 PORTD = 0b00001111; //switchs
 EICRA = 0xFF;//The rising edge between two samples of INTn generates an interrupt
//request.
 EIMSK = (1<<INT0)|(1<<INT1)|(1<<INT2)|(1<<INT3);//enable external interrupts
 sei ();
 while(1);//{
 //PORTA = 0xFF;}

   }

ISR (INT0_vect)
{
  //PORTC = 0b00000100;
  //printf("here lcd works");
  i=1;
}

ISR (INT1_vect)
{
//PORTC = 0b00001000;
i=2;
}


ISR (INT2_vect)
{
  //PORTC = 0b00000100;
  //printf("here lcd works");
  i=3;
}

ISR (INT3_vect)
{
//PORTC = 0b00001000;
i=4;
}
ISR (USART0_UDRE_vect)
{   if(i==1){
 
   UDR0='a';
   
   i=0;}
   if(i==2){
 
   UDR0='b';
   
   i=0;}
   if(i==3){
 
   UDR0='c';
   
   i=0;}
   if(i==4){
 
   UDR0='d';
   
   i=0;}
}
