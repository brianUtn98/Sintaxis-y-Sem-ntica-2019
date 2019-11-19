#include<stdio.h>

int main()
{
float numero,potencia=1;
int i=0,exponente,aux;

	printf("Ingrese el numero: ");
	scanf("%f",&numero);
	printf("\nIngrese el exponente: ");
	scanf("%d",&exponente);
	if(numero==0 && exponente<0)
	{
	printf("No hay potencia negativa de 0, ya que no se puede dividir por cero.");
	}
	else
	{
	if(exponente<0)
	aux=(-1)*exponente;
	else
	aux=exponente;
	
	for(i=0;i<aux;i++)
	{
	potencia=potencia*numero;
	}
	if(exponente<0)
	potencia=1/potencia;
	
	printf("La potencia %d del numero %f es: %f",exponente,numero,potencia);
	}

return 0;
}
