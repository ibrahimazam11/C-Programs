#include<stdio.h>
#include<conio.h>
void letusc(int*);
int main()
{
	int x=5;
	letusc(&x);
	
	printf("\n%d",&x);
	
	printf("\n%d",x);
	getch();
	
	return 0;
}


void letusc(int *y)
{
	printf("%d\n",&y);
	printf("%d\n",y);
	printf("%d\n",*y);
}
