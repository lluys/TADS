#include <stdlib.h>
#include <stdio.h>

void leer()
{
	
}

int main(int argc, const char* argv[]){
  int num_sensores = atoi(argv[1]);
  int num_lecturas = atoi(argv[3]);
  float tiempo_lectura = atof(argv[2]);

  printf("Datos de entrada sensores:%d, lecturas:%d, frecuencias: %f", num_sensores, num_lecturas, tiempo_lectura);
  
	int **datosSensores;
	datosSensores = (int **)malloc(num_lecturas*sizeof(int*));
	for ()
	{
		
	}
  
  //Esta linea para que el Travis no nos borre nada al compilar
  printf("\n\n");
  fflush(stdout);
  return 0;
}
