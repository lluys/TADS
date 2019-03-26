#include <stdlib.h>
#include <stdio.h>


int main(){
  
int x = 10;
  
  printf("Hola Mundo. Esto es el numero diez: %d", x);
  
  
  
  //Esta linea para que el Travis no nos borre nada al compilar
  printf("\n\n");
  fflush(stdout);
  return 0;
}
