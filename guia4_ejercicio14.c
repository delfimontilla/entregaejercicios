#include <stdio.h>
#include <stdlib.h>

#define MSJ_UBICACION "El objetivo se encuentra en la posicion"
#define MSJ_NO_ENCONTRADO "No se encontro el numero"

int busqueda_binaria(const int v[], size_t n, int objetivo){   

 int minimo, maximo, promedio;

 minimo = 0;
 maximo = n - 1;
 while (minimo <= maximo) {

  promedio = (minimo+maximo)/2;

  if (objetivo == v[promedio])  
   return promedio;

  else if (objetivo > v[promedio])
   minimo = promedio + 1;
   
  else
   maximo = promedio - 1;
  }
   
  return -1;
}

int main(void)
{
 
 int v[]={1,2,3,4,5,6,7,8,9,10};
 int objetivo=9, ubicacion=0; /*objetivo es el elemento que quiero rastrear*/
 int n = sizeof(v) / sizeof(int);

 ubicacion=busqueda_binaria(v,n,objetivo);

 if (ubicacion!=-1)
  printf("%s: %d\n", MSJ_UBICACION, ubicacion);
 
 else 
  printf("%s %d\n", MSJ_NO_ENCONTRADO, objetivo);

 return EXIT_SUCCESS;
}



