#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


typedef struct{
	char etiqueta[2];
	float valor;
	time_t momento;
}Lectura;

typedef Lectura t_lectura;