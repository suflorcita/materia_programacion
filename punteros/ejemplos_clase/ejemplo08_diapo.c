/*
Ejemplo 8 Presentacion punteros
Muestra la relacion entre los vectores y los punteros. Notar que el nombre del vector actua como un puntero
Programacion UNSAM
Autores: J. Bertinat, D. Lopez
Año: 2020
*/
#include <stdio.h>

int main ()
    {
    char v[10];

    v[0]=15;
    v[4]=32;

    printf("\n");
    printf("%p \n", v); /* imprime la dir. de comienzo del vector */
    printf("%hhd \n", *v); /* imprime el valor del primer elemento (15) */
    printf("%hhd \n", *(v+4)); /* imprime el valor del elemento 4 (32) */
    
    return 0;
}

