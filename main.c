#include "Estructuras.h"

void mostrarMatriz(int **datos,int fil, int col  ){
	int i,j;
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			printf("%d\t\t",datos[i][j]);
		}
		printf("\n");
	}
}

void leer(int* datos, int sensor, int lecturas){
	int i, j;
	//el dato a leer en cada iteracion sera  un numero aleatorio dentro de los rangos  del problema
	int dato;
	int cont=0;
	char etiqueta[20];
	
	
	t_lectura lectura;
	
	
	while(cont<lecturas){
		
		dato = datos[cont];
		sprintf(etiqueta, "%dS%d", dato, sensor);
	
		printf("%s\n",  etiqueta);
		cont++;
	}
    
}


void simular(char* nombre, int sensores, int lecturas){
	FILE *f;
	int i, j;
	f = fopen(nombre, "w");
    
	for(j=0;j<sensores;j++){
		fprintf(f, "S%d\t", j);
	}
	


	for(i=0;i<lecturas;i++){
		fprintf(f, "\n");
		for(j=0;j<sensores;j++){
			fprintf(f, "%d\t", rand()%100);
		}
	}	
	fprintf(f, "\n");	
	fclose(nombre);

}

void  cargarDatos(char* archivo, int** datos, int sensores, int lecturas){
	FILE* file = fopen(archivo, "r"); 
    char line[256];
	int numTok, i;
	char s2[4] = " \n\t";
	char *ptr;
    int sens, lect=1;	
    
	//Etiqueta
	fgets(line, sizeof(line), file);
	for(i=0;i<sensores;i++){
        datos[i][0]=i;
    }
	//valores
    while (lect <= lecturas && fgets(line, sizeof(line), file)) {
        sens=0;
		ptr = strtok( line, s2 );    // Primera llamada => Primer token
		datos[sens][lect]=atoi(ptr);
		while( (ptr = strtok( NULL, s2 )) != NULL ) {   // Posteriores llamadas
			sens++;
			datos[sens][lect]=atoi(ptr);
		}
		lect++;
    }
    
}

int main(int argc, const char* argv[]){
    int i, j;
    int **datosSensores;    //Estructura para guardar los datos leidos de los sensores
	int num_sensores = atoi(argv[1]);
	int num_lecturas = atoi(argv[3]);
	int tiempo_lectura = atoi(argv[2]);
  
	FILE *f;
    simular("sensores.txt", num_sensores, num_lecturas);

  //printf("Datos de entrada sensores:%d, lecturas:%d, frecuencias: %d", num_sensores, num_lecturas, tiempo_lectura);
    

	datosSensores = (int **)malloc(num_lecturas*sizeof(int*));
	for (i=0;i<num_sensores;i++)
	{
		datosSensores[i] = (int *)malloc(num_lecturas*sizeof(int));
	}
	
    cargarDatos("sensores.txt",  datosSensores, num_sensores, num_lecturas);
	
	for (i=0;i<num_sensores;i++)
	{
		if(i != 0)	sleep((unsigned int)tiempo_lectura);
		leer(datosSensores[i], i, num_lecturas);
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