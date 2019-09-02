#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
/*
Dadas dos cadenas, encripta la primera sumandole caracter por caracter la segunda.
*/
int main()
{
int i=0;
char str1[20],str2[20];
strcpy(str1,"Hola Jorge");
strcpy(str2,"Hola Brian");
    printf("Cadena sin encriptar: %s",str1);
    printf("\nSe va a encriptar con: %s",str2);
    for(i=0;i<strlen(str1);i++)
        str1[i]+=str2[i];
    printf("\nCadena encriptada: %s",str1);

    for(i=0;i<strlen(str1);i++)
        str1[i]-=str2[i];
    printf("\nCade desencriptada: %s",str1);
return 0;
}
