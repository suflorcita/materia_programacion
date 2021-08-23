/*
Ejemplo 7 Presentacion punteros
Muestra el uso de una variable de tipo puntero para acceder y modificar el valor de una variable
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

	/* Ahora vemos los valores mediante indireccion */
	printf("La dirección de memoria de x es %p y el valor asignado es %d \n", puntero, *puntero);

	(*puntero)++; /* Incremento el valor apuntado por puntero (o sea el valor de x) */

	printf("La dirección de memoria de x es %p y el valor asignado es %d \n", puntero, *puntero);	

	return 0;
}

