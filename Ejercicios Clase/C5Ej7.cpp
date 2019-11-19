#include<stdio.h>
#include<conio.h>

int fibonacci(int);

int main()
{
int n=0,f=0;
	do
	{
	printf("\nIngrese un numero: ");
	scanf("%d",&n);
f=fibonacci(n);
printf("\nEl fibonacci de %d es: %d",n,f);
			 
			 }
			 while(n>=0);
return 0;
}

int fibonacci(int n)
{
if(n==1 || n==0)
return n;
else
return fibonacci(n-2)+fibonacci(n-1);
}
