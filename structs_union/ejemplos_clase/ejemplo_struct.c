/*
Programacion UNSAM
Autor: David Lopez
Año: 2020
Ejemplo de estructuras:
Este programa permite ingresar por teclado los datos (codigo, nombre, precio y stock)
de una cant. indefinida de productos finalizando cuando el codigo ingresado es cero. 
Los productos se almacenan en un vector que luego se recorre y se muestra por pantalla.
*/

#include <stdio.h>
#define MAX 1000

/*Aca se define el tipo de datos*/
struct producto {   
    int codigo;
    char nombre[10];
    float precio;
    long stock;
};

/* Esta funcion recibe una estructura de tipo producto y muestra sus campos */
void muestra_producto (struct producto p) {
    printf ("Codigo: %d - Nombre: %s - Precio %.2f - Stock: %ld\n", p.codigo, p.nombre, p.precio, p.stock);
}

/* Esta funcion recibe un vector de estructuras de tipo producto y lo recorre */
void muestra_vector (struct producto v[], int cant) {
    int i;
    
    for (i=0; i < cant; i++) {
        muestra_producto (v[i]);
    }
}

int main () {
    int cod, i = 0;
    /* Declaro vector de estructuras */
    struct producto vp[MAX];

    /* Ingresar cod */
    printf ("Ingrese un codigo: ");
    scanf ("%d", &cod);
    while (cod != 0) {
        /* setear cod */
        vp[i].codigo = cod;
        /* ingresar otros campos */
        printf ("Ingrese el nombre del producto %d: ", cod);
        scanf ("%s", vp[i].nombre);
        printf ("Ingrese el precio: ");
        scanf ("%f", &vp[i].precio);
        printf ("Ingrese el stock: ");
        scanf ("%ld", &vp[i].stock);

        /* Incremento contador de productos ingresados */
        i++;
        /* Pregunto un nuevo codigo */
        printf ("Ingrese otro codigo: ");
        scanf ("%d", &cod);
    }
    
    muestra_vector (vp, i);
    return 0;
}

