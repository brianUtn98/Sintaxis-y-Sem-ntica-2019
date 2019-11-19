#include<conio.h>
#include<stdio.h>
#define tam 5
void sumarVectores(int[],int[],int[]);

int main()
{
int i=0,j=0,k=0,vector1[tam],vector2[tam],vectorResultado[tam];

	for(i=0;i<tam;i++)
	{
	printf("\nInserte el numero [%d] del vector 1: ",i+1);
	scanf("%d",&vector1[i]);
	}
	for(i=0;i<tam;i++)
	{
	printf("\nInserte el numero [%d] del vector 2: ",i+1);
	scanf("%d",&vector2[i]);
	}

sumarVectores(vector1,vector2,vectorResultado);
											   
printf("\nEl vector sumatoria es: ");	
			 for(i=0;i<tam;i++)
		 	 printf("%d ",vectorResultado[i]);
return 0;
}

void sumarVectores(int x[],int y[],int resultado[])
{
int i=0;
	for(i=0;i<tam;i++)
 	resultado[i]=x[i]+y[i];
}
