#include <stdio.h>

void print_array(int arr[],int len)
{
  printf("[");
  for(int i = 0; i< len; i++)
  {
    if(i < len -1)
    {
      printf("%d, ",arr[i]);
    }
    else
    {
      printf("%d",arr[i]);
    }
  }
  printf("]\n");
}

void print_array_with_mark(int arr[],int len, int target, int location)
{
  printf("[");
  for(int i = 0; i< len; i++)
  {
    if(i == target)
    {
      printf("{%d}",arr[i]);
    }
    else if(i == location)
    {
      printf("<-(%d)",arr[i]);
    }

    if((i == target || i == location) && i < len -1)
    {
      printf(",");
      continue;
    }


    if(i < len -1)
    {
      printf("%d, ",arr[i]);
    }
    else
    {
      printf("%d",arr[i]);
    }
  }
  printf("]\n");
}


int main()
{
  int arr[] = {5,2,7,3,9,8,1};
  int length = sizeof(arr)/sizeof(arr[0]);
  print_array(arr,length);

  for(int i = 0; i < length -1; i++)
  {
    for(int j = i+1; j < length; j++)
    {
      if(arr[i] > arr[j])
      {
	print_array_with_mark(arr,length,i,j);
	//swap
	arr[i] += arr[j];
	arr[j] = arr[i] - arr[j];
	arr[i] -= arr[j];
      }
    }
  }

  print_array(arr,length);
  return 0;
}
