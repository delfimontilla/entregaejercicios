#include <stdio.h>
#include <stdlib.h>

#define  MSJ_ERROR_PREFIJO "Error"
#define MSJ_ERROR_DIA_INV "El día ingresado es inválido."

#define DIA_MIN 1
#define DIA_MAX 366

int main (void)
{

	int dia=0;

	puts("Ingrese el día del año:");

	scanf("%d", &dia);

	if (dia<DIA_MIN || dia>DIA_MAX){
	
	fprintf(stderr, "%s:%s\n", MSJ_ERROR_PREFIJO, MSJ_ERROR_DIA_INV);

	return EXIT_FAILURE;
	}

	dia%=7;


	switch (dia)
  {
     case 1:     
     	printf ("Lunes\n");     
     	break;

     case 2:   
     	printf ("Martes\n");   
     	break;

     case 3:    
     	printf ("Miércoles\n"); 
     	break;

     case 4:    
     	printf ("Jueves\n");     
     	break; 

     case 5:    
     	printf ("Viernes\n");     
     	break;

     case 6:    
     	printf ("Sábado\n");     
     	break; 

     case 7:  
     	printf ("Domingo\n"); 
     	break;

     default:
     	if (dia<DIA_MIN || dia>DIA_MAX){
	
		fprintf(stderr, "%s:%s\n", MSJ_ERROR_PREFIJO, MSJ_ERROR_DIA_INV);

		return EXIT_FAILURE;
		}
	}

	return 0;
}