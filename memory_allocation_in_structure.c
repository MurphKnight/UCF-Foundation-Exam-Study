/*  A practice code for memory allocation for a structure: 
    - structure that holds a character (name) and integer (age)
    - dynamically allocated struct ironman
    - dynamically allocated array of structs
    - freeing the dynamically allocated memory
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct person{
  char* name;
  int age;
} person;

void printPerson(person * p){
  printf("\tname: %s,  ", p->name);
  printf("\tage: %d\n\n", p->age );
}

int main(void) {
  person* ironman = (person*) malloc( sizeof(person) );
  ironman->name = "Tony Stark";
  ironman->age = 50;
  printf("Pointer ironman: \n");
  printPerson(ironman);

  //array of structs size 3
  person* arr = (person*) malloc(3*sizeof(person));
  arr[0].name = "Peter Parker";
  arr[0].age = 17;

  arr[1].name = "Kate Bishop";
  arr[1].age = 22;

  arr[2].name = "Steve Rogers";
  arr[2].age = 104;

  printf("\n\nArray of Pointers: \n");
  printPerson( &arr[0] );
  printPerson( &arr[1] );
  printPerson( &arr[2] );
  

  // Free all of the memory
  free(ironman);
  free(arr);
  return 0;
}