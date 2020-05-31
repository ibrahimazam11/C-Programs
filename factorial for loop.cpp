#include<stdio.h>
#include<conio.h>
int main()
{
	int fact=1, num=0;
	printf("Enter a number to find factorial:");
	scanf("%d",&num);
	for(;num>0;num--)
	{
		fact=fact*num;
	
	}
	printf("factorial of %d=%d",num,fact);
	getch();
    return 0;
}
