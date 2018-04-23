
#include <stdio.h>
#include <stdlib.h>

int imprimir( int f, int c, int m[][4], int *puntero){

 int i,j;

 for (i = 0; i < f; i++) 
    for (j = 0; j < c; j++) 
      printf("%d ", *(puntero + i * c + j));
 printf("\n");

 return EXIT_SUCCESS;

}


int main (void){
 
 int matriz[3][4] = {{ 1, 2, 3, 4}, { 5, 6, 7, 8}, { 9,10,11,12}};
 int *ptr=&matriz[0][0];
 int fila = sizeof(matriz) / sizeof(matriz[0]);
 int col = sizeof(matriz[0]) / sizeof(matriz[0][0]);


 imprimir(fila, col, matriz, ptr);

 return EXIT_SUCCESS;
	
}