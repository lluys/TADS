#include "Estructuras.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>


//Solo estructura, no se ha implementeado correctamente aun
void ordenarBurbuja(t_lectura* datos, int num_sensores){
    int i, j;
    t_lectura temp;
    for(i=0;i<num_sensores;i++){
            printf("%d: %d\n", datos[i].etiqueta, datos[i].valor);
        }
    for (i=1;i<num_sensores;i++)
    {
       for (j=0; j < num_sensores-i ;j++) // for(j=0; j < Nelementos-i; j++) es menor y no menor igual
       {
          if (datos[j].valor > datos[j+1].valor)//Condicion mayor-menor
          {
            temp=datos[j];
            datos[j]=datos[j+1];
            datos[j+1]=temp;
          }
       }
    }
}


int leerDatos(t_lectura* datos_sensores, int num_sensores, int num_lecturas, int tiempo_lectura){
    int *sensores_leidos;
    int n_aleatorio, i, j, contador;
    bool reinicio_busqueda;
    clock_t tini;
    
    sensores_leidos = (int*)malloc(sizeof(int)*num_sensores);
    for(i=0;i<num_sensores;i++){
        sensores_leidos[i] = 0;
    }

    tini = clock();
	while(((double)(clock() - tini) / CLOCKS_PER_SEC) < tiempo_lectura){
		//Tic Tac, no tenemos nueva lectura aun
		//printf("Total time taken by CPU: %f\n", ((double)(clock() - tini) / CLOCKS_PER_SEC)  );
	}

    contador = 0;
	while(contador<num_sensores){
		
		
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
					return 0;
                }
            }
		}//Hemos encontrado un sensor por leer
		sensores_leidos[n_aleatorio]++;
		datos_sensores[n_aleatorio].momento = ((double)(clock() - tini) / CLOCKS_PER_SEC);
		
		contador++;
	}//Salimos de las lecturas
	return 1;
}

void simular(t_lectura* datos, char* nombre, int sensores){
	FILE *f;
	int j;
	f = fopen(nombre, "w");
    
	
	for(j=0;j<sensores;j++){
		datos[j].valor = rand()%100;
		datos[j].etiqueta = j+1;
		
		printf("datos[j].valor: %d\n", datos[j].valor);
		fprintf(f, "%d\t", datos[j].valor);
	}
	
	fprintf(f, "\n");	
	fclose(f);

}

void escribirFichero(t_lectura* datos, char* nombre, int sensores){
	FILE *f;
	int j;
	f = fopen(nombre, "w");
    
	
	for(j=0;j<sensores;j++){
		fprintf(f, "%d\t%d\t%.10f\n", datos[j].valor, datos[j].etiqueta, datos[j].momento);
	}
	
	fprintf(f, "\n");	
	fclose(f);



}


int main(int argc, const char* argv[]){
    int i, j;
	FILE *f;
	
 	int num_sensores = atoi(argv[1]);
	int num_lecturas = atoi(argv[3]);
	int tiempo_lectura = atoi(argv[2]);
	t_lectura *datos_sensores;
	
	//printf("Datos de entrada sensores:%d, lecturas:%d, frecuencias: %d", num_sensores, num_lecturas, tiempo_lectura);  
	
	datos_sensores = (t_lectura*)malloc(sizeof(t_lectura)*num_sensores);
	
	while(1){
		simular(datos_sensores, "sensores.txt", num_sensores);
		printf("aaaaaaaaaaaaaa%d\n", datos_sensores[0].etiqueta);
		
		if(!leerDatos(datos_sensores, num_sensores, num_lecturas, tiempo_lectura)){
            return -1;
        }
        printf("\n\n");
        
        ordenarBurbuja(datos_sensores, num_sensores);
		printf("\n\n");
		
		escribirFichero(datos_sensores, "envio.txt", num_sensores);
		
		printf("Ya los hemos leido todos\n");
	}//fin bucle infinito
    
  //Esta linea para que el Travis no nos borre nada al compilar
  printf("\n\n");
  fflush(stdout);
  return 0;
}
