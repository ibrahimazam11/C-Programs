#include<stdio.h>
#include<conio.h>
int main()
{
    
    int j,k;    
    printf("Input a positive number: ");    
    scanf("%d",&j);
     printf("\nThe prime factors of %d are: ",j);
    
    k= 2;
    
    while(j!=0)
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
