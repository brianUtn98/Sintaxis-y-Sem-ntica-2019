#include<string.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <locale.h>




struct accion // Estructura para guardar los datos traídos de bolsar.
{
char especie[10];
int cantNominalA;
float precioCompra;
float precioVenta;
int cantNominalB;
float ultimo;
float variacion;
float apertura;
float maximo;
float minimo;
float cierreAnterior;
char volNominal[1024];
char montoOperado[1024];
int cantidadOperada;
char horas[7+1];
};

char menu(); /* Función para general el menú del TP*/
float convertirFloat(char []); /* Función hallada en linea, para convertir un string en float (reemplaza a atof)*/
void cargarEspecie(struct accion*,int,char[]); /*Función utilizada para crear la estructura estática de las especies*/
void mostrarEspecie(struct accion); /*Función de testeo, utilizada en el desarrollo del programa pero no implementada finalmente*/




FILE *popen(const char *command, const char *mode);
int pclose(FILE *stream);

int main(int argc,char *argv)
{
    int i=0,j=0,k=0;
    struct accion especies[20];
    char command[] = ".\\GnuWin32\\bin\\wget -q --user-agent=\"Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.103 Safari/537.36\" -O - http://52.67.191.9/SSL/lideres-bcba_limpio.html";
    FILE *cmd = popen(command, "r");

    char opcion;
    char buffer[1048576];
    char *token;



do
    {
    system("cls");
    opcion=menu();
    system("cls");
            printf("\n------------------------------------------------------------\n");
            printf("Parseando http://52.67.191.9/SSL/lideres-bcba_limpio.html");
            printf("\n------------------------------------------------------------\n");

            while(fscanf(cmd,"%s",&buffer) && strcmp(buffer,"<td>Especie</td><td>Vto.</td><td>Cant.")!=0  && !feof(cmd))// Este while descarta la mayor parte de la tabla.
            {

            }
            while(fscanf(cmd,"%s",&buffer) && strcmp(buffer,"</tr>")!=0 && !feof(cmd)) // Este while nos posiciona al inicio de las acciones
            {

            }

            while(fscanf(cmd,"%s",&buffer) && strcmp(buffer,"</table>")!=0 && !feof(cmd)) // Con este while se comienzan a guardar los campos de las acciones en un token.
            {

                token=strtok(buffer,"<td>");
                strcpy(especies[i].especie,token);

                    while(fscanf(cmd,"%s",&buffer) && strcmp(buffer,"</tr>")!=0)
                    {
                        token=strtok(buffer,"</td>");
                        cargarEspecie(&especies[i],j,token);

                             while(token != NULL)
                                {
                                 j++;
                                token = strtok(NULL, "</td>");
                               cargarEspecie(&especies[i],j,token);
                                }

                    }
                    j=0;

            i++;

            }


            /*token=strtok(buffer,"<td>");
            strcpy(especies[i].especie,token);
            */
    pclose(cmd);

        switch(opcion)
        {
        case '1':
            printf("Se eligio opcion 1");
            getche();
            for(k=0;k<20;k++)
            {
                if(especies[k].variacion>0.5)
                mostrarEspecie(especies[k]);
            }
        getche();
        break;
        }

    }
    while(opcion!=27);
}

char menu()
{
char opcion;
    printf("\n[1] Listar en pantalla las especies cuyo porcentaje de variacion supera el 0,5.");
    printf("\n[2] Crear reporte de cotizaciones de compra y venta en archivo .CSV.");
    printf("\n[3] Crear reporte de cotizaciones de compra y venta en archivo .html.\n");
    printf("\nESc. Salir.");
    opcion=getche();

return opcion;
}

//Créditos: http://www.forosdelweb.com/f96/transofmar-char-float-c-733924/
float convertirFloat(char s[1048576]) // Ya que atof no tenía en cuenta los decimales a la hora de convertir a float, buscamos una solución, hallando esta función.
{
double res = 0.0, aux;
int i, j, k;
for(i=0, j=1; s[i]>47 && s[i]<58; ++i);

    for(k=i-1; k>-1; --k, j*=10) // Guarda la parte entera del número.
        res = res + (s[k]-48)*j;

   //Si se posicionó en 'j' o '.' hay parte decimal, sino no hay.
    if(s[i]==',' || s[i]=='.'){
        ++i;
        for(k=1; s[i]!='\0'; ++k, ++i){
            aux = s[i] - 48;
            for(j=0; j<k; ++j)
                aux = aux * 0.1;
            res = res + aux;
        }
}
return res;
}

void cargarEspecie(struct accion *accion,int campo,char s[1048576])
{
setlocale(LC_ALL|~LC_NUMERIC, ""); // No funcionó
int campoNum;
double campoFloat;
    switch(campo)
    {
    case 0:
        strcpy(accion->especie,s);
    break;
    case 3:
        accion->cantNominalA=atoi(s);
    break;
    case 4:
        accion->precioCompra=convertirFloat(s);

        //accion->precioCompra=atof(s);
    break;
    case 5:
        accion->precioVenta=convertirFloat(s);

        //accion->precioVenta=atof(s);
    break;
    case 6:
        accion->cantNominalB=atoi(s);
    break;
    case 7:
        accion->ultimo=convertirFloat(s);

        //accion->ultimo=atof(s);
    break;
    case 8:
        //accion->variacion=convertirFloat(s);
        accion->variacion=atof(s);
    break;
    case 9:
        //accion->apertura=convertirFloat(s);

        accion->apertura=atof(s);
    break;
    case 10:
        accion->maximo=convertirFloat(s);

        //accion->maximo=atof(s);
    break;
    case 11:
        accion->minimo=convertirFloat(s);

        //accion->minimo=atof(s);
    break;
    case 12:
        accion->cierreAnterior=convertirFloat(s);

        //accion->cierreAnterior=atof(s);
    break;
    case 13:
        strcpy(accion->volNominal,s);
    break;
    case 14:
        strcpy(accion->montoOperado,s);
    break;
    case 15:
        accion->cantidadOperada=atoi(s);
    break;
    case 16:
        strcpy(accion->horas,s);
    break;
    }

return;
}

void mostrarEspecie(struct accion accion)
{
    printf("Especie\n");

    printf("\nNombre de Especie:%s ",accion.especie);
    printf("\nCant. Nominal: %d ",accion.cantNominalA);
    printf("\nPrecio Compra: %.3f ",accion.precioCompra);
    printf("\nPrecio venta: %.3f ",accion.precioVenta);
    printf("\nCant.Nominal: %d ",accion.cantNominalB);
    printf("\nUltimo: %.3f ",accion.ultimo);
    printf("\nVariacion: %.3f ",accion.variacion);
    printf("\nApertura: %.3f ",accion.apertura);
    printf("\nMaximo: %.3f ",accion.maximo);
    printf("\nMinimo: %.3f ",accion.minimo);
    printf("\nCierre anterior: %.3f ",accion.cierreAnterior);
    printf("\nVol. Nominal: %d ",accion.volNominal);
    printf("\nMonto operado: %d ",accion.montoOperado);
    printf("\nCant. Operada: %d ",accion.cantidadOperada);
    printf("\nHora: %s ",accion.horas);

}
