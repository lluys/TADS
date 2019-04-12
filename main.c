#include <stdlib.h>
#include <stdio.h>

void simular(char* nombre, int sensores){
	FILE *f;
	int j;
	f = fopen(nombre, "w");
    
	
	for(j=0;j<sensores;j++){
		fprintf(f, "%d\t", rand()%100);
	}
	
	fprintf(f, "\n");	
	fclose(nombre);

}



int main(int argc, const char* argv[]){
    int i, j;
	FILE *f;
		
	int num_sensores = atoi(argv[1]);
	int num_lecturas = atoi(argv[3]);
	int tiempo_lectura = atoi(argv[2]);
	//printf("Datos de entrada sensores:%d, lecturas:%d, frecuencias: %d", num_sensores, num_lecturas, tiempo_lectura);  
	
	while(1){
		simular("sensores.txt", num_sensores);
	}
    
  //Esta linea para que el Travis no nos borre nada al compilar
  printf("\n\n");
  fflush(stdout);
  return 0;
}