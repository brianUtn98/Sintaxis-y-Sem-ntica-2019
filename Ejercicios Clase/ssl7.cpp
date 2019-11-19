#include<stdio.h>

int main()
{
float numero,maximo=0,promedio,acumulador=0;
int i,contador=0,juego,nroValor;

	for(i=1;i<=5;i++)
	{
	 juego=i;
	 nroValor=0;
	 maximo=0;
		do
		{
		
	 	  	 do
	 	  	 {
 	  	 	 printf("Ingrese el valor [%d] del juego [%d]: ",nroValor+1,juego);
 	  	 	 scanf("%f",&numero);
			 }
			 while(numero<=0 && numero!=-1);
 		 if(numero!=-1)
 		 {	
 		 	if(numero>maximo)
 		 	maximo=numero;
 		 	
 		 	acumulador+=numero;
 		 	contador++;
 		 	nroValor++;
 		 	
		 	
 		 	
 		 	
		  }
		}
		while(numero!=-1);
		printf("\nEl maximo del juego %d es: %f \n",juego,maximo);
	}
	
	promedio=acumulador/contador;
	printf(" Acumulador: %f  contador: %d Promedio: %f",acumulador,contador,promedio);
	printf("El promedio es: %f",promedio);

return 0;
}
