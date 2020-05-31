#include<stdio.h>
#include<conio.h>
int main()
{
	int fact=1, num=0;
	printf("Enter a number to find factorial:");
	scanf("%d",&num);
	while(num>0)
	{
		fact=fact*num;
		num--;
	}
	printf("factorial=%d",fact);
	getch();
	return 0;
}
