/*  A quick practice code: 
    - pointer that points to a integer
    - pointer that points to an array of integers
    - freeing the dynamically allocated memory that was used for the pointer
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("\n\t\t\trunning...\n\n\n");


  int *p;
  p = (int*)malloc(sizeof(int));

  // if you want to fill the spot in heap the p pointer is pointing to, you have to dereference p
  *p = 19;
  free(p);

  p = (int*)malloc(20*sizeof(int));
  *p = 10;
  *(p+1) = 20;
  *(p+2) = 30;
  
  for(int i=0; i<3; i++)
    printf("[%d] = %d\n", i, *(p+i) );
  free(p);

  return 0;
}
