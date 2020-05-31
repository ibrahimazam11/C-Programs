#include<stdio.h>
#include<conio.h>
int main()
{
	int num=0, i=2;
	printf("Enter a Number:");
	scanf("%d",&num);
	while(i<=num)
	{
		printf("\n%d",i);
		i+=2;
	}
	getch();
	return 0;
}


