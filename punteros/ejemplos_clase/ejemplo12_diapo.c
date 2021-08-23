/*
Ejemplo 11 Presentacion punteros
Muestra la diferencia entre el pasaje de argumentos por valor y por referencia 
Programacion UNSAM
Autores: J. Bertinat, D. Lopez
Año: 2020
*/
#include <stdio.h>

/* Esta funcion recibe 2 enteros short (el primero por valor y el segundo por referencia) y los incrementa */
void incrementa (short x, short *y) {
	x++;
	(*y)++;
}
	
int main () {
	short a = 1, b = 2, *p;
	
	p = &b;
    
	printf ("Antes de invocar a incrementa: a:%d b:%d\n", a, b); /* Imprime 1 y 2 */
	incrementa (a, p);
	printf ("Despues de invocar a incrementa: a:%d b:%d\n", a, b); /* Que imprime? */

	return 0;
}
