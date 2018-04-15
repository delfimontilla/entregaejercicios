#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI 
#define M_PI 3.14159
#endif

#define MSJ_ERROR_PREFIJO "Error"
#define MSJ_ERROR_NUM_INVALIDO "El número ingresado es inválido."
#define MSJ_ERROR_NO_NUMERO "Debe ingresar un número."


#define MSJ_INGRESO_ALTURA "Ingrese la altura del cilindro"
#define MSJ_INGRESO_RADIO "Ingrese el radio del cilindro"
#define MSJ_RESULTADO_DIAMETRO "El diametro es"
#define MSJ_RESULTADO_CIRCUNFERENCIA "La circunferencia es"
#define MSJ_RESULTADO_BASE "La base es"
#define MSJ_RESULTADO_VOLUMEN "El volumen es"

float cilindro_diametro(float radio){

 return radio*2;
}

float cilindro_circunferencia(float radio){

 return 2*M_PI*radio;
}

float cilindro_base(float radio){

 return M_PI*radio*radio;
}

float cilindro_volumen(float radio, float altura){

 return M_PI*radio*radio*altura;
}

int main (void){
 
 float altura=0, radio=0, diametro=0, circunferencia=0, base=0, volumen=0;

 printf("%s:\n", MSJ_INGRESO_ALTURA);

 if (scanf("%f",&altura)!=1){
  fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_NO_NUMERO);
  return EXIT_FAILURE;
 }
 
 while ((getchar())!='\n');

 printf("%s:\n", MSJ_INGRESO_RADIO);

 if (scanf("%f",&radio)!=1){
  fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_NO_NUMERO);
  return EXIT_FAILURE;
 }
	
 while((getchar())!='\n');

 diametro = cilindro_diametro(radio);
 circunferencia = cilindro_circunferencia(radio);
 base = cilindro_base(radio);
 volumen = cilindro_volumen(radio,altura);

 printf("%s: %.4f\n", MSJ_RESULTADO_DIAMETRO, diametro);
 printf("%s: %.4f\n", MSJ_RESULTADO_CIRCUNFERENCIA, circunferencia);
 printf("%s: %.4f\n", MSJ_RESULTADO_BASE, base);
 printf("%s: %.4f\n", MSJ_RESULTADO_VOLUMEN, volumen);

 return EXIT_SUCCESS;
}