/*Escribir una función que devuelva un puntero al máximo valor de un vector de
“doubles”. Si el vector está vacío (cant = 0) la función debe retornar NULL.
double* max (double *v, int cant);*/


#include <stdio.h>


double* max (double *v, int cant){
/* Función que devuelve un puntero al máximo valor de un vector de doubles y si no retorna null */
	double* maximo = v; 

	if(cant > 0){
		for(int i = 0; i < cant; i++){
			
			if (*(v + i) > *maximo) {
				maximo = (v + i); 
			}
		}
	} else {
		maximo = NULL; 
	}
	
	return maximo; 
}

int main(){
/*Pruebo la función*/	
	double vec[100]; 
	double* maxi; 
	int tamanio; 

	printf("Ingrese el tamaño del vector: "); 
	scanf("%d", &tamanio); 

	for(int i = 0; i < tamanio; i++){
		printf("Ingrese la posición %d del vector: ", i); 
		scanf("%lf", &vec[i]); 
	}

	maxi = max(vec, tamanio); 

	if (maxi != NULL){
		printf("El valor máximo del vector es %.2lf \n", *maxi); 
	} else {
		printf("El puntero tiene valor NULL\n"); 
	}

	return 0; 
}