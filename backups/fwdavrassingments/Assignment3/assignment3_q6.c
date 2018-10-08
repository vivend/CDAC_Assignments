/*6. Write a C program using EEPROM interrupts to write some bytes of data
in EEPROM locations and then read the same bytes from EEPROM location.
The serial interface should be used to display messages like “Writing EEPROM “
, “Reading EEPROM” the values that are read have to be displayed on the serial
Console.*/

//doubt //




#include<avr/io.h>
#include<avr/interrupt.h>
unsigned int a;
int main()
{       char st[21]="writing 61,4,44,72,1";
	unsigned char a[5]={61,4,44,72,1};
	int i=0;
  UBRR0L=12; 
    
    UCSR0B=(1<<TXEN0);
	UCSR0C=(3<<UCSZ10); 
for(i=0;i<21;i++){
	UDR0 = st[i];
	}
while(EECR & (1<<EEWE));
	EEAR=0x20;
		EEDR=a[i];
		EECR |= (1<<EEMWE);
		EECR |= (1<<EEWE);
	for(i=1;i<5;i++)
	{
		
while(EECR & (1<<EEWE));
			
		EEDR=a[i];
		EEAR++;
		EECR |= (1<<EEMWE);
		EECR |= (1<<EEWE);
	

	}
	EECR =(1<<EERIE) ;
	
	sei();
	while(1);	
			return 0;
}

ISR(EE_READY_vect)
{
int i;
char st1[21] ="reading 61,4,44,72,1";
UBRR0L=12; 
    
    UCSR0B=(1<<TXEN0);
	UCSR0C=(3<<UCSZ10); 
for(i=0;i<21;i++){
	UDR0 = st1[i];
	}
DDRB=0xFF;
while(EECR & (1<<EEWE));
	EEAR++;
	EECR |= (1<<EERE);
	PORTB=EEDR;
for(int i=1;i<5;i++){
	while(EECR & (1<<EEWE));
	EEAR++;
	EECR |= (1<<EERE);
	a=EEDR;
	PORTB=a;
}
}

