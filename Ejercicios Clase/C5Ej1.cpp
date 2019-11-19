#include<stdio.h>
#include<conio.h>

int suma(int x,int y)
{
return x+y;
}

int main()
{
int num1=0,num2=0,res=0;

	printf("\nIngrese un numero: ");
	scanf("%d",&num1);
	printf("\nIngrese otro numero: ");
	scanf("%d",&num2);
	res=suma(num1,num2);
	printf("La suma es : %d",res);
return 0;
}
