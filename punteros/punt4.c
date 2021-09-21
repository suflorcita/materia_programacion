/*Escribir una función que reciba un vector de enteros y su tamaño, y devuelva la
cantidad de números impares que contiene.
int impares (int *v, int tam);*/


#include <stdio.h>

int impares(int *v, int tam){
/*Función que devuelve la cantidad de números impares en un vector de enteros*/

	int cant = 0; 

	for(int i = 0; i < tam; i++){
		if((*(v + i) % 2) != 0) cant ++; 
	}

	return cant; 
}


int main(){
/*pruebo la función*/

	int vector[100]; 
	int tamanio; 
	int cantidad_impares; 

	printf("Ingrese tamaño del vector: "); 
	scanf("%d", &tamanio);

	for(int i = 0; i < tamanio; i++){
		printf("Ingrese el elemento %d del vector: ", i); 
		scanf("%d", &vector[i]); 
	}

	cantidad_impares = impares(vector, tamanio); 

	printf("Hay %d número(s) impar(es).\n", cantidad_impares); 

	return 0; 
}