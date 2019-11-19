#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
char str1[20+1],str2[20+1],str3[20+1],str4[20+1];
int i=0,l;


 	if(((strlen(argv[1]))==(strlen(argv[2]))) && strlen(argv[1])<21)
	{ 
	strcpy(str1,argv[1]);
	strcpy(str2,argv[2]);
	printf("Cadena 1: %s",str1);
	printf("\nCadena 2: %s",str2);
	printf("\n%d",strlen(str1));
	printf("\n%d\n",strlen(str2));	
 	l=strlen(str1);
						  for(i=0;i<l;i++)
						  {
					  	  str3[i]=str1[i]+str2[i];
					  	  str4[i]=str3[i]-str2[i];
							}
					  	  printf("\nCadena encriptada: ");
						  for(i=0;i<l;i++)
					  	  printf("%c",str3[i]);
					  	  printf("\nCadena desencriptada: ");
					  	  for(i=0;i<l;i++)
					  	  printf("%c",str4[i]);
					  	  
	
	}
	else
	printf("\n Las cadenas deben tener la misma longitud o menor a 20.");

return 0;
}
