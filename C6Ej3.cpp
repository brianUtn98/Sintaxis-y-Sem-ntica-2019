#include<stdio.h>
#include<conio.h>
#include<string.h>

void intercalarArchivos(FILE*,FILE*,FILE*);

int main(int argc,char *argv[])
{
FILE *f1,*f2,*f3;

f1=fopen(argv[1],"r");
f2=fopen(argv[2],"r");
f3=fopen(argv[3],"a");
intercalarArchivos(f1,f2,f3);		  
return 0;
}

void intercalarArchivos(FILE *in1,FILE *in2,FILE *out)
{
char buffer1,buffer2;
buffer1=getc(in1);
buffer2=getc(in2);
while((!feof(in1))&&(!feof(in2)))
{
fprintf(out,"%c",buffer1);	
fprintf(out,"%c",buffer2);
buffer1=fgetc(in1);
buffer2=fgetc(in2);
}
// Caso Cerrado el 2
while(!feof(in1))
{
fprintf(out,"%c",buffer1);
fprintf(out,"*");
buffer1=fgetc(in1);
}
// Caso Cerrado el 1
while(!feof(in2))
{
fprintf(out,"*");
fprintf(out,"%c",buffer2);
buffer2=fgetc(in2);
}

fclose(in1);
fclose(in2);
fclose(out);
return;
}
