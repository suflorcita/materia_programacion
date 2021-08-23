/*
Ejemplo 9 Presentacion punteros
Muestra la relación entre las filas de una matriz y los vectores
Programacion UNSAM
Autores: J. Bertinat, D. Lopez
Año: 2020
*/
#include <stdio.h>

int main (void){

    char m[3][2];
    char *p;

    m[0][0] = 'a';
    m[0][1] = 'b';
    m[1][0] = 'c';
    m[1][1] = 'd';
    m[2][0] = 'e';
    m[2][1] = 'f';
    
    p = m[2]; /* Vector "ultima fila" */
    printf("%c \n", p[1]); /* Imprime 'f' */

    return 0;
}