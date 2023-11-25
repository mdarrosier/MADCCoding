#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void reset_num(char arr[])
{
  arr[0] = '\0';
  arr[1] = '\0';
  arr[2] = '\0';
}

int main()
{
  FILE *f;
  f = fopen("input.txt","r");


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
          if(11 == count)
          {
    printf("\n A %d: %s\n",count,buf);
            printf("->  %d,%d,%d,%d\n",row[0] , row[2] , row[1],  row[3]);
            return 0;
          }
          sum++;
    printf("\n A %d: %s\n",count,buf);
        }
        // 2-3,1-3
        else if(row[2] <= row[0] && row[3] >= row[1])
        {
          sum++;
    printf("\n B %d: %s\n",count,buf);
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
  
  
  fclose(f);
  return 0;
}
