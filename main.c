#include "Estructuras.h"


void simular(int* datos, char* nombre, int sensores){
	FILE *f;
	int j;
	f = fopen(nombre, "w");
    
	
	for(j=0;j<sensores;j++){
		datos[j] = rand()%100;
		fprintf(f, "%d\t", datos[j]);
	}
	
	fprintf(f, "\n");	
	fclose(f);

}



int main(int argc, const char* argv[]){

    int i, j, contador;

	int n_aleatorio;

	FILE *f;
	clock_t tini;
 	int num_sensores = atoi(argv[1]);
	int num_lecturas = atoi(argv[3]);
	int tiempo_lectura = atoi(argv[2]);
	int *datos_sensores, *sensores_leidos;
	bool reinicio_busqueda;
	//printf("Datos de entrada sensores:%d, lecturas:%d, frecuencias: %d", num_sensores, num_lecturas, tiempo_lectura);  
	
	datos_sensores = (int*)malloc(sizeof(int)*num_sensores);
	sensores_leidos = (int*)malloc(sizeof(int)*num_sensores);


	
	while(1){
		simular(datos_sensores, "sensores.txt", 5);
		
		for(i=0;i<num_sensores;i++){
            sensores_leidos[i] = 0;
        }
		
		contador = 0;
		while(contador<num_sensores){
			tini = clock();
			while(((double)(clock() - tini) / CLOCKS_PER_SEC) < tiempo_lectura){
				//Tic Tac, no tenemos nueva lectura aun
				//printf("Total time taken by CPU: %f\n", ((double)(clock() - tini) / CLOCKS_PER_SEC)  );
			}
			reinicio_busqueda = false;
			n_aleatorio = rand()%num_sensores;
				
			while(sensores_leidos[n_aleatorio] != 0){
                
                n_aleatorio++;
               
				//Volvemos al principio
				if(n_aleatorio==num_sensores){
                    
                    if(!reinicio_busqueda){
                        n_aleatorio=0;   
                        reinicio_busqueda = true;
                        
                    }else{
    					//Se supone que nunca llegaremos a este punto
    					//Si pasa ha habido algun error
    					return 1;
                    }
                    
            }
			}//Hemos encontrado un sensor por leer
			sensores_leidos[n_aleatorio]++;
			
			contador++;
		}//Salimos de las lecturas
		printf("Ya los hemos leido todos");
	}//fin bucle infinito
    
  //Esta linea para que el Travis no nos borre nada al compilar
  printf("\n\n");
  fflush(stdout);
  return 0;
}