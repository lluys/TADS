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
    
    while(1)
    {
        FILE* archivo;
        archivo = fopen("envio.txt", "r");
        
        if(archivo == NULL)
        {
            return-1;
        }
        
        while(!feof(archivo))
        {
            fscanf(archivo, "%d", &valor);
            fscanf(archivo, "%d", &etiqueta);
            fscanf(archivo, "%f", &tiempo);
            
            datos_sensores[etiqueta-1].valor = valor;
            datos_sensores[etiqueta-1].etiqueta = etiqueta;
            datos_sensores[etiqueta-1].momento = tiempo;
        }
	}//fin bucle
    
  //Esta linea para que el Travis no nos borre nada al compilar
  printf("\n\n");
  fflush(stdout);
  return 0;
}
