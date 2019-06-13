#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/*
Encontrar la cantidad de veces que aparece una palabra dada, en un archivo de texto.
*/
int main()
{
FILE *f;
char str[20],palabra[20];
int contador=0,contadorTotal=0;
printf("Ingrese la palabra que desea contar: ");
scanf("%s",&palabra);
        f=fopen("ArchivoTexto.dat","r");
        fscanf(f,"%s",&str);
            while(!feof(f))
            {
                if(strcmp(str,palabra)==0)
                contador++;
                contadorTotal++;
            fscanf(f,"%s",&str);
            }
        printf("\n El archivo de texto contiene la palabra '%s' %d veces entre %d palabras",palabra,contador,contadorTotal);
        fclose(f);

}
