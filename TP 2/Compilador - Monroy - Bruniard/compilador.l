%{
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "compilador.tab.h"

void yyerror(const char*);
int yyparse(void);

void errorMaximosCaracteres();
void errorLexico();


%}

%option yylineno
%option noyywrap

espacio [\t\n]+
digito [0-9]
letra [a-zA-Z]
constante {digito}+
identificador {letra}({digito}|{letra})*
suma \+
resta -
asignacion :=
paren_IZQ \(
paren_DER \)
%%

{constante}				{yylval.int_val=atoi(yytext); return CONSTANTE;}; //Debo guardar el valor para poder acceder deste YACC
inicio 						return INICIO;
fin 						return FIN;
leer 						return LEER;
escribir 					return ESCRIBIR;
{identificador}				{
							yylval.str_val=strdup(yytext);
							if(strlen(yylval.str_val)>32)
							errorMaximosCaracteres();
							return IDENTIFICADOR;
							}; // Debo guardar el valor, para poder acceder desde YACC, además se realiza la comprobación de longitud.
{asignacion}				return ASIGNACION;
{suma}						{yylval.str_val=strdup(yytext); return SUMA;}
{resta}						{yylval.str_val=strdup(yytext); return	RESTA;}				
{paren_IZQ}					{yylval.str_val=strdup(yytext); return PAREN_IZQ;}
{paren_DER}					{yylval.str_val=strdup(yytext); return PAREN_DER;}
	;						{yylval.str_val=strdup(yytext); return PUNTOYCOMA;}
		,					{yylval.str_val=strdup(yytext); return COMA;}
"//".*						; //Ignora comentarios
.							{errorLexico();};
{espacio}					; //Ignorar espacios
%%

void errorMaximosCaracteres()
{
printf("\nERROR: El identificador sobrepasa la cantidad máxima de caracteres en la linea %d. Presione una tecla para salir.",yylineno);
getche();
exit(0);
}


void errorLexico()
{
printf("\nError lexico en linea %d. Presione una tecla para salir",yylineno);
getche();
exit(0);
}

