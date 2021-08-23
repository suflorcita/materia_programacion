/*
Ejemplo de revision: Lectura de archivo
Se tiene el archivo binario "datos.dat" con una cantidad desconocida de valores enteros (int).
Escribir un programa que lea y muestre en panatalla dichos valores.
Programacion UNSAM
Autor: David Lopez
Año: 2020
*/

#include <stdio.h>

int main(){
    int res, aux;
    FILE *f;

    /* Abrir archivo para lectura en modo binario */
    f = fopen("datos.dat", "rb"); /*b significa binario. No tiene efecto en Linux */
    if (f == NULL) {
        printf("\nError al abrir el archivo\n");
        return 1;
    }

    /* Leer archivo */
    res = fread(&aux, sizeof aux, 1, f); /* Leer un entero */
    while (res == 1) {
        printf("\nDato: %10d", aux);
        res = fread(&aux, sizeof aux, 1, f);
    }

    /* Cerrar archivo */
    res = fclose(f);
    if (res != 0) {
        printf("\nError al cerrar el archivo\n");
        return 2;
    }

    printf("\n");
    return 0; /* Si llego hasta aca no hubo errores */
}