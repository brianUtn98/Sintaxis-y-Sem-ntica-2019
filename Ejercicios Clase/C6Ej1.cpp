#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(int argc,char *argv[])
{
FILE* f;
int i,contador=0;
char palabra[100];
char ruta[100];
char buffer[100];
printf("Ingrese una palabra a buscar: ");
gets(palabra);
printf("\nIngrese la ruta del archivo de texto: ");
gets(ruta);

		   f=fopen(ruta,"r");
		   while(!feof(f))
		   {
	   	   				  fscanf(f,"%s",&buffer);
	   	   				  if(strcmp(buffer,palabra)==0)
	   	   				  {
	   	   				  printf("\n %s",buffer);
	   	   				  contador++;
		   				  }
		   }
		   fclose(f);
		   printf("\n La cantidad de veces que aparece la palabra %s es %d",palabra,contador);


return 0;
}
