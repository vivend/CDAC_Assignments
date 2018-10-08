/*2. Demonstrate working with I2C based RTC chip by doing write and read operations with RTC registers and output the values of these registers on serial console or on LCD display.*/



#include <avr/io.h>

void write(unsigned char data)
{
TWDR = data;    
TWCR = (1<<TWINT)|(1<<TWEN);
while((TWCR & (1<<TWINT)) == 0);
}

void start(void)   //starting I2C CONNECTION
{
TWCR = (1<< TWINT)|(1<< TWSTA)|(1<<TWEN);
while((TWCR & (1<<TWINT))==0);
}

void stop(void)  
{
TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void init(void)   //SETTING MODE FOR I2C
{
TWSR = 0x00;
TWBR = 0x47;
TWCR = 0x04;
}

unsigned char read(unsigned char buff)  //READING 1 BYTE OF DATA
{
if(buff == 0)
 TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
else
 TWCR = (1<<TWINT)|(1<<TWEN);

while((TWCR & (1<<TWINT))==0);
return TWDR;
}


int main(void)
{
UBRR0L=12; 
    
    UCSR0B=(1<<TXEN0);
	UCSR0C=(3<<UCSZ10); 
init();
start();
write(0b11010000); //TRANSMIT SLA +READ/WRITE
write(0b11110000); //SEND DATA
// OR i=read(1); read one byte of data
//porta = i; //seethe data in port or send it to uart terminal
UDR0 = 0b11110000;
stop();
while(1);
return 0;
}
