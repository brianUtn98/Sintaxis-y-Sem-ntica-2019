#include<stdio.h>
#include<conio.h>

int main()
{
float a1,b1,a2,b2,x,y;
int repetir=1;
char rta;

	  do
	  {
	printf("\nIngrese la pendiente de la recta 1, seguido la ordenada de la recta 1: ");
	scanf("%f",&a1);
	scanf("%f",&b1);
	
	printf("\nIngrese la pendiente de la recta 2, seguido la ordenada de la recta 2: ");
	scanf("%f",&a2);
	scanf("%f",&b2);
	
	

	if(a1==a2)
	{
 	 		  if(b1==b2)
 	 		  	printf("Son rectas coincidentes, por lo tanto la solucion son todos los puntos de la recta.\n");
				else
				printf("Son rectas paralelas no coincidentes y no tienen ningun punto en comun.\n");
				

	}
	else
	{
	x=(b2-b1)/(a1-a2);
	y=x*a1+b1;
	printf("\nEl punto de interseccion es  P=(%f,%f )\n",x,y);	
	}
	
	printf("Desea ingresar otro par de rectar? (S/N): ");
	
	scanf("%s",&rta);
	
	if(rta=='n' || rta=='N')
				repetir=0;

	}	
	while(repetir);
return 0;
}


