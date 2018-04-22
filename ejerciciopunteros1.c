#include <stdio.h>
#include <stdlib.h>

#define MSJ_ERROR_PREFIJO "Error"
#define MSJ_ERROR_NO_NUMERO "Debe ingresar un número."

#define MSJ_INGRESO_NUMERO "Ingrese un numero que representa una cantidad de segundos"
#define MSJ_RESULTADO "Los segundos ingresados equvalen a"

int conv_horario(int *tiempo){
 
 int h=0, m=0, s=0;

 h=*tiempo/3600;

 m=(*tiempo%3600)/60;
 
 s= (*tiempo%3600)%60;
 
 printf("%s: %dh %dm %ds.\n",MSJ_RESULTADO, h,m,s);

 return EXIT_SUCCESS;
}


int main (void){

 int numero=0;
 int *ingreso=NULL;

 ingreso=&numero;

 printf("%s\n", MSJ_INGRESO_NUMERO);
	
 if((scanf("%d",&numero))!=1){
  fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_NO_NUMERO);
  return EXIT_FAILURE;
 }

 while((getchar())!='\n');

 conv_horario(ingreso);

 return EXIT_SUCCESS;
	
}