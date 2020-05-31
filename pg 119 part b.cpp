#include<stdio.h>
#include<conio.h>
int main(){
	int x=0,y=1,z=1;
	printf("Enter a number :");
	scanf("%d",&x);
	while(y<=x){
		z=z*y;
		z<x;
		y=y+1;
	}
	if(z==0){
		printf("\nError");
}else
	printf("\nThe factorial of %d = %d",x,z);
	return 0;
	getch();
}
