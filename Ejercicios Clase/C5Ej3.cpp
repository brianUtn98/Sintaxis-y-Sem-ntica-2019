#include<stdio.h>
#include<conio.h>
int n=0,fact=1;

int factorialDe(int x)
{
int i=0,fact=1;
	for(i=x;i>0;i--)
	fact=i*fact;
return fact;
}

int factorialRecursivoDe(int x)
{
	if(x==1 || x==0)
	return 1;
	else
	return x*factorialRecursivoDe(x-1);
	
}

int main()
{
int n=0,fact=1;
	do
	{
	printf("\nIngrese un numero: ");
	scanf("%d",&n);
	if(n>=0)
	{
	fact=factorialDe(n);
	printf("El factorial de %d es: %d ",n,fact);
	fact=factorialRecursivoDe(n);
	printf("\nEl factorial recursivo de %d es: %d ",n,fact);
	}
	else
	printf("\nLa funcion factorial no esta definida para numeros negativos.");
	}
	while(n!=-1);
return 0;
}
