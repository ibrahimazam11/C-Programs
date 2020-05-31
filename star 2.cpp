#include<stdio.h>
#include<conio.h>
int main()
{
	int i=4,j=1,s=1;
	while(i>=1)
	{
		s=1;
		while(s<=4-i)
		{
			printf(" ");
			s++;
		}
		j=1;
		while(j<=i)
		{
			printf("*");
			j++;
		}
		printf("\n");
		i--;
	}
	getch();
	return 0;
}
