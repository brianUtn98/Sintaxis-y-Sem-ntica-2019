%{
	#include <string.h>
	#include <conio.h>
	#include <stdio.h>
	#include <iostream>
	
	extern int yylineno;
	void cerrarPrograma();
	
	
	struct nodo{
	char *id;
	int val;
	struct nodo *sgt;
	}Simbolo;
	
	struct valExpresiones{
	int valor;
	struct valExpresiones *sgte;
	}valorDeExpresiones;
	
	int flagR=0,flagW=0;
	valorDeExpresiones *valorDeExpresiones=NULL;
	Simbolo *identificadores=NULL;
	Simbolo *tablaDeSimbolos=NULL;
	Simbolo *iniciarTS(Simbolo *);
	Simbolo *agregarSimbolo(Simbolo *,char *,int);
	Simbolo *agregarIdentificador(Simbolo *,char *);
	
%}

%union {
	int int_val;
	std::string* str_val;
}

%token <int_val> INICIO FIN SUMA RESTA PRODUCTO ASIGNACION PAREN_DER PAREN_IZQ PUNTOYCOMA LEER ESCRIBIR COMA CONSTANTE
%token <str_val> IDENTIFICADOR

%left SUMA RESTA
%left PRODUCTO

%start programa

%%
programa: INICIO {tablaDeSimbolos=iniciarTS(tablaDeSimbolos);} sentencias FIN{cerrarPrograma();};
sentencias: sentencia sentencias | sentencia;
sentencia: 	LEER {flagR=1;} PAREN_IZQ listaIdentificadores PAREN_DER PUNTOYCOMA {
	tablaDeSimbolos=agregarSimbolos(identificadores,tablaDeSimbolos);
	flagR=0;} |
			ESCRIBIR {flagW=1;} PAREN_IZQ listaExpresiones PAREN_DER PUNTOYCOMA {escribirExpresiones(valorDeExpresiones)
			limpiarLista(valorDeExpresiones)
			flagW=0;} |
			IDENTIFICADOR ASIGNACION expresion PUNTOYCOMA{asignarValorASimbolo($1,$3)};
listaExpresiones: 	expresion {if(flagW=1) agregarValor(valorDeExpresiones,$1);} COMA listaExpresiones {} |
					expresion {if(flagW=1) agregarValor(valorDeExpresiones,$1);};
listaIdentificadores: IDENTIFICADOR {if(flagR=1) listaIdentificadores=agregarIdentificador(listaIdentificadores,$1);} COMA listaIdentificadores |   IDENTIFICADOR {if(flagR=1) listaIdentificadores=agregarIdentificador(listaIdentificadores,$1);};
			
	
}

%%

void cerrarPrograma(){
printf("\n Se ha terminado la ejecución del programa exitosamente");
return 0;
}

Simbolo *iniciarTS(Simbolo *lista)
{
lista=NULL;
return lista;
}

Simbolo *agregarSimbolo(Simbolo *lista,Simbolo *nuevoSimbolo)
{
nuevoSimbolo->sgt=NULL;
	if(lista == NULL){
		lista=nuevoSimbolo;
	}
	else
	{
	aux=lista;
		while(aux->sgt != NULL){
			aux=aux->sgt;
		}
		aux->sgt=nuevoSimbolo;
	}
	return lista;
}
Simbolo *agregarSimbolos(Simbolo *lista,Simbolo *identificadores);
{
Simbolo *aux=identificadores;
int buffer;
	while(aux != NULL)
	{
	
	printf("Ingrese el valor de %c",aux->id);
	scanf("%d",&buffer)
	aux.val=buffer;
	lista=agregarSimbolo(lista,aux);
	aux=aux->sgt;
	}
	return lista;
}

Simbolo *agregarIdentificador(Simbolo *lista,char *nombreId);
{
Simbolo *nuevoIdentificador,*aux;
nuevoIdentificador=Simbolo*malloc(sizeof(Simbolo));
nuevoIdentificador->id=id;
nuevoIdentificador.val=-1; //-1 simboliza aún sin valor.
nuevoIdentificador->sgte=NULL;
aux=lista;
	
	if(lista==NULL)
	{
		lista=nuevoIdentificador;
	}
	else
	{
		while(aux->sgt != NULL)
		{
			aux=aux->sgt;
		}
		aux->sgt=nuevoIdentificador;
	}
	return lista;
}