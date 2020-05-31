#include<stdio.h>
#include<conio.h>
int main(){
	int p=0, n=0, z=0, x=0;
	while(1)
	{
	printf("Enter a number (Enter 100 to exit):");
	scanf("%d",&x);

		if(x==100)
		{
			break;
		}
		else if(x>0)
		{
			p++;
		}
		else if(x<0)
		{
			n++;
		}
		else
		{
			z++;
		}
	}
	printf("%d Positive Number(s) \t %d Negative Number(s) \t %d Zero(s)",p,n,z);
	getch();
	return 0;
}
