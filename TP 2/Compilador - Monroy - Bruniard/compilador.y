%{
	#include <string.h>
	#include <conio.h>
	#include <stdio.h>
	#include <stdlib.h>
	
	extern int yylineno;
	extern int yylex();
	extern void yyerror(const char*);
	int yywrap();
	typedef struct ElementoSimbolo{
	char id[32];
	int val;
	struct ElementoSimbolo *sgte;
	}Simbolo;
	
	typedef struct ElementovalorDeExpresiones{
	int valor;
	struct ElementovalorDeExpresiones *sgte;
	}valorDeExpresiones;
	

	
	valorDeExpresiones *valExpresiones=NULL;
	Simbolo *identificadores=NULL;
	Simbolo *tablaDeSimbolos=NULL;
	Simbolo *iniciarTS(Simbolo *);
	Simbolo *agregarSimbolo(Simbolo *,Simbolo*);
	Simbolo *agregarIdentificador(Simbolo *,char []);
	valorDeExpresiones *agregarValor(valorDeExpresiones*,int);
	Simbolo *buscarId(Simbolo *,char []);
	Simbolo *agregarSimbolos(Simbolo*,Simbolo*);
	Simbolo *asignarValorASimbolo(Simbolo*,char[],int);
	int identificadorCreado(Simbolo*,char[]);
	valorDeExpresiones *limpiarListaExpresiones(valorDeExpresiones*);
	int esPalabraReservada(char[]);
	void errorIdNoDeclarado(char[]);
	void errorPalabraReservada(char[]);
	
	
	int flagR=0,flagW=0;
	void cerrarPrograma();
	int idCreado;
	Simbolo *cursor=NULL;
	
	
%}

%union {
	int int_val;
	char str_val[32];
}

%token <int_val> INICIO FIN SUMA RESTA ASIGNACION PAREN_DER PAREN_IZQ PUNTOYCOMA LEER ESCRIBIR COMA CONSTANTE
%token <str_val> IDENTIFICADOR

%type <str_val> sentencia listaIdentificadores;
%type <int_val> expresion primaria1 primaria2 listaExpresiones;

%left SUMA RESTA

%start programa

%%
programa: INICIO {tablaDeSimbolos=iniciarTS(tablaDeSimbolos);} sentencias FIN{cerrarPrograma();};
sentencias: sentencia sentencias | sentencia;
sentencia: 	LEER {flagR==1;} PAREN_IZQ listaIdentificadores PAREN_DER PUNTOYCOMA {
	tablaDeSimbolos=agregarSimbolos(identificadores,tablaDeSimbolos);
	flagR=0;} |
			ESCRIBIR {flagW=1;} PAREN_IZQ listaExpresiones PAREN_DER PUNTOYCOMA {escribirExpresiones(valExpresiones);
			valExpresiones=limpiarListaExpresiones(valExpresiones);
			flagW=0;} |
			IDENTIFICADOR ASIGNACION expresion PUNTOYCOMA {asignarValorASimbolo(tablaDeSimbolos,$1,$2);};
listaExpresiones: 	expresion {if(flagW==1) valExpresiones=agregarValor(valExpresiones,$1);} COMA listaExpresiones {} |
					expresion {if(flagW==1) valExpresiones=agregarValor(valExpresiones,$1);};
listaIdentificadores: IDENTIFICADOR {if(flagR==1) identificadores=agregarIdentificador(identificadores,$1);} COMA listaIdentificadores |   IDENTIFICADOR {if(flagR=1) identificadores=agregarIdentificador(identificadores,$1);};
expresion:	expresion SUMA primaria1 {$$= $1 + $3;} |
			expresion RESTA primaria1 {$$= $1 - $3;} |
			primaria1 {$$=$1;};
primaria1:	primaria2 {$$ = $1;};

primaria2: 	IDENTIFICADOR{
			if((idCreado=identificadorCreado(tablaDeSimbolos,$1))==1)
			{
				if(idCreado=esPalabraReservada($1)==1)
				{
				errorPalabraReservada($1);
				}
				else
				{
				cursor=buscarId(tablaDeSimbolos,$1);
				$$=cursor->val;
				}
			}
			else
			errorIdNoDeclarado($1);
		
			} |
			CONSTANTE {$$ = $1;} |
			PAREN_IZQ expresion PAREN_DER {$$=$2;};
%%

void cerrarPrograma(){
printf("\n Se ha terminado la ejecución del programa exitosamente");
return 0;
}

Simbolo *iniciarTS(Simbolo *lista)
{
lista=NULL;
Simbolo *inicio,*fin,*leer,*escribir;
inicio=(Simbolo*) malloc (sizeof(Simbolo));
fin=(Simbolo*) malloc (sizeof(Simbolo));
leer=(Simbolo*) malloc (sizeof(Simbolo));
escribir=(Simbolo*) malloc (sizeof(Simbolo));

	strcpy(inicio->id,"inicio");
	strcpy(fin->id,"fin");
	strcpy(leer->id,"leer");
	strcpy(escribir->id,"escribir");
return lista;
}

Simbolo *agregarSimbolo(Simbolo *lista,Simbolo *nuevoSimbolo)
{
Simbolo *aux;
nuevoSimbolo->sgte=NULL;
	if(lista == NULL){
		lista=nuevoSimbolo;
	}
	else
	{
	aux=lista;
		while(aux->sgte != NULL){
			aux=aux->sgte;
		}
		aux->sgte=nuevoSimbolo;
	}
	return lista;
}
Simbolo *agregarSimbolos(Simbolo *lista,Simbolo *identificadores)
{
Simbolo *aux=identificadores;
int buffer;
	while(aux != NULL)
	{
	
	printf("Ingrese el valor de %s",aux->id);
	scanf("%d",&buffer);
	aux->val=buffer;
	lista=agregarSimbolo(lista,aux);
	aux=aux->sgte;
	}
	return lista;
}

Simbolo *agregarIdentificador(Simbolo *lista,char nombreId[])
{
Simbolo *nuevoIdentificador,*aux;
nuevoIdentificador=(Simbolo*) malloc (sizeof(Simbolo));
strcpy(nuevoIdentificador->id,nombreId);
nuevoIdentificador->val=-1; //-1 simboliza aún sin valor.
nuevoIdentificador->sgte=NULL;
aux=lista;
	
	if(lista==NULL)
	{
		lista=nuevoIdentificador;
	}
	else
	{
		while(aux->sgte != NULL)
		{
			aux=aux->sgte;
		}
		aux->sgte=nuevoIdentificador;
	}
	return lista;
}

Simbolo *asignarValorASimbolo(Simbolo *lista,char nombreId[],int val)
{
Simbolo *aux=NULL;
	aux=buscarId(lista,nombreId);
	aux->val=val;
return lista;
}

Simbolo *buscarId(Simbolo *lista,char nombreId[])
{
	while(lista->sgte!=NULL && strcmp(lista->id,nombreId)!=0)
	lista=lista->sgte;

	if(strcmp(lista->id,nombreId)==0)
	return lista;
	else
	return NULL;
}

int identificadorCreado(Simbolo *lista,char nombreId[])
{
	while(lista->sgte!= NULL && strcmp(lista->id,nombreId)!=0)
	lista=lista->sgte;

	if(strcmp(lista->id,nombreId)==0)
	return 1;
	else
	return 0;
}

valorDeExpresiones *limpiarListaExpresiones(valorDeExpresiones *lista)
{
valorDeExpresiones *aux=lista;
	while(lista != NULL)
	{
	aux=lista;
	lista=aux->sgte;
	free(aux);
	}
return lista;
}

valorDeExpresiones *agregarValor(valorDeExpresiones *lista,int val)
{
valorDeExpresiones *aux=NULL;
valorDeExpresiones *nuevoVal=(valorDeExpresiones*) malloc (sizeof(valorDeExpresiones));
nuevoVal->valor=val;
nuevoVal->sgte=NULL;
nuevoVal->sgte=NULL;
	if(lista == NULL){
		lista=nuevoVal;
	}
	else
	{
	aux=lista;
		while(aux->sgte != NULL){
			aux=aux->sgte;
		}
		aux->sgte=nuevoVal;
	}
	return lista;
}

void escribirExpresiones(valorDeExpresiones *expresiones)
{
	while(expresiones!=NULL)
	{
	printf("%d ,",expresiones->valor);
	expresiones=expresiones->sgte;
	}
}

int esPalabraReservada(char nombreId[])
{
	if(strcmp(nombreId,"inicio")==0)
		return 1;
	if(strcmp(nombreId,"fin")==0)
		return 1;
	if(strcmp(nombreId,"leer")==0)
		return 1;
	if(strcmp(nombreId,"escribir")==0)
		return 1;
	return 0;
}

void errorIdNoDeclarado(char nombreId[])
{
printf("El identificador %s no esta declarado en linea %d",nombreId,yylineno);
return 1;
}

void errorPalabraReservada(char nombreId[])
{
printf("El identificador %s es palabra reservada en linea %d",nombreId,yylineno);
return 1;
}

void yyerror (char const *s) {
   printf ("Error al compilar");
 }
 
 int yywrap()
 {
return 1;
 }