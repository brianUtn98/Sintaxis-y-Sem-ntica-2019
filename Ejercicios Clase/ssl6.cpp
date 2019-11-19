#include<stdio.h>

int main()
{
int numero,minimo,i;

	for(i=1;i<=10;i++)
	{
		printf("Ingrese el numero [%d]: ",i);
		scanf("%d",&numero);
		
		if(i==1)
		minimo=numero;
		
		if(numero<minimo)
		minimo=numero;
	}
	printf("El minimo es: %d",minimo);
return 0;
}
