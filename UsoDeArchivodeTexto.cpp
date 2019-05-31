#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
FILE* f;
char str[100];

f=fopen("UsoDeArchivoDeTexto.txt","a");

if(f)
{
 do
 {
 printf("Ingrese un texto: ");
 gets(str);
 if(strcmp(str,"0")!=0)
 fprintf(f,"%s\n",str);

 }
 while(strcmp(str,"0")!=0);
  fclose(f);
}
else
return 1;




return 0;
}
