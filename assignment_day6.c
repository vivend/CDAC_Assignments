#include<stdio.h>
#include "a6.h" // a6 for assignment on the 6th day 
#define MAX_SIZE 500
/* function prototypes*/
void readArray( int [] );
/*function*/
int main(){
	int sample_array[ MAX_SIZE ] , number = 0 ;
	char choice;
	FILE * log = NULL;
	readArray( sample_array );
	printf("Your responses are being logged in output.txt");
	log = fopen("log.txt","w+");
	choice = menu( sample_array , log );
	return 0;
}
