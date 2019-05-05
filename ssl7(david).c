#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float numero, maximo=0, promedio, acumulador = 0;
	int i, contador = 0, j = 1;
	
	printf("Ingrese los numeros de cada juego, ingrese -1 para terminar el juego: \n\n");

	for (i = 1; i <= 5; i++) {
		printf("Numero [1] del juego nro [%d]: ", i);
		scanf("%f", &numero);
		maximo = numero;

		while (numero != -1) {
			if(numero >= 0){
				acumulador += numero;
				contador++;
				if(numero >= maximo){
					maximo = numero;
				}
			}

			j++;
			printf("Numero [%d] del juego nro [%d]: ", j, i);
			scanf("%f", &numero);
		}
		
		if (maximo == -1)
			printf("\nNo se ingresaron valores, por lo tanto no hay maximo.\n\n");
		else
			printf("\nEl maximo es: %f\n\n", maximo);
			
		j = 1;
	}

	if (contador == 0) {
		printf("No hay valores ingresados, por lo tanto no hay promedio que calcular\n\n");
	} else {
		promedio = acumulador/contador;
		printf("El promedio total es: %f\n\n", promedio);	
	}

	system("PAUSE");
	return 0;
}
