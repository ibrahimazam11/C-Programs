#include<stdio.h>
#include<conio.h>
int main()
{
	char x;
	printf("Enter an alphabet:");
	scanf("%c",&x);
	switch(x)
	{
		case 'A':
		case 'a': printf("\nIt is a vowel");break;
		case 'E':
		case 'e': printf("\nIt is a vowel");break;
		case 'I':
		case 'i': printf("\nIt is a vowel");break;
		case 'O':
		case 'o': printf("\nit is a vowel");break;
		case 'U':
		case 'u': printf("\nIt is a vowel");break;
		default: printf("it is a consonant");
	}
		getch();
		return 0;
}
