#include <stdio.h>
#include <string.h>

typedef struct {
  int red;
  int green;
  int blue;
} cube;

int gen_str(char *src, char *dest, int start, char until)
{
  int len = strlen(src);
  int dest_index = 0;
  for(int i = start; i < len; i++)
  {
	if(src[i] == until)
	{
	  return i;
	}
	if(src[i] == '\0')
	{
	  return -1;
	}
	dest[dest_index] = src[i];
	dest_index++;
  }
  return -1;
}

int get_id(char *str)
{
  int id;
  sscanf(str, "Game %d",&id);
  return id;
}

void get_cube(char *str,char *col,int *num)
{
  sscanf(str, "%d %s",num,col);
  printf("getcube %s col: %s, num: %d\n",str,col,(*num));
}


void part_one(FILE *f)
{
  cube cube = {12,13,14};
  char buf[200];
  int sum = 0;

  while(fgets(buf,200,f))
  {
		//reset for next game
		cube.red =12;
		cube.green = 13; 
		cube.blue = 14;
	printf("\nrow %s\n",buf);
	//Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
	char game[10];
	int start = gen_str(buf, game, 0, ':') + 1;
	int id = get_id(game);

	char substr[20];
	int substr_index = 0;
	int len = strlen(buf);
	char color[10];
	int color_number;
	for(int i = start; i <=len; i++)
	{
	  if(buf[i] == ',')
	  {
		substr[substr_index] = '\0';
	  }
	  else if(buf[i] == ';')
	  {
		substr[substr_index] = '\0';
	  }
	  else if(buf[i] == '\0')
	  {
		substr[substr_index] = '\0';
		substr_index++;
	  }
	  else
	  {
		substr[substr_index] = buf[i];
		substr_index++;
		continue;
	  }

	  substr_index= 0;

	  get_cube(substr,color,&color_number);


	  if(strcmp(color,"red") == 0)
	  {
		cube.red -= color_number;
	  }
	  else if(strcmp(color,"green") == 0)
	  {
		cube.green -= color_number;
	  }
	  else if(strcmp(color,"blue") == 0)
	  {
		cube.blue -= color_number;
	  }

	  if(cube.red < 0 || cube.blue < 0 || cube.green < 0)
	  {
		id = 0;
	  }

	  if(buf[i] == ';' || buf[i] == '\0'  || buf[i] == '\n')
	  {
		printf("->>>>>>red: %d, blue:%d, green:%d\n",cube.red,cube.blue,cube.green);
		//reset for next game
		cube.red =12;
		cube.green = 13; 
		cube.blue = 14;
		substr[0] = '\n';
	  }
	}

	printf("Id = %d \n",id);


	sum += id;


  }
  printf("Part 1 results: %d\n",sum);
}

void part_two(FILE *f)
{
}

int main()
{
  char part;
  printf("day2,parts 1 or 2. Which part do you want to run?");
  part = getchar();

  if(part != '1' && part != '2')
  {
	printf("invalid part");
	return 1;
  }

  FILE *f;
  f = fopen("input.txt","r");
  if(f == NULL)
  {
	printf("could not open");
	return 1;
  }
  if(part == '1')
  {
	part_one(f);
  }
  else if(part == '2')
  {
	part_one(f);
  }

  fclose(f);
  return 0;
}
