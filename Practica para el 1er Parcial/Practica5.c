#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
/*
Dado un archivo de texto, crea uno nuevo cambiando todas las letras 'a' por 'e'.
*/
int main()
{
FILE *f1,*f2;
    f1=fopen("In.dat","r");
    f2=fopen("Practica5.dat","w");
char c;
    while((c=fgetc(f1)) != EOF )
        {
        if(c=='a')
            fprintf(f2,"e");
        else
            fprintf(f2,"%c",c);
        }
return 0;
}
