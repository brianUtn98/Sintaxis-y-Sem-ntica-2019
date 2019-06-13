#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
FILE *f1,*f2;
char buffer,letra,reemplazo;

    printf("Ingrese la letra que desea reemplazar: ");
    letra=getche();
    printf("\nIngrese la letra nueva: ");
    reemplazo=getche();

    f1=fopen("In.dat","r");
    f2=fopen("Out.dat","w");
        while(fscanf(f1,"%c",&buffer) != EOF)
        {
            if(buffer==letra)
                fprintf(f2,"%c",reemplazo);
            else
                fprintf(f2,"%c",buffer);
        }
return 0;
}
