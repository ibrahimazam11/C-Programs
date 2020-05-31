#include<stdio.h>
#include<conio.h>
int main(){
	int num, power, ans=1;
	printf("Enter a number :");
	scanf("%d",&num);
	printf("Enter power :");
	scanf("%d",&power);
	while(power>0){
		ans=ans*num;
		power--;
	}
	printf("Answer =%d",ans);
	return 0;
	getch();
	}
