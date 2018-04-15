#include <stdio.h>
#include <stdlib.h>

#define MSJ_ERROR_PREFIJO "Error"
#define MSJ_ERROR_NUM_INVALIDO "El número ingresado es inválido."
#define MSJ_ERROR_CASO_INVALIDO "El caso es inválido."
#define MSJ_ERROR_NO_NUMERO "Debe ingresar un número."

#define MSJ_INGRESO "Ingrese la temperatura de la estrella"

#define MSJ_COLOR_O "Su color: azul"
#define MSJ_COLOR_B "Su color: blanco azulado"
#define MSJ_COLOR_A "Su color: blanco"
#define MSJ_COLOR_F "Su color: blanco amarillento"
#define MSJ_COLOR_G "Su color: amarillo"
#define MSJ_COLOR_K "Su color: naranja"
#define MSJ_COLOR_M "Su color: rojo"

typedef enum {O,A,B,F,G,K,M} espectral_t; 


int main (void) {
	
  int t;
  espectral_t clase;

  printf("%s:\n", MSJ_INGRESO);
	
  if (scanf("%d",&t) == 1){

   if(t>=28000 && t<=50000)
    clase = O;

   else if(t>=9600 && t<28000)
    clase = B;

   else if(t>=7100 && t<9600)
    clase = A;

   else if(t>=5700 && t<7100)
    clase = F;

   else if(t>=4600 && t<5700)
    clase = G;

   else if(t>=3200 && t<4600)
    clase = K;

   else if(t>=1700 && t<3200)
    clase = M;

   else if(t>50000 || t<1700){
    fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_NUM_INVALIDO);
    return EXIT_FAILURE;
   }
   
  } 

   else { 
    fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_NO_NUMERO);
    return EXIT_FAILURE;
   } 

  switch(clase){
    case O:
     printf("%s\n", MSJ_COLOR_O);
     break;

    case B:
     printf("%s\n", MSJ_COLOR_B);
     break;
      
    case A:
     printf("%s\n", MSJ_COLOR_A);
     break;

    case F:
     printf("%s\n", MSJ_COLOR_F);
     break;

    case G:
     printf("%s\n", MSJ_COLOR_G);
     break;

    case K:
     printf("%s\n", MSJ_COLOR_K);
     break;

    case M:
     printf("%s\n", MSJ_COLOR_M);
     break;

    default:
     fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_CASO_INVALIDO);
     break;
  }

 return EXIT_SUCCESS;

}
