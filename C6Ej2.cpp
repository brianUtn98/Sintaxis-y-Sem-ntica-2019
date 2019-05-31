#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(int argc,char *argv[])
{
FILE* f,*f2;
int i,contador=0;
char buffer;
for(i=1;i<argc;i++)
printf("%s\n",argv[i]);

		   f=fopen(argv[3],"rw");
		   f2=fopen("C6Ej2Trans.txt","w");
		   while(!feof(f))
		   {
	   	   				  buffer=fgetc(f);
	   	   				  if(buffer==*argv[1])
	   	   				  fprintf(f2,"%c",*argv[2]);
		   				  else
		   				  fprintf(f2,"%c",buffer);
		   }
		   fclose(f);
		   fclose(f2);
		   printf("\n Se ha termiado la operacion" );


return 0;
}
