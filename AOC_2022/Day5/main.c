#include <stdio.h>
#include <string.h>
#include "stack.h"


int main()
{
  FILE *f;
  f = fopen("test.txt","r");

  struct Stack* array[20];

  struct Stack* stack = createStack(100); 
  push(stack, 10); 
  push(stack, 20); 
  push(stack, 30); 

  array[0] = stack;

  printf("%d popped from stack\n", array[0]->top);
  

  fclose(f);
  return 0;
}
