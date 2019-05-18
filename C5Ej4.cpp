#include<conio.h>
#include<stdio.h>
#define tam 5
int mayorDelVector(int[],int*);

int main()
{
int i=0,posicion=0,vector[tam],mayor=0;

	for(i=0;i<tam;i++)
	{
	printf("\nInserte el numero [%d]: ",i+1);
	scanf("%d",&vector[i]);
	}
	mayor=mayorDelVector(vector,&posicion);
	printf("\nEl mayor es: %d y esta en la posicion %d",mayor,posicion+1);
return 0;
}

int mayorDelVector(int vector[],int *posicion)
{
int i=0,mayor=0;
mayor=vector[0];
	for(i=0;i<tam;i++)
	{
 	 if(vector[i]>mayor)
  	 {
  	 mayor=vector[i];
  	 *posicion=i;
   	 }
	}
return mayor;
}
