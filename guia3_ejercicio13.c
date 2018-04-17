#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	
#define MSJ_ERROR_PREFIJO "Error"
#define MSJ_LUGAR_ERROR_A "en la ejecucion de a."
#define MSJ_LUGAR_ERROR_B "en la ejecucion de b."
#define MSJ_LUGAR_ERROR_C "en la determinacion de cara o ceca."
#define MSJ_LUGAR_ERROR_D "en la impresion de la cara del dado."

#define MSJ_INCISO_A "El numero generado del inciso a) es"
#define MSJ_INCISO_B "El numero generado del inciso b) es"


#define MSJ_RESULTADO_0 "Ha salido cara" /*asignacion de cara a 0 fue arbitraria, idem para ceca*/
#define MSJ_RESULTADO_1 "Ha salido ceca"



void probabilidada(int x){

  x = x % 10;

  if(x>=8)
   printf("%s: %d\n", MSJ_INCISO_A, 0);
   
  else if(x<8)
   printf("%s: %d\n", MSJ_INCISO_A, 1);

 else 
   fprintf(stderr, "%s: %s\n", MSJ_ERROR_PREFIJO, MSJ_LUGAR_ERROR_A);

}

void probabilidadb(int x){

  x = x % 100;

  if (x<10)
   printf("%s: %d\n", MSJ_INCISO_B, 3);

  else if (x>=10 && x<65)
   printf("%s: %d\n", MSJ_INCISO_B, 5);

  else if (x>=65)
    printf("%s: %d\n", MSJ_INCISO_B, 9);
 
  else
   fprintf(stderr, "%s: %s\n", MSJ_ERROR_PREFIJO, MSJ_LUGAR_ERROR_B);

}

void probabilidadc (int x){

  x = x % 2;
 
  switch (x){

   case 0:
    printf("%s.\n", MSJ_RESULTADO_0);
    break;

   case 1:
    printf("%s.\n", MSJ_RESULTADO_1);
    break;

   default:
    fprintf(stderr, "%s: %s\n", MSJ_ERROR_PREFIJO, MSJ_LUGAR_ERROR_C);
    break;
  }
}

void probabilidadd (int x){

 x = 1 + x % 6;

 switch(x){
  case 1:
   printf("%s\n","|     |" );
   printf("%s\n","|  *  |" );
   printf("%s\n","|     |" );
   break;

  case 2:
   printf("%s\n","|    *|" );
   printf("%s\n","|     |" );
   printf("%s\n","|*    |" );
   break;

  case 3:
   printf("%s\n","|*    |" );
   printf("%s\n","|  *  |" );
   printf("%s\n","|    *|" );
   break;

  case 4:
   printf("%s\n","|*   *|" );
   printf("%s\n","|     |" );
   printf("%s\n","|*   *|" );
   break;

  case 5:
   printf("%s\n","|*   *|" );
   printf("%s\n","|  *  |" );
   printf("%s\n","|*   *|" );
   break;

  case 6:
   printf("%s\n","|*   *|" );
   printf("%s\n","|*   *|" );
   printf("%s\n","|*   *|" );
   break;

  default:
   fprintf(stderr, "%s: %s\n", MSJ_ERROR_PREFIJO, MSJ_LUGAR_ERROR_D);
   break;
 }

}



int main (void){
 
 int x;

 srand(time(NULL));
 x = rand();

 probabilidada(x);
 probabilidadb(x);
 probabilidadc(x);
 probabilidadd(x);

 return EXIT_SUCCESS;
}
