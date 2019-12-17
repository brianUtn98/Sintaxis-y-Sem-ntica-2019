%{
	#include <string.h>
	#include <conio.h>
	#include <stdio.h>
	#include <stdlib.h>
	
	extern int yylineno;
	extern int yylex();
	extern FILE *yyin;
	extern void yyerror(const char*);
	int yywrap();
	
	typedef struct ElementoSimbolo{
	char id[33];
	int val;
	struct ElementoSimbolo *sgte;
	}Simbolo;
	
	/*typedef struct ElementovalorDeExpresiones{
	int valor;
	struct ElementovalorDeExpresiones *sgte;
	}valorDeExpresiones;*/

	//valorDeExpresiones *valExpresiones=NULL;
	Simbolo *valExpresiones=NULL;
	Simbolo *identificadores=NULL;
	Simbolo *tablaDeSimbolos=NULL;
	Simbolo *iniciarTS(Simbolo *);
	Simbolo *agregarSimbolo(Simbolo *,char [],int);
	Simbolo *agregarIdentificador(Simbolo *,char []);
	/*valorDeExpresiones *agregarValor(valorDeExpresiones*,int);*/
	Simbolo *agregarValor(Simbolo *,int);
	Simbolo *buscarId(Simbolo *,char []);
	Simbolo *agregarSimbolos(Simbolo*,Simbolo*);
	Simbolo *asignarValorASimbolo(Simbolo*,char[],int);
	int identificadorCreado(Simbolo*,char[]);
	//valorDeExpresiones *limpiarListaExpresiones(valorDeExpresiones*);
	Simbolo *limpiarLista(Simbolo*);
	int esPalabraReservada(char[]);
	void errorIdNoDeclarado(char[]);
	void errorPalabraReservada();
	/*void escribirExpresiones(valorDeExpresiones*);*/
	void escribirValores(Simbolo*);
	void mostrar(Simbolo*);
	
	
	int flagR=0,flagW=0;
	void cerrarPrograma();
	int idCreado;
	Simbolo *cursor=NULL;
	
	
%}

%union {
	int int_val;
	char *str_val;
}

%token <int_val> INICIO FIN SUMA RESTA ASIGNACION PAREN_DER PAREN_IZQ PUNTOYCOMA LEER ESCRIBIR COMA CONSTANTE
%token <str_val> IDENTIFICADOR

%type <str_val> sentencia listaIdentificadores;
%type <int_val> expresion primaria1 primaria2 listaExpresiones;

%left SUMA RESTA

%start programa

%%

programa: INICIO {tablaDeSimbolos=iniciarTS(tablaDeSimbolos);} sentencias FIN{cerrarPrograma();};

sentencias: sentencias sentencia | sentencia;

sentencia: 	LEER {flagR=1;} PAREN_IZQ listaIdentificadores PAREN_DER PUNTOYCOMA { /*mostrar(identificadores);*/
	tablaDeSimbolos=agregarSimbolos(tablaDeSimbolos,identificadores);
	flagR=0;} |
			ESCRIBIR {flagW=1;} PAREN_IZQ listaExpresiones PAREN_DER PUNTOYCOMA {escribirValores(valExpresiones);
			valExpresiones=limpiarLista(valExpresiones);
			flagW=0;} |
			IDENTIFICADOR ASIGNACION expresion PUNTOYCOMA {if((idCreado=esPalabraReservada($1))==1) { errorPalabraReservada();} else { asignarValorASimbolo(tablaDeSimbolos,$1,$3);} };
			
listaExpresiones: 	expresion {if(flagW==1) valExpresiones=agregarValor(valExpresiones,$1);} COMA listaExpresiones {} |
					expresion {if(flagW==1) valExpresiones=agregarValor(valExpresiones,$1);};
					
listaIdentificadores: IDENTIFICADOR {if(flagR==1) identificadores=agregarIdentificador(identificadores,$1);} COMA listaIdentificadores |   IDENTIFICADOR {if(flagR==1) identificadores=agregarIdentificador(identificadores,$1);};

expresion:	expresion SUMA primaria1 {$$= $1 + $3;} |
			expresion RESTA primaria1 {$$= $1 - $3;} |
			primaria1 {$$=$1;};
			
primaria1:	primaria2 {$$ = $1;};

primaria2: 	IDENTIFICADOR{
			if((idCreado=identificadorCreado(tablaDeSimbolos,$1))==1)
			{
				if((idCreado=esPalabraReservada($1))==1)
				{
				errorPalabraReservada();
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
printf("\n Se ha terminado la ejecucion del programa exitosamente. Se han analizado %d lineas. Presione una tecla para salir.",yylineno);
getche();
exit(0);
}

Simbolo *iniciarTS(Simbolo *lista)
{
//printf("\n Iniciando tabla de simbolos...\n");
//getche();
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
	inicio->val=80;
	fin->val=81;
	leer->val=82;
	escribir->val=83;
lista=agregarSimbolo(lista,inicio->id,0);
lista=agregarSimbolo(lista,fin->id,0);
lista=agregarSimbolo(lista,leer->id,0);
lista=agregarSimbolo(lista,escribir->id,0);

//printf("\n Tabla de simbolos iniciada correctamente.\n");
//getche();
return lista;
}

Simbolo *agregarSimbolo(Simbolo *lista,char nombreId[],int val)
{
Simbolo *nuevoSimbolo=(Simbolo *)malloc(sizeof(Simbolo));
nuevoSimbolo->sgte=NULL;
strcpy(nuevoSimbolo->id,nombreId);
nuevoSimbolo->val=val;
//printf("\nAgregando simbolo a la tabla de simbolos. ");
//printf("%s y %d\n",nuevoSimbolo->id,nuevoSimbolo->val);
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
//printf("\nSe agrego el simbolo %s:%d \n",nuevoSimbolo->id,nuevoSimbolo->val);
	return lista;
}
Simbolo *agregarSimbolos(Simbolo *lista,Simbolo *identificadores)
{
Simbolo *aux=identificadores;
int buffer;
	while(aux != NULL)
	{
	printf("\nIngrese el valor de %s: ",aux->id);
	scanf("%d",&buffer);
	//printf("\n Se leyo %d",buffer);
	aux->val=buffer;
	lista=agregarSimbolo(lista,aux->id,aux->val);
	//printf("\n Agregado valor de %s : %d ",aux->id,aux->val);
		if(aux->sgte!=NULL)
		{
		Simbolo *sgte=aux->sgte;
		free(aux);
		aux=sgte;
		}
		else
		{
		free(aux);
		aux=NULL;
		}
	/*if(aux!=NULL)
	printf("\n Moviendo cursor a %s a %s ",aux->id,aux->sgte->id);
	*/
	}
	//mostrar(lista);
	//getche();
	return lista;
}

Simbolo *agregarIdentificador(Simbolo *lista,char nombreId[])
{
Simbolo *nuevoIdentificador,*aux;
nuevoIdentificador=(Simbolo*) malloc (sizeof(Simbolo));
strcpy(nuevoIdentificador->id,nombreId);
nuevoIdentificador->val=0; //0 simboliza aún sin valor.
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
Simbolo *aux2=NULL;
	aux2=lista;
	aux=buscarId(aux2,nombreId);
		if(aux!=NULL)
		aux->val=val;
		else
		{
		agregarSimbolo(lista,nombreId,val);
		}
	
return lista;
}

Simbolo *buscarId(Simbolo *lista,char nombreId[])
{
Simbolo *aux=lista;
	while(aux->sgte!=NULL && strcmp(aux->id,nombreId)!=0)
	aux=aux->sgte;
	if(strcmp(aux->id,nombreId)==0)
	return aux;
	else
	return NULL;
}

int identificadorCreado(Simbolo *lista,char nombreId[])
{
Simbolo *aux=lista;
	while(aux->sgte!= NULL && strcmp(aux->id,nombreId)!=0)
	aux=aux->sgte;

	if(strcmp(aux->id,nombreId)==0)
	return 1;
	else
	return 0;
}

Simbolo *limpiarLista(Simbolo *lista)
{
Simbolo *aux=lista;
lista=NULL;
	while(aux != NULL)
	{
	Simbolo *sgte=aux->sgte;
	free(aux);
	aux=sgte;
	}
return lista;
}

Simbolo *agregarValor(Simbolo *lista,int val)
{
Simbolo *aux=NULL;
Simbolo *nuevoVal=(Simbolo*) malloc (sizeof(Simbolo));
nuevoVal->val=val;
strcpy(nuevoVal->id,"");
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

void escribirExpresiones(Simbolo *expresiones)
{
	while(expresiones!=NULL)
	{
	printf("%d , ",expresiones->val);
	expresiones=expresiones->sgte;
	}
	printf("\n");
}

int esPalabraReservada(char *nombreId)
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
printf("\nERROR: El identificador %s no esta declarado en linea %d. Presione una tecla para salir.",nombreId,yylineno);
getche();
exit(0);
}

void errorPalabraReservada()
{
printf("\nERROR: El identificador en la linea %d es palabra reservada. Presione una tecla para salir.",yylineno);
getche();
exit(0);
}
 
void yyerror (char const *s) {
   printf ("\nError al compilar");
 }
 
 void escribirValores(Simbolo *lista)
 {
Simbolo *aux=lista;
	while(aux != NULL)
	{
		printf("\n %d",aux->val);
		aux=aux->sgte;
	}
 }
 
 void mostrar(Simbolo *lista)
{
Simbolo *aux=lista;
	while(aux!=NULL)
	{
	printf("ID: %s , VAL: %d \n",aux->id,aux->val);
	aux=aux->sgte;
	}
}
 
 int main(int argc,char *argv)
{
int opcion;
char ruta[100];
printf("\nElija modo lectura de Archivo (1) o Modo estandar (2):");
scanf("%d",&opcion);
	if(opcion!=1)
	{
	printf("\nSe ha ejecutado en modo entrada estandar. Escriba el codigo de su programa de forma manual.\n");
	yyin=stdin;
	yyparse();
	}
	else
	{
		printf("Ingrese el nombre del archivo: ");
		scanf("%s",ruta);
		FILE *archivo=fopen(ruta,"r");
		if(archivo==NULL){
		printf("\nNo se pudo abrir el archivo.");
		return 1;
		}
		else
		{
		system("cls");
		printf("\nComenzando a parsear\n");
		yyin=archivo;
		yyparse();
		fclose(archivo);
		}
	}
return 0;
}

