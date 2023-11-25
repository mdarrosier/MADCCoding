#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void reset_num(char arr[])
{
  arr[0] = '\0';
  arr[1] = '\0';
  arr[2] = '\0';
}

void part_one(FILE *f)
{
  char buf[100];
  int row[4];
  int rowi = 0;
  int sum = 0;
  int numi = 0;

  int count = 0;


  while(fgets(buf,100,f))
  {
    count++;
    char num[3];
    char len = strlen(buf);
    for(int i = 0; i < len; i++)
    {
      if(buf[i] == ',')
      {
        row[rowi] = atoi(num);
        reset_num(num);
        rowi++;
        numi=0;
      }
      else if(buf[i] == '-')
      {
        row[rowi] = atoi(num);
        reset_num(num);
        rowi++;
        numi=0;
      }
      else if(buf[i] == '\n')
      {
        row[rowi] = atoi(num);
        reset_num(num);
        numi=0;
        rowi++;
        // 1-4,1-2
        //  A 11: 46-69,7-46
        if(row[0] <= row[2] && row[1] >= row[3])
        {
          sum++;
        }
        // 2-3,1-3
        else if(row[2] <= row[0] && row[3] >= row[1])
        {
          sum++;
        }
      }
      else
      {
        num[numi] = buf[i];
        numi++;
      }
    }
    //reset for next row
    rowi = 0;
  }

  printf("\nResult: %d\n",sum);
}

void part_two(FILE *f)
{
  char buf[100];
  int row[4];
  int rowi = 0;
  int sum = 0;
  int numi = 0;

  int count = 0;


  while(fgets(buf,100,f))
  {
    count++;
    char num[3];
    char len = strlen(buf);
    for(int i = 0; i < len; i++)
    {
      if(buf[i] == ',')
      {
        row[rowi] = atoi(num);
        reset_num(num);
        rowi++;
        numi=0;
      }
      else if(buf[i] == '-')
      {
        row[rowi] = atoi(num);
        reset_num(num);
        rowi++;
        numi=0;
      }
      else if(buf[i] == '\n')
      {
        row[rowi] = atoi(num);
        reset_num(num);
        numi=0;
        rowi++;
        // 1-4,2-5
        if(row[0] <= row[2] && row[1] >= row[2])
        {
          sum++;
        }
        // 2-6,4-5
        else if(row[0] <= row[3] && row[1] >= row[3])
        {
          sum++;
        }
        else if(row[0] <= row[2] && row[1] >= row[3])
        {
          sum++;
        }
        // 2-3,1-3
        else if(row[2] <= row[0] && row[3] >= row[1])
        {
          sum++;
        }
      }
      else
      {
        num[numi] = buf[i];
        numi++;
      }
    }
    //reset for next row
    rowi = 0;
  }

  printf("\nResult: %d\n",sum);
}

int main()
{
  FILE *f;
  char c;
  printf("enter 1 or 2 for the desire part: ");
  c = getchar();

  if(c == '1' || c == '2')
  {
    f = fopen("input.txt","r");
    if(c == '1')
    {
      part_one(f);
    }
    else 
    {
      part_two(f);
    }
    fclose(f);
  }
  else 
  {
    printf("\ninvalid option!!!!\n");
  }
  
  
  return 0;
}
