#include<stdio.h>
#include<conio.h>
int intsum(int,int,int,int,int);
int main()
{
	int i,j,k,l,m,n;
	printf("Input number 1 :");
	scanf("%d",&i);
	printf("\nInput number 2 :");
	scanf("%d",&j);
	printf("\nInput number 3 :");
	scanf("%d",&k);
	printf("\nInput number 4 :");
	scanf("%d",&l);
	printf("\nInput number 5 :");
	scanf("%d",&m);
	n=intsum(i,j,k,l,m);
	printf("\nAverage of the 5 numbers is : %d",n);
	getch();
	return 0;
}
int intsum(int i,int j,int k,int l,int m)
{
	int x;
	x=i+j+k+l+m;
	printf("\nSum of 5 numbers is : %d",x);
	x=x/5;
	return(x);
}
