#include<stdio.h>
#include<conio.h>
int main()
{
    
    int j,k=2;    
    printf("Input a positive number: ");    
    scanf("%d",&j);
     printf("\nPrime factors : ",j);
     
    for(;j!=0;)
	{
    
        if(j%k!=0)
		{
            k=k++;
		}
        else 
		{
            j= j/k;
            printf("%d ",k);
        }
            if(j==1)
                break;
    }
    
    getch();
    return 0;
}


