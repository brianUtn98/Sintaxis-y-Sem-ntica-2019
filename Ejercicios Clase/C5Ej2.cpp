#include<stdio.h>
#include<conio.h>

void suma(int x,int y,int *res)
{
*res=x+y;
}

int main()
{
int num1,num2,res;

printf("\nIngrese un numero: ");
	scanf("%d",&num1);
	printf("\nIngrese otro numero: ");
	scanf("%d",&num2);
	suma(num1,num2,&res);
	printf("La suma es : %d",res);
return 0;
}
