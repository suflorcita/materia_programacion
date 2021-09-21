/*Implemente una función que reciba un vector de números en punto flotante y un
entero que representa el tamaño del vector y devuelva el promedio.
Usar notación aritmética de punteros (no subíndices []) para recorrer el vector.*/


#include <stdio.h>

float promedio(float *vec, int tamanio){
	/*Función que recibe un vector de números en punto flotante 
	y un entero que representa el tamaño de un vector y devuelve el promedio */
	float suma = 0; 
	float promedio; 

	for(int i = 0; i < tamanio; i++){
		suma += *(vec + i); 

	}
	promedio = suma / tamanio; 

	return promedio; 
}


int main(){
	float vec[100], prom; 
	int tamanio; 

	printf("Ingrese el tamaño del vector: "); 
	scanf("%d", &tamanio); 

	for(int i = 0; i < tamanio; i++){
		printf("Ingrese el elemento %d del vector: ", i); 
		scanf("%f", (vec + i)); 

	}

	prom = promedio(vec, tamanio); 

	printf("El promedio de los numeros del vector es %.2f\n", prom); 


	return 0; 
}