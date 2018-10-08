/*5. Write a C program to read the data from hyper terminal and Print the
same on LCD panel.*/

#include<avr/io.h>
#include<avr/interrupt.h>
	#include<util/delay.h>
	#define PRT PORTA
	#define RS 0
	#define RW 1
	#define EN 2
	
	void delay_ms(int d);
	void delay(int d);
	void LCD_init(void);
	void goto_LCD(unsigned char x,unsigned char y);	
	void lcd_command(unsigned char cmd);
	void LCD_Data(unsigned char data);
	void LCD_string(unsigned char *ptr);

unsigned char buff;
int i=0;
int j=1;
ISR(USART0_RX_vect)
{
    /*PUT DATA INTO BUFFER*/
    buff=UDR0;
i++;
if(i==17)
{
j=2;
i=1;
}
   // return 0;

}


	int main()
	{
	  UBRR0L=12;
      UCSR0B=(1<<RXEN0)|(1<<RXCIE);
    UCSR0C=(3<<UCSZ00);
		
		LCD_init();
		goto_LCD(1,1);
        LCD_string("start");
		sei ();
		while(1){
	
		goto_LCD(i,j);
       LCD_string(&buff);
		
	 }
	 }

	 void goto_LCD(unsigned char x,unsigned char y)
	 {

	  	unsigned char arr[]= {0x80,0xc0};
	 	 lcd_command(arr[y-1] + (x-1));
		 delay_ms(100);
	 }

	 void lcd_command(unsigned char cmd)
	 {

		  PRT = ((PRT & 0x0F) | (cmd & 0xF0));
		  PRT &= (~(1<<RS));
		  PRT &= (~(1<<RW));
		  PRT |= (1<<EN);
		  delay_ms(1);
		  PRT &= (~(1<<EN));

		  delay_ms(20);
		
		  PRT = ((PRT & 0x0F) | (cmd <<4));
		  PRT |= (1<<EN);
		  delay_ms(1);
		  PRT &= (~(1<<EN));

	}

	void LCD_Data(unsigned char data)
	{

		  PRT = ((PRT & 0x0F) | (data & 0xF0));
		  PRT |= ((1<<RS));
		  PRT &= (~(1<<RW));
		  PRT |= (1<<EN);
		  delay_ms(1);
		  PRT &= (~(1<<EN));

		  delay_ms(20);
		
		  PRT = ((PRT & 0x0F) | (data <<4));
		  PRT |= (1<<EN);
		  delay_ms(1);
		  PRT &= (~(1<<EN));

	}

	void LCD_string(unsigned char *ptr)
	{
		unsigned char i=0;
		while(ptr[i] != 0)
		{
			LCD_Data(ptr[i]);
			i++;
		}
	}

	void LCD_init(void)
	{

	  	DDRA = 0xFF;

	  	 PRT &= (~(1<<EN));
			delay_ms(2000);
		lcd_command(0x33);
		delay_ms(100);
		lcd_command(0x32);
		delay_ms(100);
		lcd_command(0x0e);
		delay_ms(100);
		lcd_command(0x01);
		delay_ms(1000);
		lcd_command(0x06);
		delay_ms(100);
	}


	void delay_ms(int d)
	{
		_delay_us(d);
	}

	void delay(int d)
	{

	 _delay_ms(d);
	}
