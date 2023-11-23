#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char NEW_LINE[] = "\n";

void calculate(int *most_so_far, int current_elf)
{
  if(current_elf > *most_so_far)
  {
    *most_so_far = current_elf;
  }
}

void part_one(FILE* filePtr)
{
  char buf[10];
  int most_cals = 0;
  int sum = 0;
  
  while(fgets(buf,10,filePtr))
  {
    if(strcmp(buf,NEW_LINE) != 0)
    {
      sum += atoi(buf);
    }
    else
    {
      calculate(&most_cals, sum);
      sum = 0;
    }
  }
  //response : 70764
  printf("most calories: %d\n",most_cals); 
}


void calculate_three_with_most(int cals[],int elf_cal)
{
  for(int i = 0; i < 3; i++)
  {
    if(cals[i] < elf_cal)
    {
      cals[i] += elf_cal; //z = x+y
      elf_cal = cals[i] - elf_cal;//z - y = x
      cals[i] = cals[i] - elf_cal;///z - x = y
    }
  }
}

void part_two(FILE* filePtr)
{

  if (filePtr == NULL) {
    printf("no such file.");
    return;
  }

  char buf[10];
  int most_cals[] = {0,0,0};
  int sum = 0;
  
  while(fgets(buf,10,filePtr))
  {
    if(strcmp(buf,NEW_LINE) != 0)
    {
      sum += atoi(buf);
    }
    else
    {
      calculate_three_with_most(most_cals, sum);
      sum = 0;
    }
  }

  sum = 0;
  for(int i = 0; i < 3; i++)
  {
    sum+= most_cals[i];
  }
  printf("most calories: %d\n",sum); 
  //response : 203905.
}

int main()
{
  int part;
  printf("which part to run? Options [1|2]:");
  scanf("%d",&part);

  if(part != 1 && part != 2)
  {
    printf("\nInvalid Option.");
    return 0;
  }
  
  FILE* filePtr = fopen("input.txt", "r");
  if (filePtr == NULL) {
    printf("no such file.");
    return 0;
  }

  if(part == 1)
  {
    part_one(filePtr);
  }
  else 
  {
    part_two(filePtr);
  }

  fclose(filePtr);
  return 0;
}
