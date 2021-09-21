/*Escribir un programa para leer el archivo vector .dat del ejercicio anterior y
almacenarlo en un vector. No se conoce la cantidad de elementos y no se puede
limitar.*/


#include <stdio.h>
#include <stdlib.h>

int* leer_archivo(){
/*Función que lee el archivo y lo almacena en un vector*/
	FILE *f; 
	int *v, n = 0; 

	f = fopen("vector.dat", "rb"); 

	if(f != NULL){
		v = malloc(sizeof(int)); //reservo un bloque de memoria

		while((fread(v + n, sizeof(int), 1, f)) > 0){
			//printf("%d\n", *(v+n)); -> Para verificar que lee bien
			n++;
			v = (int*) realloc(v, sizeof(int) * (n + 1)); //Voy reservando espacio para almacenar en el vector
		}

		*(v + n) = NULL; //warning, es para poder leer y verificar despues
		if(fclose(f) != 0) printf("Error cerrando\n"); 
	} else {
		printf("Error Abriendo"); 
	}

 

	return v; 

}



int main(){
	int *v, n = 0; 

	v = leer_archivo(); 

	while(*(v + n) != NULL){
		printf("%d\n", *(v+n)); // Para verificar que lee bien
		n++;
	}

	return 0; 
}
