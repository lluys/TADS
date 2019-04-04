#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


typedef struct Lectura{
	char etiqueta[2];
	float valor;
	time_t momento;
}
