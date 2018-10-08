#ifndef __LL
# define __LL 1
#endif
typedef struct node {
   int data;
   struct node *next;
}NODE;

void printList(NODE *);
