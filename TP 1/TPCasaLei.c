#include<string.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>




struct accion
{
char especie[10];
int cantNominalA;
double precioCompra;
double precioVenta;
int cantNominalB;
double ultimo;
double variacion;
double apertura;
double maximo;
double minimo;
double cierreAnterior;
int volNominal;
int montoOperado;
int cantidadOperada;
char horas[7+1];
};

void cargarEspecie(struct accion *accion,int campo,char s[1048576])
{
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
        accion->precioCompra=atof(s);
    break;
    case 5:
        accion->precioVenta=atof(s);
    break;
    case 6:
        accion->cantNominalB=atoi(s);
    break;
    case 7:
        accion->ultimo=atof(s);
    break;
    case 8:
        accion->variacion=atof(s);
    break;
    case 9:
        accion->apertura=atof(s);
    break;
    case 10:
        accion->maximo=atof(s);
    break;
    case 11:
        accion->minimo=atof(s);
    break;
    case 12:
        accion->cierreAnterior=atof(s);
    break;
    case 13:
        accion->volNominal=atoi(s);
    break;
    case 14:
        accion->montoOperado=atoi(s);
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

    printf("\n%s ",accion.especie);
    printf("\n%d ",accion.cantNominalA);
    printf("\n%f ",accion.precioCompra);
    printf("\n%f ",accion.precioVenta);
    printf("\n%d ",accion.cantNominalB);
    printf("\n%f ",accion.ultimo);
    printf("\n%f ",accion.variacion);
    printf("\n%f ",accion.apertura);
    printf("\n%f ",accion.maximo);
    printf("\n%f ",accion.minimo);
    printf("\n%f ",accion.cierreAnterior);
    printf("\n%d ",accion.volNominal);
    printf("\n%d ",accion.montoOperado);
    printf("\n%d ",accion.cantidadOperada);
    printf("\n%s ",accion.horas);

}

FILE *popen(const char *command, const char *mode);
int pclose(FILE *stream);

int main(void)
{
    int i=0,j=0;
    struct accion especies[20];
    char command[] = ".\\GnuWin32\\bin\\wget -q --user-agent=\"Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.103 Safari/537.36\" -O - http://52.67.191.9/SSL/lideres-bcba_limpio.html";
    FILE *cmd = popen(command, "r");
    FILE *f;
    char stop[1024];
    f=fopen("CADENASTOP.dat","r");
    fgets(stop,sizeof(stop),f);
    fclose(f);
    printf("%s",stop);
    getche();

    char buffer[1048576];
    char *token;
            while(fscanf(cmd,"%s",&buffer) && strcmp(buffer,"<td>Especie</td><td>Vto.</td><td>Cant.")!=0  && !feof(cmd)) // Este while descarta la mayor parte de la tabla.
            {
                printf("\n------------------------------------------------------------\n");
                printf("%s",buffer);
            }

            while(fscanf(cmd,"%s",&buffer) && strcmp(buffer,"<tr>")!=0 && !feof(cmd)) // Este while nos posiciona al inicio de las acciones
            {
                printf("\n------------------------------------------------------------\n");
                printf("%s",buffer);
            }

                while(fscanf(cmd,"%s",&buffer) && strcmp(buffer,"</table>")!=0 && !feof(cmd)) // Con este while se comienzan a guardar los campos de las acciones en un token.
            {
                printf("\n------------------------------------------------------------\n");
                printf("%s",buffer);
                token=strtok(buffer,"<td>");
                strcpy(especies[i].especie,token);
                    while(fscanf(cmd,"%s",&buffer) && strcmp(buffer,"</tr>")!=0)
                    {
                        token=strtok(buffer,"</td>");
                        cargarEspecie(&especies[i],j,token);
                                j=0;
                             while(token != NULL)
                                {
                                j++;
                                printf( "{El token es: %s\n}", token );
                                token = strtok(NULL, "</td>");
                               cargarEspecie(&especies[i],j,token);

                                }

                            }

            i++;

            }


            printf("%s",buffer);
            token=strtok(buffer,"<td>");
            printf("El token es: %s",token);

            strcpy(especies[i].especie,token);
            printf("%s",especies[i].especie);


    getche();
    int k;
   printf("\n------------------------------------------------------------\n");
    printf("Listando especies: ");
    for(k=0;k<20;k++)
    mostrarEspecie(especies[k]);
    pclose(cmd);
    return 0;
}
