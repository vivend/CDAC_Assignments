#include<stdlib.h>
#include "bw.h"

char menu(){
	char choice;
	printf("\nSwitchboard\n");
	printf("\nAll_off | Heater - 3 | Fan - 2 | HC - 1 | AC - 0\n");
	scanf("\n%c",&choice);
	switch(choice){
		case '0':
		SWITCH(AC);
		choice =  menu();
		
		casse '1':
		SWITCH(HC);
		choice = menu();

		case '2':
		SWITCH(FAN);
		choice = menu();
		
		case '3':
		SWITCH(HEATER);	
		choice = menu();

		case '4':
		SWITCH(ALL_OFF);
		return '0';
	}
}
