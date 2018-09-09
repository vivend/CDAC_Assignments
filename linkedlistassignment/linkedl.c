#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node *next;
}NODE;

//Self referential structure means:
/*A structure that has a pointer to itself*/

/*Let's make all structure variables auto in main*/
NODE *head = NULL;
NODE *current = NULL;

//display the list
void printList() {

   NODE *ptr = head;

   printf("\n[head] =>");
   //start from the beginning
   while(ptr != NULL) {        
      printf(" %d =>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [null]\n");
}

void insert(int data) {
//insert link at the first location
   //Completely modifying the insert function
   //create a link
   NODE *link = (struct node*) malloc(sizeof(struct node));

   //link->key = key;
   link->data = data;

   //point it to old first node
   link->next = head;

   //point first to new first node
   head = link;
}

int main() {
   insert(10);
   insert(20);
   insert(30);
   insert(1);
   insert(40);
   insert(56); 

   printList();
   return 0;
  }
