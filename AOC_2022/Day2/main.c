#include <stdio.h>

//Part 1
//(1 for Rock, 2 for Paper, and 3 for Scissors)
//plus the score for the outcome of the round 
//(0 if you lost, 3 if the round was a draw, and 6 if you won).
const int MAP[3][3] = {
  //self Rock,Paper,Scisor
  {4,8,3},//oponent Rock
  {1,5,9},//o Paper
  {7,2,6},//o Scisor
};


int hand_value(char hand)
{
  int value=0;
  if(hand == 'A' || hand == 'X')
  {
    value = 0;
  }
  else if(hand == 'B' || hand == 'Y')
  {
    value = 1;
  }
  else if(hand == 'C' || hand == 'Z')
  {
    value = 2;
  }
  return value;
}

//Part 2
//X means you need to lose,
//Y means you need to end the round in a draw,
//and Z means you need to win. Good luck!"
const int MAPRESULT[3][3] = {
  //lose,draw,win
  {3,4,8},//Rock
  {1,5,9},//Paper
  {2,6,7},//Scisor
};

int hand_value_result(char hand)
{
  int value = hand == 'X' ? 0 : hand =='Y' ? 1 : 2;
  return value;
}

void part_two(FILE *f)
{
  char round[5];
  int op, self;
  int score = 0;
  while(fgets(round,5,f))
  {
    op = hand_value(round[0]);
    self = hand_value_result(round[2]);
    //printf("op: %c , self: %c , => %d\n",round[0],round[2],MAPRESULT[op][self]);
    score += MAPRESULT[op][self];
  }

  printf("your score is %d.\n",score);
  //your score is 12316.
}

void part_one(FILE *f)
{
  char round[5];
  //A X -> Rock
  //B Y -> Paper
  //C Z -> Scisor
  int op, self;
  int score = 0;
  while(fgets(round,5,f))
  {
    op = hand_value(round[0]);
    self = hand_value(round[2]);
    score += MAP[op][self];
  }

  printf("your score is %d.\n",score);
  //your score is 13809.
}

int main()
{
  FILE *f = fopen("input.txt","r");

  char c;

  printf("for part 1 type a for part 2 type b: ");
  c = getchar();

  if(c != 'a' && c != 'b')
  {
    printf("invalid option\n");
    return 0;
  }

  printf("Calculating...\n");
  if(c == 'a')
  {
    part_one(f);
  }
  else 
  {
    part_two(f);
  }

  fclose(f);
  return 0;
}
