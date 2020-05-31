#include<stdio.h>
#include<conio.h>
void peravg(int,int,int,float *,float*);
int main()
{
	int a,b,c;
	float avg, per;
	printf("Enter marks of three subjects:");
	scanf("%d %d %d",&a,&b,&c);
	
	peravg(a,b,c,&avg,&per);
	printf("percentage= %f",per);
	printf("\naverage= %f",avg);
	getch();
	return 0;
}
void peravg(int a, int b, int c, float *avg, float *per)
{
    int x;
    x=a+b+c;
    *avg=x/3;
    *per=(x*100)/300;
    
}
