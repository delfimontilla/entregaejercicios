#include <stdio.h>
#include <stdlib.h>

#define MSJ_INGRESO_MATRIZ "Ingrese elementos de la matriz"
#define MSJ_INGRESO_ELEMENTO "Ingrese el elemento"
#define MSJ_INGRESO_FILAS "Ingrese la cantidad de filas"
#define MSJ_INGRESO_COLUMNAS "Ingrese la cantidad de columnas"
#define MSJ_INGRESO_NUMERO_B "Ingrese un numero para sumar a los componentes de la matriz"
#define MSJ_INGRESO_NUMERO_C "Ingrese un numero para multiplicar a los componentes de la matriz"


#define MSJ_ERROR_PREFIJO "Error"
#define MSJ_ERROR_NUM_INVALIDO "El número ingresado es inválido."
#define MSJ_ERROR_NO_NUMERO "Debe ingresar un número."
#define MSJ_MATRIZ_NO_CUAD "La matriz no es cuadrada."
#define MSJ_MATRIZ_NO_VALIDA "La matriz no es 2x2 o 3x3."

#define MSJ_RESULTADO_TRAZA "La traza de la matriz es"
#define MSJ_RESULTADO_SUMA_COMP "El resultado de la suma del numero con los componentes es"
#define MSJ_RESULTADO_PRODUCTO_COMP "El resultado del producto del numero con los componentes es"
#define MSJ_RESULTADO_TRANSPUESTA "La matriz transpuesta es"
#define MSJ_RESULTADO_MATRIZB "La matriz b es"
#define MSJ_RESULTADO_TIPO_MATRIZ "La matriz es"
#define MSJ_RESULTADO_POSITIVA "positiva"
#define MSJ_RESULTADO_NO_NEGATIVA "no negativa"
#define MSJ_RESULTADO_NEGATIVA "negativa"
#define MSJ_RESULTADO_NO_POSITIVA "no positiva"
#define MSJ_RESULTADO_INDETERMINADA "indeterminada, no cumple ninguna de las condiciones"
#define MSJ_RESULTADO_DETERMINANTE "El determinante de la matriz es"
#define MSJ_RESULTADO_MAXIMO "El componente maximo de la matriz es"
#define MSJ_RESULTADO_SUMA_COL "El máximo de la suma, en valores absolutos, de los elementos de cada columna es"
#define MSJ_RESULTADO_SUMA_FIL "El máximo de la suma, en valores absolutos, de los elementos de cada fila es"



int traza(int (* const m)[2],int nfilas,int ncols){

 int suma=0, i=0;

 if(nfilas!=ncols){
  	fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_MATRIZ_NO_CUAD);
  	return EXIT_FAILURE;
  }

 for(i=0; i<nfilas; i++)
  suma+=m[i][i];

 return suma;
}

int suma_componentes(int (* const m)[2],int nfilas,int ncols){

 int i=0, j=0, b=0;	
 
 printf("%s:\n", MSJ_INGRESO_NUMERO_B);
 if((scanf("%d",&b))!=1){
  fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_NO_NUMERO);
  return EXIT_FAILURE;
  }

 printf("%s:\n", MSJ_RESULTADO_SUMA_COMP);
 for(i=0; i<nfilas; i++){
  for(j=0; j<ncols; j++){
   printf("%d  ", m[i][j]+b);
   if (j == ncols-1)
     printf("\n");
  }
 }

 return EXIT_SUCCESS;
}

int prod_componentes(int (* const m)[2],int nfilas,int ncols){

 int i=0, j=0, c=0;	
 
 printf("%s:\n", MSJ_INGRESO_NUMERO_C);
 if((scanf("%d",&c))!=1){
  fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_NO_NUMERO);
  return EXIT_FAILURE;
  }

 printf("%s:\n", MSJ_RESULTADO_PRODUCTO_COMP);
 for(i=0; i<nfilas; i++){
  for(j=0; j<ncols; j++){
   printf("%d  ", m[i][j]*c);
   if (j == ncols-1)
     printf("\n");
  }
 }
 return EXIT_SUCCESS;
} 


int transpuesta(int (* const m)[2],int nfilas,int ncols){

 int i=0, j=0;	
 int matriz_t[2][2];

 
 for(i=0; i<nfilas;  i++){
  for(j=0; j<ncols; j++)
  	matriz_t[j][i]=m[i][j];
 }

 printf("%s:\n", MSJ_RESULTADO_TRANSPUESTA);
 for(i=0; i<ncols; i++){ 
  for(j=0; j<nfilas; j++){
   printf("%d  ", matriz_t[i][j]);
   if (j == nfilas-1)
     printf("\n");
  }
 }
 return EXIT_SUCCESS;
} 

int tipo_de_matriz(int (* const m)[2],int nfilas,int ncols){

 int i=0, j=0, positivos=0, negativos=0, ceros=0;	
 
 for(i=0; i<nfilas; i++){
  for(j=0; j<ncols; j++){
    if(m[i][j]>0)
      positivos+=1;
    else if (m[i][j]<0)
      negativos+=1;
    else if (m[i][j]==0)
      ceros+=1;
  } 	
 }
  
  if(positivos==4)
   printf("%s %s\n", MSJ_RESULTADO_TIPO_MATRIZ, MSJ_RESULTADO_POSITIVA);

  else if(negativos==4)
   printf("%s %s\n", MSJ_RESULTADO_TIPO_MATRIZ, MSJ_RESULTADO_NEGATIVA);

  else if(positivos>0 && positivos<4 && ceros>0 && negativos==0)
   printf("%s %s\n", MSJ_RESULTADO_TIPO_MATRIZ, MSJ_RESULTADO_NO_NEGATIVA);

  else if(negativos>0 && negativos<4 && ceros>0 && positivos==0)
   printf("%s %s\n", MSJ_RESULTADO_TIPO_MATRIZ, MSJ_RESULTADO_NO_POSITIVA);

  else
   printf("%s %s\n", MSJ_RESULTADO_TIPO_MATRIZ, MSJ_RESULTADO_INDETERMINADA);


 return EXIT_SUCCESS;

}

int determinante(int (* const m)[2],int nfilas,int ncols){

 int determinante=0;

 if(nfilas!=ncols){
  	fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_MATRIZ_NO_CUAD);
  	return EXIT_FAILURE;
  }

 switch (nfilas){

  case 2:
   determinante=m[0][0]*m[1][1]-m[0][1]*m[1][0];
   break;

  case 3:
   determinante=m[0][0]*m[1][1]*m[2][2]-m[1][2]*m[0][1]*m[2][0]-m[1][0]*m[2][1]*m[0][2]-m[0][2]*m[1][1]*m[2][0]-m[1][2]*m[2][1]*m[0][0]-m[1][0]*m[0][1]*m[2][2];
   break;

  default:
   fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_MATRIZ_NO_VALIDA);
   break;
 }

 return determinante;
}

int maximo_componente(int (* const m)[2],int nfilas,int ncols){

 int i=0, j=0, maximo=0; 

 maximo=m[0][0];
 
 for(i=0; i<nfilas; i++){
  for(j=0; j<ncols; j++){
    if(m[i][j]>maximo)
      maximo=m[i][j];
  }  
 }

 return maximo;
}


int suma_columna(int (* const m)[2],int nfilas,int ncols){

 int i=0, j=0, maximo_col=0, s_columnas[2]={0,0}; 

for(j=0; j<ncols; j++){
   for(i=0; i<nfilas; i++){
    if(m[i][j]<0)
      s_columnas[j]-=m[i][j];
    else if(m[i][j]>0)
      s_columnas[j]+=m[i][j];

  }  
 }

 for(j=0; j<ncols; j++){
  if(s_columnas[j]>maximo_col)
  	maximo_col=s_columnas[j];
 }

 return maximo_col;
}


int suma_fila(int (* const m)[2],int nfilas,int ncols){

 int i=0, j=0, maximo_fil=0, s_filas[2]={0,0}; 

 for(i=0; i<nfilas; i++){
  for(j=0; j<ncols; j++){
    if(m[i][j]<0)
      s_filas[i]-=m[i][j];
    else if(m[i][j]>0)
      s_filas[i]+=m[i][j];

  }  
 }

 for(i=0; i<nfilas; i++){
  if(s_filas[i]>maximo_fil)
  	maximo_fil=s_filas[i];
 }

 return maximo_fil;
}


int main (void){

 int nfilas=0, ncols=0;	
 int m[2][2]={{1,0},{3,4}};
 int resultado_traza=0, resultado_determinante=0, maximo=0, resultado_sumacolumna=0, resultado_sumafila=0;

 nfilas = sizeof(m) / sizeof(m[0]);
 ncols = sizeof(m[0]) / sizeof(m[0][0]);

 resultado_traza=traza(m,nfilas,ncols);
 printf("%s:%d.\n", MSJ_RESULTADO_TRAZA, resultado_traza);

 suma_componentes(m,nfilas,ncols);

 prod_componentes(m,nfilas,ncols);

 transpuesta(m,nfilas,ncols);

 tipo_de_matriz(m,nfilas,ncols);

 resultado_determinante=determinante(m,nfilas,ncols);
 printf("%s:%d\n",MSJ_RESULTADO_DETERMINANTE,resultado_determinante);

 maximo=maximo_componente(m,nfilas,ncols);
 printf("%s:%d\n",MSJ_RESULTADO_MAXIMO,maximo);

 resultado_sumacolumna=suma_columna(m,nfilas,ncols);
 printf("%s:%d\n",MSJ_RESULTADO_SUMA_COL,resultado_sumacolumna);

 resultado_sumafila=suma_fila(m,nfilas,ncols);
 printf("%s:%d\n",MSJ_RESULTADO_SUMA_FIL,resultado_sumafila);

 return EXIT_SUCCESS;
	
}