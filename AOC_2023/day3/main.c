#include <stdio.h>

void part_one(FILE *f)
{
	char buf[200];
	while(fgets(buf,200,f))
	{
		printf("%s",buf);
	}
}

int main()
{
	FILE *f;
	f = fopen("test.txt","r");

	part_one(f);

	fclose(f);
	return 0;
}
