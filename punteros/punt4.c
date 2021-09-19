/*Escribir una función que reciba un vector de enteros y su tamaño, y devuelva la
cantidad de números impares que contiene.
int impares (int *v, int tam);*/


#include <stdio.h>

int impares(int *v, int tam){
/*Función que devuelve la cantidad de números impares en un */

	int cant = 0; 

	for(int i = 0; i < tam; i++){
		if((*(v + i) % 2) != 0) cant ++; 
	}

	return cant; 
}


int main(){
/*pruebo la función*/

	int prueba[9] = {1, 4, 5, 6, 7, 7, 8, 9, 3}; 
	int tamanio = 9; 
	int cantidad_impares; 

	cantidad_impares = impares(&prueba[0], tamanio); 

	printf("Hay %d números impares\n", cantidad_impares); 

	return 0; 
}