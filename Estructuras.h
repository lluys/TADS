#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
	char etiqueta[2];
	float valor;
	time_t momento;
}Lectura;

typedef Lectura t_lectura;