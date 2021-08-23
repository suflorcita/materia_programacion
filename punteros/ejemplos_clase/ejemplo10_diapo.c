/*
Ejemplo 9 Presentacion punteros
Muestra como recorrer un vector incrementando un puntero (aritmetica de punteros)
Programacion UNSAM
Autores: J. Bertinat, D. Lopez
Año: 2020
*/
#include <stdio.h>
int main () {
	int i;
    int v[4] = {10, 20, 30, 40}; /* Declaro un vector de 4 y lo inicializo con valores */
	int *p;
    
	p = v; /* Igual que hacer p = &v[0]; */
    
	for (i = 0; i < 4; i++) {
		printf ("Direccion: %p, valor: %d \n", p, *p);
		p++;
	}
    
	return 0;
}
