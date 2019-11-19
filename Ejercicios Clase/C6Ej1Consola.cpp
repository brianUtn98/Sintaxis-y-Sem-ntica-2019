#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(int argc,char *argv[])
{
FILE* f;
int i,contador=0;
char buffer[100];

		   f=fopen(argv[2],"r");
		   while(!feof(f))
		   {
	   	   				  fscanf(f,"%s",&buffer);
	   	   				  if(strcmp(buffer,argv[1])==0)
	   	   				  {
	   	   				  printf("\n %s",buffer);
	   	   				  contador++;
		   				  }
		   }
		   fclose(f);
		   printf("\n La cantidad de veces que aparece la palabra %s es %d",argv[1],contador);


return 0;
}
