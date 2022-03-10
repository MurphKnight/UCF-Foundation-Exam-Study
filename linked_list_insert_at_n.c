#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
} node;


// GLOBAL
node* head;


// Inserts integer at the begining of the list
void Insert(int data){
  node* temp = (node*) malloc( sizeof(node) );
  temp->data = data;
  temp->next = head;
  head = temp;
}

// Inserts integer at the end of the list
void InsertEnd(int data){
  node* temp = (node*) malloc( sizeof(node) );
  temp->data = data;
  temp->next = NULL;

  node* loc = head;
  while( loc->next != NULL ){
    loc = loc->next;
  }
  // loc is the last valid node in list
  loc->next = temp;
}


void Delete(int n){
  node* loc = head;

  //When deleting the head node
  if(n == 1){
    head = loc->next; // head now points to the second node
    free( loc ); //delete loc which holds the old head 
    return;
  }

  //index works 1, 2, 3, 4, 5
  for(int i=0; i<n-2; i++)
    loc = loc->next;
  //loc points to the (n-1)th node
  node* temp = loc->next;  // nth node
  loc->next = temp->next; // locs next is (n+1)th node,  link is FIXED
  free(temp); // delete temp
}

void recursiveFree(node* tmp){
  // We can stop.
  if(tmp == NULL)
    return;

  // Free the rest of the list.
  recursiveFree(tmp->next);

  // Free first node
  free(tmp);
}

void Print(){
  node* temp = head;
  printf("\nList: ");
  while( temp != NULL ){
    printf("%d --> ", temp->data );
    temp = temp->next;
  }
  printf("NULL\n");
}


void reversePrint(node* tp){
  if(tp == NULL){
    printf("\nReverse List: null --> ");
    return;
  }
  reversePrint(tp->next);
  printf("%d --> ", tp->data);
}

void recursivePrint(node* tp){
  if(tp == NULL){
    printf("null");
    return;
  }
  printf("%d --> ", tp->data);
  recursivePrint( tp->next );
}



int main(void) {
  printf("\n\t\t\trunning\n\n");

  //node* head;
  head = NULL;
  Insert(2);
  Insert(4);
  Insert(6);
  Insert(15); // List : 15, 6, 4, 2, null

  Print(); // List : 15, 6, 4, 2, null
  reversePrint(head);
  printf("\n\n");


  InsertEnd(45); // List : 15, 6, 4, 2, 45, null
  recursivePrint(head);
  printf("\n");




  printf("\n\nEnter a postion\n");
  //scanf("%d", &n);
  Delete(3);
  Print(); // 15, 6, -, 2, 45
  Delete(1);
  Print(); // -, 6, 2, 45

  printf("\n\nFree()\n");
  recursiveFree(head);
  //Print();  // This print checks that memory has been freed

  return 0;
}