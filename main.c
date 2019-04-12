#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void simular(char* nombre, int sensores){
	FILE *f;
	int j;
	f = fopen(nombre, "w");
    
	
	for(j=0;j<sensores;j++){
		fprintf(f, "%d\t", rand()%100);
	}
	
	fprintf(f, "\n");	
	fclose(f);

}



int main(int argc, const char* argv[]){
    int i, j;
	FILE *f;
	clock_t tini;
 	int num_sensores = atoi(argv[1]);
	int num_lecturas = atoi(argv[3]);
	int tiempo_lectura = atoi(argv[2]);
	
	//printf("Datos de entrada sensores:%d, lecturas:%d, frecuencias: %d", num_sensores, num_lecturas, tiempo_lectura);  
		
	while(1){
		tini = clock();
		while(((double)(clock() - tini) / CLOCKS_PER_SEC) < tiempo_lectura){
            //Tic Tac, no tenemos nueva lectura aun
            //printf("Total time taken by CPU: %f\n", ((double)(clock() - tini) / CLOCKS_PER_SEC)  );
		}
		simular("sensores.txt", 5);
	}
    
  //Esta linea para que el Travis no nos borre nada al compilar
  printf("\n\n");
  fflush(stdout);
  return 0;
}
