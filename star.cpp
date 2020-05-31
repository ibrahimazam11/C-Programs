#include<stdio.h>
#include<conio.h>
int main()
{
	int count,c;
	for(count=1;count<=3;count++)
	{
		for(c=1;c<=count;c++)
		{
			printf("*");
		}
		printf("\n");
	}
	getch();
	return 0;
}
