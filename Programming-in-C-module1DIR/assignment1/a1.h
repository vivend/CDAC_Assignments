#include<stdio.h>
extern void readArray( int [ ] ) ;
extern char menu( int [] , FILE * ) ;
extern void addInt( int [ ] ) ;
extern void removeInt( int [ ] );
extern void modifyInt( int[] );
extern void printArray( int [ ] );
extern int sum_of_odd_positions(int [] );
extern void last_two_smallest_integers(int []);
extern int generic_search( const void  * , const void * , int (*) (const void *,const void *) );
extern int searchCriterion( const void * , const void * );
extern int comparefunc(const void *, const void * );
extern void intcopy( int [] , int [] );
extern void writeToFile( int [] , FILE *);
extern void readFromFile(int [] , FILE *);

