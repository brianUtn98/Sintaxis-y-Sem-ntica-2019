#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/*
Programa para leer un text file de Empleados. Calcular la cantidad total de sueldos a liquidar.
*/

int main(int argc,char *argv[])
{
FILE *f;
int dni=0,contador=0;
float sueldo=0,sumatoria=0;
char nombre[20],apellido[20],basura[20];
f=fopen("ArchivoEmpleados.dat","r");

            fscanf(f,"%s",&basura);
            fscanf(f,"%s",&basura);
            fscanf(f,"%s",&basura);
            fscanf(f,"%s",&basura);
            while(!feof(f))
            {
                fscanf(f,"%s",&nombre);
                fscanf(f,"%s",&apellido);
                fscanf(f,"%d",&dni);
                fscanf(f,"%f",&sueldo);

                printf("\nEmpleado %s %s Dni: %d , cobra %.2f",nombre,apellido,dni,sueldo);
                sumatoria+=sueldo;
                contador++;
            }
            printf("\nLa cantidad total a liquidar por el empleador es: %.2f, el promedio de sueldos es: %.2f",sumatoria,sumatoria/contador);
return 0;
}
