#include<stdio.h>
#include<conio.h>
int main()
{
      int subject1,subject2,subject3,obtainedmarks,maximummarks=300;
      float percentage;
      printf("enter the marks of 1st subject=");
      scanf("%d",&subject1);
      printf("enter the marks of 2nd subject=");
      scanf("%d",&subject2);
      printf("enter the marks of 3rd subject=");
      scanf("%d",&subject3);
      obtainedmarks=subject1+subject2+subject3;
      printf("obtained marks=%d out of 300",obtainedmarks);
      percentage=(obtainedmarks*100)/maximummarks;
      printf("\npercentage =%f",percentage);
      getch(); 
      return 0;
      }
