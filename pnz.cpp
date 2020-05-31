#include<stdio.h>
#include<conio.h>
int main()
{
	int num, n=0, p=0, z=0;
	for(;;)
	{
	printf("Enter a number(enter 101 to stop):");
	scanf("%d",&num);
	if(num==101)
	{
		break;
	}
	if(num>0)
	{
		p++;
	}
	if(num<0)
	{
		n++;
	}
	if(num==0)
	{
		z++;
	}
    }
    printf("Positive numbers : %d \nNegative Numbers : %d \nZeros : %d", p,n,z);
    getch();
    return 0;
    
}
