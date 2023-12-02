#include <stdio.h>
#include <ctype.h>

void part_one(FILE *f)
{
  char buf[100];
  while(fgets(buf,100,f))
  {
    printf("%s\n",buf);
  }
}

void part_two(FILE *f)
{
  char buf[100];
  while(fgets(buf,100,f))
  {
    printf("%s\n",buf);
  }
}

int main()
{
  char part;
  printf("to run part one type 1 else 2 for part two:");
  part = getchar();

  if(part != '1' && part != '2')
  {
    printf("invalid part");
    return 0; 
  }

  FILE *f;
  f = fopen("test.txt","r");
  if(f == NULL)
  { 
    printf("file could not be open!\n");
    return 1;
  }


  if(part == '1')
  {
    printf("running part 1\n");
    part_one(f);
  }
  else if(part == '2')
  {
    printf("running part 2\n");
    part_two(f);
  }

  fclose(f);
  return 0;
}
