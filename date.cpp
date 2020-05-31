#include<stdio.h>
#include<conio.h>
struct date
{
	int date;
	int month;
	int year;
};
int main()
{
	struct date s1,s2;
	printf("Enter date:");
	scanf("%d %d",&s1.date,&s2.date);
	printf("Enter month:");
	scanf("%d %d",&s1.month,&s2.month);
	printf("Enter year:");
	scanf("%d %d",&s1.year,&s2.year);
	if(s1.date==s2.date && s1.month==s2.month && s1.year==s2.year)
	{
		printf("Equal");
		
	}
	else
	{
		printf("Unequal");
		
	}
	
	getch();
	return 0;
}
