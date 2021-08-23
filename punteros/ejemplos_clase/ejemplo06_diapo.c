/*
Ejemplo 6 Presentacion punteros
Muestra el uso de una variable de tipo puntero
Programacion UNSAM
Autores: J. Bertinat, D. Lopez
Año: 2020
*/
#include <stdio.h>

int main (void){
	
	int x;
	int *puntero; /*  El * significa que es un puntero */

	x = 2;
	puntero = &x; /* Almaceno en puntero la direccion de x */

	printf("La dirección de memoria de x es %p y el valor asignado es %d \n", &x, x);
	printf("La dirección de memoria de puntero es %p y el valor asignado es %p \n", &puntero, puntero);
	
	return 0;
}

