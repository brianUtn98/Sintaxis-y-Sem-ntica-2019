#include<stdio.h>
#include<math.h>

int main()
{
float x1,x2,a,b,c,aux1,aux2;

printf("Ingrese los coeficientes de un polinomio de segundo grado.\n");
printf("a: ");
scanf("%f",&a);
printf("\nb: ");
scanf("%f",&b);
printf("\nc: ");
scanf("%f",&c);
aux1=pow(b,2);
aux2=4*a*c;
if(aux1>=aux2)
{
 x1=((-1)*b+sqrt(pow(b,2)-(4*a*c)))/(2*a);
 x2=((-1)*b-sqrt(pow(b,2)-(4*a*c)))/(2*a);
 										  if(x1==x2)
										  printf("\nLa funcion tiene una raiz doble en x= %f ",x1);
										  else
										  printf("\nLa funcion tiene raices en x= %f y x=%f",x1,x2);
}
else
	printf("\nEl polinomio no tiene raices reales.\n");
return 0;	
}
