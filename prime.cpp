#include<stdio.h>
#include<conio.h>
int prime(int);
int main()
{
	int num, x;
	printf ("Enter a number :");
	scanf("%d",&num);
	x=prime(num);
	if(x==1)
	{
		printf("It is a prime number\n\n");
	}
	else
	{
		printf("It is not a prime number\n\n");
	}
	main();
	getch();
	return 0;
}
int prime(int num)
{
    int ans=1;

	for(int i = 2; i <= num/2; i++)
	{
		if(num % i == 0)
        {
			ans = 0;
            break;
        }	
	}

        return ans;


}
