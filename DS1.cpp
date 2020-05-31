#include<stdio.h>
#include<conio.h>
void question1(void);
int main()
{
	printf("kdhvds");
	getch();
	question1();
	
	getch();
	return 0;
}


void question1(void)
{
	int x=0,set1[x];
	int set2[x];
	printf("Enter number of elements 1st set :");    
	scanf("%d",&x);
	printf("Enter elements of set i\n");
	for(int count=0;count<x;count++)
	{
		scanf("%d",&set1[count]);
	}
	
	printf("Elements of set 1\n{");
	
	for(int count=0;count<x;count++)
    {
		printf("%d,",set1[count]);
		
    }
	
	printf("}");
	
	printf("\n\nEnter number of elements in 2nd set :");
	scanf("%d",x);
	
	for(int count=0;count<x;count++)
	{
		scanf("%d",&set2[count]);
	}
	
	for(int count=0;count<x;count++)
	{
		printf("%d",set2[count]);
	}

}









