#include <stdio.h>

void read_and_print()
{
   FILE* ptr;
   char ch;

   // Opening file in reading mode
   ptr = fopen("input.txt", "r");

   if (NULL == ptr) {
      printf("file can't be opened \n");
   }

   printf("content of this file are \n");

   // Printing what is written in file
   // character by character using loop.
   do {
      ch = fgetc(ptr);
      printf("%c", ch);

      // Checking if character is not EOF.
      // If it is EOF stop reading.
   } while (ch != EOF);

   // Closing the file
   fclose(ptr);
}

int main()
{
   read_and_print();
   return 0;
}
