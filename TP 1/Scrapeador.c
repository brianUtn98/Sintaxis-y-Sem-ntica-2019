#include<string.h>
#include<stdio.h>
#include<conio.h>



struct accion
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
float volNominal;
float montoOperado;
int cantidadOperada;
char horas[7+1];
};

FILE *popen(const char *command, const char *mode);
int pclose(FILE *stream);

int main(void)
{
    int i=0;
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
                printf("\n------------------------------------------------------------\n");
                printf("%s",buffer);
            }

            while(fscanf(cmd,"%s",&buffer) && strcmp(buffer,"<tr>")!=0 && !feof(f)) // Este while nos posiciona al inicio de las acciones
            {
                printf("\n------------------------------------------------------------\n");
                printf("%s",buffer);
            }

            while(fscanf(cmd,"%s",&buffer) && strcmp(buffer,"</table>")!=0 && !feof(f)) // Con este while se comienzan a guardar los campos de las acciones en un token.
            {
                printf("\n------------------------------------------------------------\n");
                printf("%s",buffer);
                token=strtok(buffer,"<td>");
                strcpy(especies[i].especie,token);
                    while(fscanf(cmd,"%s",&buffer) && strcmp(buffer,"</tr>")!=0)
                    {
                        token=strtok(buffer,"</td>");

                             while( token != NULL )
                                {
                                printf( "{El token es: %s\n}", token );
                                token = strtok(NULL, "</td>");
                                }

                            }

            }


            printf("%s",buffer);
            token=strtok(buffer,"<td>");
            printf("El token es: %s",token);

            strcpy(especies[i].especie,token);
            printf("%s",especies[i].especie);



    pclose(cmd);
    return 0;
}
