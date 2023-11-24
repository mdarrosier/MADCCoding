#include <stdio.h>
#include <string.h>
#include <ctype.h>

unsigned int get_value(char c)
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

void reset_array(unsigned int arr[])
{
  for(int i =0; i <= 52; i++)
  {
    arr[i] = 0;
  }
}

int get_bit(int pos)
{
  return pos == 0 ? 0x1 : pos == 1 ? 0x2 : 0x4;
}

int evaluate_char(unsigned int arr[],char c,unsigned int bit)
{
  int val = get_value(c);
  arr[val] = arr[val] | bit;
  return val;
}

void part_two(FILE *f)
{
  unsigned int arr[53];
  reset_array(arr);
  int sum = 0;
  char line[50];
  int position = 0;
  while(fgets(line,50,f))
  {
    int len = strlen(line) -1;
    unsigned int bit = get_bit(position);

    if(position < 2)
    {
      for(int i = 0; i < len; i++)
      {
	evaluate_char(arr,line[i],bit);
      }
      position++;
    }
    else
    {
      for(int i = 0; i < len; i++)
      {
	int val = evaluate_char(arr,line[i],bit);
	if(arr[val] == 7)
	{
	  sum += val;
	  reset_array(arr);
	  break;
	}
      }
      position = 0;
    }
  }
  //Result: 2522
  printf("Result : %d\n",sum);
}

int main()
{
  char o;
  printf("options: [1] for part 1 or [2] for part 2: ");
  o = getchar();
  if(o == '1' || o == '2')
  {
    FILE *f = fopen("input.txt","r");
    if(o == '1')
    {
      part_one(f);
    }
    else if(o == '2')
    {
      part_two(f);
    }
    fclose(f);
  }
  else
  {
    printf("\ninvalid option");
    return 0;
  }
  return 0;
}

