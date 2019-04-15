#include "Estructuras.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>



int main(int argc, const char* argv[]){
    int i, j;
    t_lectura *datos_sensores;
    int num_sensores = atoi(argv[1]);
	
	datos_sensores = (t_lectura*)malloc(sizeof(t_lectura)*num_sensores);
    
    int valor;
    int etiqueta;
    double tiempo;
    
    FILE* archivo;
    archivo = fopen("envio.txt", "r");
    
    while(archivo == NULL)
    {
        printf(".");
    }
    
    printf("\n");
    
    while(!feof(archivo))
    {
        fscanf(archivo, "%d", &valor);
        fscanf(archivo, "%d", &etiqueta);
        fscanf(archivo, "%f", &tiempo);
        
        datos_sensores[etiqueta-1].valor = valor;
        datos_sensores[etiqueta-1].etiqueta = etiqueta;
        datos_sensores[etiqueta-1].momento = tiempo;
    }
	
	for(i = 0; i < num_sensores; i++)
    {
        if (datos_sensores[i].valor > 100)
        {
            printf("Alerta roja en sensor %d -> Valor: %d\n", i+1, datos_sensores[i].valor);
        }
        else if(datos_sensores[i].valor > 50)
        {
            printf("Alerta amarilla en sensor %d -> Valor: %d\n", i+1, datos_sensores[i].valor);
        }
        else
        {
            printf("Alerta verde en sensor %d -> Valor: %d\n", i+1, datos_sensores[i].valor);
        }
    }
    
  //Esta linea para que el Travis no nos borre nada al compilar
  printf("\n\n");
  fflush(stdout);
  return 0;
}
