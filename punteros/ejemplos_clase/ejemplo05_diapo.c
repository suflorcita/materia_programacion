/*
Ejemplo 5 Presentacion punteros
Muestra el uso del operador & (indireccion)
Programacion UNSAM
Autores: J. Bertinat, D. Lopez
Año: 2020
*/
#include <stdio.h>

int main (void){

	int x = 2;

	printf("El valor de x es: %d \n", x); /*  imprime 2 */
	printf("La dirección de memoria de x es: %p \n", &x); /*  imprime la direccion, ej 0x7fff20ff030c */
	return 0;
}

