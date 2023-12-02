#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void part_one(FILE *f)
{
  char buf[100];
  int sum = 0;
  while(fgets(buf,100,f))
  {
    int i = 0;
    char first[1] = {'a'};
    char last[1] = {'b'};
    while (buf[i])
    {
      if(isdigit(buf[i]) && buf[i] != '0')
      {
        if(first[0] == 'a')
        {
          last[0] =first[0] = buf[i];
        }
        else
        {
          last[0] = buf[i];
        }
      }
      i++;
    }
    char num[3] = {first[0], last[0], '\0'};
    sum += atoi(num);
  }
    printf("Result for part 1 is %d\n",sum);
}

char numbers[18][10] = {
  "1","2","3", "4", "5", "6", "7", "8", "9",
  "one","two", "three", "four", "five", "six", "seven", "eight", "nine",
};

int resolve(char number[10])
{
  int num = 0;
  if(strcmp(number , "1") == 0 || strcmp(number, "one") == 0) return 1;
  if(strcmp(number , "2") == 0 || strcmp(number, "two") == 0) return 2;
  if(strcmp(number , "3") == 0 || strcmp(number, "three") == 0) return 3;
  if(strcmp(number , "4") == 0 || strcmp(number, "four") == 0) return 4;
  if(strcmp(number , "5") == 0 || strcmp(number, "five") == 0) return 5;
  if(strcmp(number , "6") == 0 || strcmp(number, "six") == 0) return 6;
  if(strcmp(number , "7") == 0 || strcmp(number, "seven") == 0) return 7;
  if(strcmp(number , "8")  == 0|| strcmp(number, "eight") == 0) return 8;
  if(strcmp(number , "9") == 0 || strcmp(number, "nine") == 0) return 9;
  return num;
}

int find_number_exists(char *str)
{
  char *num;
  for(int i = 0; i < 9;i++)
  {
    num = strstr(str,numbers[i]);
    if(num != NULL)
    {
      int n = resolve(num);
      return n;
    }
  }
  return 0;
}

int find_number_string_exists(char *str)
{
  char *num;
  for(int i = 9; i < 18;i++)
  {
    num = strstr(str,numbers[i]);
    if(num != NULL)
    {
      int n = resolve(num);
      return n;
    }
  }
  return 0;
}

void getsubstr(char *str,char *dest,int start, int offset)
{
  char substr[100];
  if(offset > 100)
  {
    printf("invalid sub string offset, should be less than 100");
    dest[0] = '\0';
  }

  int dest_index = 0;
  int i = start;
  while(i < offset)
  {
    dest[dest_index] = str[i];
    i++;
    dest_index++;
  }
  dest[dest_index] ='\0';
}

void part_two(FILE *f)
{
  int count = 0;
  int sum = 0;
  char buf[100];
  while(fgets(buf,100,f))
  {
    count++;
    int first = -1;
    int last = -1;

    int sub_string_start = 0;
    char substr[100];
    int len = strlen(buf)-1;
    for(int i = 0; i < len; i++)
    {
      int offset = 0;
      getsubstr(buf,substr,sub_string_start,i+1);
      int number = find_number_exists(substr);
      if(number > 0)
      {
        //single digit need to advance by one char eg: "twoone" = 21 not 22, "2one" would evaluate to 22 becuse it keeps finding the same number over and over.
        offset++;
      }
      else 
      {
        number = find_number_string_exists(substr);
      }
      if(number > 0)
      {
        if(first == -1)
        {
          first = number;
          last = number;
          sub_string_start = i+offset;
        }
        else 
        {
          last = number;
          sub_string_start = i+offset;
        }
      }
    }
    printf("row %s - %d %d add: %d\n",buf,first,last, ((first*10)+last));
    sum += ((first*10)+last);
  }
  printf("Part 2 results is: %d\n",sum);
    printf("%d\n",count);
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
  f = fopen("input2.txt","r");
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
