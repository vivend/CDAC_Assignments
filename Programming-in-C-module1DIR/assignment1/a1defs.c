//Function definitions
#include<stdio.h>
#include<error.h>
#include<stdlib.h>
#include "a1.h"
//Global variable used by all functions
static int size = 0;

void readArray(int sample_array[]){
	int sample_array_i = 0;
	printf("Enter the size of the array\n");
	scanf("%d", &size);
	for( sample_array_i = 0 ; sample_array_i < size ; sample_array_i++){
		sample_array[ sample_array_i ] = 0 ; 
	}
 }

char menu( int sample_array[] , FILE *log ){
	char choice ; int sum = 0;
	printf("Menu\n");
	printf("(a).  AddInt\n");
	printf("(b).Remove Int\n");
	printf("(c). Modify Int\n");
	printf("(d). View All\n");
	printf("(e). Print sum of odd positions in the array.\n");
	printf("(f). Print the two smallest numbers in the array\n");
	printf("(g). Exit\n");
	printf("Enter your choice :     ");
	scanf("\n%c", &choice );
	readFromFile( sample_array , log);

	switch( choice ){

		case 'a':
		addInt( sample_array );
		writeToFile( sample_array , log);
		return menu( sample_array , log);

		case 'b':
		removeInt( sample_array );
		writeToFile( sample_array , log);
		return menu( sample_array , log);

		case 'c':
		modifyInt( sample_array );
		return menu( sample_array , log );
				
	
		case 'd':
		printArray( sample_array );
		return menu( sample_array , log);
		
		case 'e':
		sum = sum_of_odd_positions( sample_array );
		printf("SUM = %d\n" , sum);
		return menu( sample_array ,log);

		case 'f':
		last_two_smallest_integers( sample_array );
		return menu( sample_array , log);

		case 'g':
		return '0';

		default:
		printf("Incorrect option , please try again\n");
		return menu( sample_array , log);		
	}

	return choice;
}

void addInt( int sample_array[ ]  ){
	int sample_array_i = 0 , found = 0 , number_to_be_added = 0 ;
	found = generic_search( sample_array , &number_to_be_added , \
		searchCriterion );
	if(found < 0){
		perror("All array elements are filled");
		return;
	}
	else{
		printf("Enter the number to be added\n");
		scanf("%d", &number_to_be_added);
		if(number_to_be_added == 0){
			perror("Cannot add an empty element\n");
		}
		else{
			printf("Zero found at position = %d\n" , found);
			printf("Adding %d at position %d\n", number_to_be_added\
			, found);
			sample_array[found]+=number_to_be_added;
		}
	}
}
int generic_search( const void  *array , const void * key,\
	 int (* searchp) (const void *,const void *) ){
	int array_i = 0 , found = -1;	
	return (found = (*searchp)(array,key) );
}
int searchCriterion( const void *array , const void * quantityB){
	int array_i = 0;
	for(array_i = 0; array_i < size && \
	*( (int*)array + array_i) != *(int *)quantityB ;\
	array_i++);
	if(array_i == size){
		return -1;
	}
	else{
		return array_i;
	}		
}	
void removeInt( int sample_array[ ] ){
	int sample_array_i = 0 , found = 0 , number_to_be_removed = 0 ;
	printf("Enter number to be removed\n");
	scanf("%d", &number_to_be_removed);
	if( number_to_be_removed != 0){
		found = generic_search( sample_array ,\
		 &number_to_be_removed ,\
		 searchCriterion );
		 
		if( found < 0 ){
			perror("No such array element found");
		}
		else{
			sample_array[found] = 0;			
		}
	}
	else{
		perror("You are trying to find an empty element. Please try again \n");
	}
}


void modifyInt( int sample_array[] ){
	int sample_array_i = 0 , found = 0 , number_to_be_replaced = 0 , \
	new_number = 0;
	printf("Enter number to be replaced\n");
	scanf("%d", &number_to_be_replaced);
	if( number_to_be_replaced != 0){
		found = generic_search( sample_array , &number_to_be_replaced , searchCriterion );
		if( found < 0 ){
			perror("No such array element found\n");
		}
		else{
			printf("Enter a number to replace %d\n" , number_to_be_replaced );
			scanf("%d", &new_number );
			if( generic_search( sample_array , &new_number , searchCriterion ) == -1 )		
				sample_array[found] = new_number;
			else perror("Number not unique -- cannot be added\n");			
		}
	}
	else{
		perror("You are trying to find an empty element. Please try again \n");
	}
}

void printArray( int sample_array[] ){
	int sample_array_i = 0;
	printf("Contents of ther array\n");
	for( sample_array_i = 0; sample_array_i < size ; sample_array_i++ ){
		printf("%d  ", sample_array[ sample_array_i ]);
	}
	printf("\n");
}


int sum_of_odd_positions(int array[] ){
	int sum =0;
	for(int array_i = 1 ; array_i  < size ; array_i = array_i + 2 ){
		sum += array[ array_i ];
	}
	return sum;
}

void last_two_smallest_integers( int array[] ){
 	int sortable_array[size];
	intcopy(array, sortable_array);
	qsort( sortable_array , size , sizeof(int) , comparefunc );
	printf("Smallest values are %d and %d\n", sortable_array[0]  , sortable_array[1]); 
}

void intcopy( int sample_array[] , int sortable_array[] ){
	int copy_i = 0;
	for( copy_i = 0; copy_i < size ; copy_i++)
		sortable_array[copy_i] = sample_array[copy_i];
	
}	

int comparefunc(const void * a , const void * b){
	return *(int *)a - *(int *)b;
}


void writeToFile( int sample_array[] , FILE *log){
	int sample_array_i = 0;
	for(sample_array_i = 0; sample_array_i < size ; sample_array_i++ ){
		fprintf(log, "array[%d] = %d\n",sample_array_i, sample_array[sample_array_i]);
	}
}

void readFromFile( int sample_array[] , FILE *log){
	int sample_array_i = 0;
	for(sample_array_i = 0; sample_array_i < size ; sample_array_i++ ){
		fscanf(log, "array[%d] = %d\n",&sample_array_i, &sample_array[sample_array_i]);
	}
}
