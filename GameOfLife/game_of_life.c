#include <stdio.h>
#include <stdlib.h>

int SIZE = 10;
char alive = 'o';
char dead = ' ';

void draw_break();

void free_matrix(char **matrix);

char** get_matrix(int rows, int cols,char fill);

void draw(char **matrix, char numbers);

void get_value(char status, int *value);

int calculate_neighbors(char **matrix, int x, int y);

char cell_run_rule(char **matrix, int x, int y);

void run(char **matrix,char **copy);

int main()
{
  char **matrix = get_matrix(SIZE,SIZE,dead);
  char **copy = get_matrix(SIZE,SIZE,dead);

  matrix[3][4] = alive;
  matrix[4][3] = alive;
  matrix[4][4] = alive;
  matrix[4][5] = alive;

  draw(matrix,'n');
  
  for(int i = 1; i <= 10; i++)
  {
    printf("round: %d",i);
    run(matrix,copy);
    draw(matrix,'n');
  }


  free_matrix(matrix);
  free_matrix(copy);
  return 1;
}



//x & y are cordinates to a cell
//updates the cell status based on the rules
char cell_run_rule(char **matrix, int x, int y)
{
  int lived_neighbors = calculate_neighbors(matrix, x, y);
  char status = matrix[x][y];
  //dead cell
  if(status == alive)
  {
    //Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    if(lived_neighbors < 2)
    {
      return dead;
    }

    //Any live cell with more than three live neighbours dies, as if by overpopulation.
    if( lived_neighbors > 3)
    {
      return dead;
    }
    //Any live cell with two or three live neighbours lives on to the next generation.
    //nothing to check
  }
  else 
  {
    //Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction 
    if(lived_neighbors == 3)
    {
      return alive;
    }
    
  }
  return matrix[x][y];
}

void run(char **matrix, char **copy)
{
  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      char result = cell_run_rule(matrix,i,j);
      copy[i][j] = result;
    }
  }

  //copy results back to the original matrix
  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      matrix[i][j] = copy[i][j];
    }
  }
}


void draw_break()
{
  printf("\n");
}

char** get_matrix(int rows, int cols,char fill) 
{ 
  char **matrix;
  matrix = malloc(sizeof(char *) * rows);

  for(int i = 0; i < rows; i++)
  {
    matrix[i] = malloc(sizeof(char) * cols);
  }

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      matrix[i][j] = fill;
    }
  }
  return matrix;
}

void draw(char **matrix, char numbers)
{
  draw_break();
  int len = 10;
  for(int i = 0; i < len; i++)
  {
    for(int j = 0; j < len; j++)
    {
      if(numbers == 'y')
      {
        printf("%2d",matrix[i][j]);
      }
      else 
      {
        printf("%2c",matrix[i][j]);
      }
    }
    draw_break();
  }
  
  draw_break();
  draw_break();
};


//returns number of live neighbors, given a cell cordinate
int calculate_neighbors(char **matrix, int x, int y)
{
  int size = SIZE;
  int left = x-1;
  int right = x+1;
  int up = y+1;
  int down = y-1;

  int live_neighbors = 0;

  //xxx
  //xox
  //xxx
  //safe to calculate all 8 neighbors
  if(left >= 0 && up >= 0 && right < size && down < size)
  {
    get_value(matrix[left][y-1],&live_neighbors);
    get_value(matrix[left][y] ,&live_neighbors);
    get_value(matrix[left][y+1] ,&live_neighbors);

    get_value(matrix[x][up] ,&live_neighbors);
    get_value(matrix[x][down] ,&live_neighbors);

    get_value(matrix[right][y-1] ,&live_neighbors);
    get_value(matrix[right][y] ,&live_neighbors);
    get_value(matrix[right][y+1] ,&live_neighbors);
    return live_neighbors;
  }

  //xxx
  //oxx
  //xxx
  //no room on the left but yes on top
  if(left < 0 && up >=0)
  {
    get_value(matrix[x][y+1],&live_neighbors);
    get_value(matrix[x][y-1],&live_neighbors);
    get_value(matrix[right][y-1],&live_neighbors);
    get_value(matrix[right][y],&live_neighbors);
    get_value(matrix[right][y+1],&live_neighbors);
    return live_neighbors;
  }

  //oxx
  //xxx
  //xxx
  //no room on the Left and Up
  if(left < 0 && up < 0)
  {
    get_value(matrix[x][y-1],&live_neighbors);
    get_value(matrix[right][y],&live_neighbors);
    get_value(matrix[right][y+1],&live_neighbors);
    return (char)live_neighbors;
  }

  //xxx
  //xxx
  //oxx
  //no room on the Left and Down
  if(left < 0 && up < 0)
  {
    get_value(matrix[x][y+1] ,&live_neighbors);
    get_value(matrix[right][y-1] ,&live_neighbors);
    get_value(matrix[right][y] ,&live_neighbors);
    return (char)live_neighbors;
  }

  //xxo
  //xxx
  //xxx
  //no room on the Left and Down
  if(right >= size && up < 0)
  {
    get_value(matrix[left][y] ,&live_neighbors);
    get_value(matrix[left][y-1] ,&live_neighbors);
    get_value(matrix[x][y+1] ,&live_neighbors);
    return (char)live_neighbors;
  }

  //xxx
  //xxo
  //xxx
  //no room on the Left and Down
  if(right >= size && up >= 0)
  {
    get_value(matrix[left][y+1] ,&live_neighbors);
    get_value(matrix[left][y] ,&live_neighbors);
    get_value(matrix[left][y-1] ,&live_neighbors);

    get_value(matrix[x][y+1] ,&live_neighbors);
    get_value(matrix[x][y-1] ,&live_neighbors);
    return (char)live_neighbors;
  }

  //xxx
  //xxx
  //xxo
  //no room on the Left and Down
  if(right >= size && down >= size)
  {
    get_value(matrix[left][y+1] ,&live_neighbors);
    get_value(matrix[left][y] ,&live_neighbors);
    get_value(matrix[x][y-1] ,&live_neighbors);
    return (char)live_neighbors;
  }

  return 'e';
}

void get_value(char status, int *value)
{
  (*value) += status == alive ? 1 : 0;
}

void free_matrix(char **matrix)
{
  for(int i = 0; i < SIZE; i++)
  {
    free(matrix[i]);
  }
  free(matrix);
}

