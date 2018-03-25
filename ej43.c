#include <stdio.h>
#include <stdlib.h>

#define  MSJ_ERROR_PREFIJO "Error"
#define MSJ_ERROR "El número ingresado es inválido."

#define MSJ_KM "Ingrese los kilometros recorridos (-1 para terminar):"
#define MSJ_PRECIO "Ingrese el precio del combustible por litro:"
#define MSJ_NAFTA "Ingrese el monto total utilizado en este compra:"
#define MSJ_RENDIMIENTO "Rendimiento (l/100km) de este tanque"

#define MSJ_REND_PROM "Rendimiento promedio (l/100km)"
#define MSJ_MEJOR_REND "Mejor rendimiento (l/100km)"
#define MSJ_PEOR_REND "Peor rendimiento (l/100km)"
#define MSJ_DIST "Distancia total recorrida (km)"
#define MSJ_COMB "Combustible total consumidos (l)"
#define MSJ_COSTO "Costo total de su vehiculo ($)"


int main (void){

	float km=0, precio=0, nafta=0, rendimiento=0;
	float prom=0, mejor=0, peor=100000, dist=0, combustible=0, costo=0;
	float R=0, i=0;

		
	
		while(km!=-1){

			printf("%s", MSJ_KM);
			scanf("%f", &km);

			if (km<-1){
	
				fprintf(stderr, "%s:%s\n", MSJ_ERROR_PREFIJO, MSJ_ERROR);
				return EXIT_FAILURE;
			} 

			if (km==-1){

				break;
			}

			printf("%s", MSJ_PRECIO);
			scanf("%f", &precio);

			if (precio<0){
	
				fprintf(stderr, "%s:%s\n", MSJ_ERROR_PREFIJO, MSJ_ERROR);
				return EXIT_FAILURE;
			} 

			printf("%s", MSJ_NAFTA);
			scanf("%f", &nafta);

			if (nafta<0){
	
				fprintf(stderr, "%s:%s\n", MSJ_ERROR_PREFIJO, MSJ_ERROR);
				return EXIT_FAILURE;
				} 

			rendimiento=(nafta/precio)/km*100;

			printf("%s>>%.2f\n",MSJ_RENDIMIENTO, rendimiento);

			R+=rendimiento;

			if(rendimiento>mejor)
			{
				mejor=rendimiento;
			}

			if (rendimiento<peor)
			{
				peor=rendimiento;
			}

			dist+=km;
			combustible+=(nafta/precio);
			costo+=nafta;
			i++;
		}

		prom=R/i;

		printf("%s >> %.2f \n", MSJ_REND_PROM,prom);
		printf("%s >> %.2f \n", MSJ_MEJOR_REND,mejor);
		printf("%s >> %.2f \n", MSJ_PEOR_REND,peor);
		printf("%s >> %.2f \n", MSJ_DIST,dist);
		printf("%s >> %.2f \n", MSJ_COMB,combustible);
		printf("%s >> %.2f \n", MSJ_COSTO,costo);

return 0;

}

