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
%%

[0-9][0-9]*					{yylval.int_val=atoi(yytext); return CONSTANTE;}; //Debo guardar el valor para poder acceder deste YACC
"inicio" 					return INICIO;
"fin" 						return FIN;
"leer" 						return LEER;
"escribir" 					return ESCRIBIR;
[a-zA-Z][a-zA-Z0-9]* 		{
							strcpy(yylval.str_val,yytext);
							if(strlen(yylval.str_val)>32)
							errorMaximosCaracteres();
							return IDENTIFICADOR;
							}; // Debo guardar el valor, para poder acceder desde YACC, además se realiza la comprobación de longitud.
":="						return ASIGNACION;
"+"							return SUMA;
"-"							return	RESTA;					
"("							return PAREN_IZQ;
")"							return PAREN_DER;
";"							return PUNTOYCOMA;
","							return COMA;
"//".*						;
.							{errorLexico();};
[ \t\n]+					; //Ignorar espacios
%%

void errorMaximosCaracteres()
{
printf("\nEl identificador sobrepasa la cantidad máxima de caracteres en la linea %d",yylineno);
}


void errorLexico()
{
printf("\Error lexico en linea %d",yylineno);
}

