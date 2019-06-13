#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(int argc,char *argv[])
{
FILE *fIn,*fOut;
char buffer;
	 if(argc<2)
	 return 1;
	 
	 fIn=fopen(argv[1],"r");
	 fOut=fopen(argv[2],"w");
	 
	 buffer=fgetc(fIn);
	 while(!feof(fIn))
	 {
	 	
 	 if(buffer=='a')
 	 fprintf(fOut,"e");
 	 else
 	 fprintf(fOut,"%c",buffer);
 	 
 	 buffer=fgetc(fIn);
	 }
	 
	 printf("\nSe termino la operacion");
	 
	 fclose(fIn);
	 fclose(fOut);
	 
return 0;
}
