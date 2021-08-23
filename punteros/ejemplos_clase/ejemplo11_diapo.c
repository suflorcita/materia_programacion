/*
Ejemplo 10 Presentacion punteros
Muestra varias acciones usando aritmetica de punteros
Programacion UNSAM
Autores: J. Bertinat, D. Lopez
Año: 2020
*/
#include <stdio.h>
int main () {
	int v[4] = {10, 20, 30, 40};
	int *p;
	
	p = v; /* Apunto p al primer elemento del vector */

	/* v++; //Daria error de compilacion (los nombres de vectores estaticos no se pueden modifcar) */
	p++; /* OK. Avanza el puntero 4 bytes (una posicion int) */
	printf ("%d \n", *p); /* Imprime 20 */
	printf ("%d \n", *(v + 1)); /* OK. Imprime 20 */
	printf ("%d \n", *(p + 1)); /* OK. Imprime 30 */
	printf ("%d \n", *(p + 3)); /* Que pasa en este caso????? */

	return 0;
}
