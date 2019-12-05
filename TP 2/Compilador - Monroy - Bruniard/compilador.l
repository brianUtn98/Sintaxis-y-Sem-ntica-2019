%{
#include <string.h>
#include "y.tab.h"
%}

%{
	/*
	Declaraciones l�xicas
	*/

%}

%opcion yylineno

%%

[0-9][0-9]*					{yyval.int_val=atoi(yytext); return CONSTANTE;}; //Debo guardar el valor para poder acceder deste YACC
"inicio" 					return INICIO;
"fin" 						return FIN;
"leer" 						return LEER;
"escribir" 					return ESCRIBIR;
[a-zA-Z][a-zA-Z0-9]* 		{
							yyval.str_val=new string(yytext);
							if(yyval.str_val->length()>32)
							errorMaximosCaracteres();
							return IDENTIFICADOR;
							}; // Debo guardar el valor, para poder acceder desde YACC, adem�s se realiza la comprobaci�n de longitud.
":="						return ASIGNACION;
"+"							return SUMA;
"-"							return RESTA;
"*"							return PRODUCTO;
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
printf("\nEl identificador sobrepasa la cantidad m�xima de caracteres en la linea %d",yylineno);
}

void errorLexico()
{
printf("\Error lexico en linea %d"yylineno);
}