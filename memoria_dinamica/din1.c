/*Escribir un prog. en el que el usuario informa la cantidad de elementos que va a
ingresar y luego los valores de los elementos (enteros).
Los elementos deben almacenarse en un vector y luego en el archivo vector.dat. No
se debe limitar la cantidad de elementos.*/


#include <stdio.h>
#include <stdlib.h>

void escribir_archivo(int *v, int n){
/*Función que escribe en el archivo vector.dat*/
	FILE *f; 
	int j; 

	f = fopen("vector.dat", "wb"); 
	if(f != NULL){
		j = fwrite(v, sizeof(int), n, f); //Grabo el vector en vector.dat 
		if(j != n){
			printf("Error grabando\n"); 
		}

		if (fclose (f) != 0)
			printf ("Error cerrando\n");

	} else{
		printf("Error creando\n");  
	}

}

void leer_archivo(int n){
/*Función que lee el archivo y presenta los valores escritos en pantalla*/
	FILE *f; 
	int *v, r; 

	v = (int*) malloc(sizeof (int) * n);//Reservo n lugares de memoria 
	f = fopen("vector.dat", "rb"); 

	if(f != NULL){
		r = fread(v, sizeof(int), n, f); 
		if(r != n) printf("Error escribiendo\n"); 
		if(fclose(f) != 0) printf("Error cerrando\n"); 

	} else {
		printf("Error Abriendo"); 
	}

	for(int i = 0; i < n; i ++){
		printf("El valor del elemento %d es:\t%d\n",i, *(v + i)); 
	}

}


int* ingresar_vector(int *v, int n){
/*Función que ingresa los valores de un vector*/

	v = (int*) realloc(v, sizeof (int)*n); //Cambio el valor de vector a N 	
	for(int i = 0; i < n; i++){
		printf("Ingrese el elemento %d: ", i); 
		scanf("%d", v + i); 
	} //Ingreso los valores de los elementos y los almaceno en el vector 

	return v; 
}



int main(){
	int n, *vec = NULL; 

	printf("Ingrese la cantidad de elementos que va a ingresar: "); 
	scanf("%d", &n); 

	vec = ingresar_vector(vec, n); 

	escribir_archivo(vec, n); //Escribo en el archivo 
	leer_archivo(n); //Leo el archivo para verificar 
	free(vec); //Libero el puntero

	return 0;
}





