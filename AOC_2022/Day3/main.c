#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_value(char c)
{
  if(islower(c))
  {
	return c - 96;
  }
  
  return c - 64 + 26;
}

void part_one(FILE *f)
{
  int sum = 0;
  char line[50];
  while(fgets(line,50,f))
  {
	int len = strlen(line) -1;
	int half = (len/2) - 1;
	char found[1] = {'-'};

	for(int i = 0; i <= half; i++)
	{
	  for(int j = half+1; j < len; j++)
	  {
		if(line[i] == line[j])
		{
		  found[0] = line[i];
		  break;
		}
	  }

	  if(found[0] != '-')
	  {
		break;
	  }
	}

	sum += get_value(found[0]);
	found[0] = '-';
  }

  //8088
  printf("Result : %d\n",sum);
}

int main()
{
  FILE *f = fopen("input.txt","r");

  part_one(f);


  fclose(f);
  return 0;
}

