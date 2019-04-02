#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void leer()
{
	
}

void simular(char* nombre, int sensores, int lecturas){
	FILE *f;
	int i, j;
	f = fopen(nombre, "w");
    
	for(j=0;j<sensores;j++){
		fprintf(f, "S%d\t\t", j);
	}
	


	for(i=0;i<lecturas;i++){
		fprintf(f, "\n");
		for(j=0;j<sensores;j++){
			fprintf(f, "%f\t", (float)rand()/(float)RAND_MAX);
		}
	}	
	fprintf(f, "\n");	

}

int main(int argc, const char* argv[]){
    int i, j;
    int **datosSensores;    //Estructura para guardar los datos leidos de los sensores
  int num_sensores = atoi(argv[1]);
  int num_lecturas = atoi(argv[3]);
  int tiempo_lectura = atoi(argv[2]);
  
  simular("sensores.txt", num_sensores, num_lecturas);

  //printf("Datos de entrada sensores:%d, lecturas:%d, frecuencias: %d", num_sensores, num_lecturas, tiempo_lectura);


	datosSensores = (int **)malloc(num_lecturas*sizeof(int*));
	for (i=0;i<num_sensores;i++)
	{
		datosSensores[i] = (int *)malloc(num_lecturas*sizeof(int));
	}



	for (i=0;i<num_sensores;i++)
	{
		free(datosSensores[i]);
	}  
    free(datosSensores);
  //Esta linea para que el Travis no nos borre nada al compilar
  printf("\n\n");
  fflush(stdout);
  return 0;
}
