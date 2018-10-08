/*1. Demonstrate the concept preemption of external hardware of interrupts
(INT6 and INT7) by displaying corresponding messages on LCD panel.*/

/* Program to read switches SW3 and SW4 & print on the LCD if the switches are pressed using interrupts*/

#include <stddef.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void lcd_command(unsigned char cmd)
{
   PORTA=cmd & 0xf0;

   PORTA |=(1<<2);
  _delay_ms(5);
  PORTA &=0xf0;   

   cmd=(cmd<<4);
   PORTA=cmd & 0xf0;
   
   PORTA |=(1<<2);
  _delay_ms(5);
  PORTA &=0xf0;
}

void lcd_data(unsigned char data)
{
 
  PORTA = data & 0xf1;
	
	PORTA |=((1<<2)|(1<<0));
 _delay_ms(5);
  PORTA &=0xf1;   

   data = ( data <<4);
   PORTA = data & 0xf1;
   
   PORTA |=((1<<2)|(1<<0));
  _delay_ms(5);
  PORTA &=0xf1;
}

void lcd_init(void)
{
  DDRE &= ~((1 << 6) | (1 << 7)); //for switch 
  PORTE |= (1<<6) | (1 << 7); 	

  DDRA = 0xFF;
  lcd_command(0x28);
  lcd_command(0x0e);
  lcd_command(0x01);
  lcd_command(0x06);
  lcd_command(0x80);


 }

 void lcd_write(char *string)
 {
 	lcd_init();

	char* ptr = string;	

	while(*ptr != '\0') 
	{
		lcd_data(*ptr);
		ptr++;
	}
}


int main()
 {
 	lcd_init();
	lcd_write("Start");
	
	EIMSK |= (1<<6) | (1<<7); // to enable external interrupts

	EICRB |= ((1<<5) | (1 <<7));
	sei();

 	while(1);
	
}

ISR(INT6_vect)
{
	sei();
	while(1){
	lcd_write("SW3 Pressed!");
	}
}

ISR(INT7_vect)
{
	sei();
	while(1){
	lcd_write("SW4 Pressed!");
	}
}
