/*Escriba la siguiente función:
int *crear_vector (int n, int valor_inicial);
La función debe retornar un puntero a un vector de enteros de tamaño n creado
dinámicamente cuyas posiciones son inicializadas con valor_inicial. La
función debe retornar NULL si no se puede reservar la memoria */


#include <stdio.h>
#include <stdlib.h>

int *crear_vector(int n, int valor_inicial){
	int *vec = NULL;

	vec = malloc(sizeof(int) * n); //reservo n bloques de memoria 
	for(int i = 0; i < n; i ++){
		*(vec + i) = valor_inicial; 
	}
 
	return vec; 
}
int main(){
	int *v, n, valor_inicial;

	printf("Ingresa el tamaño del vector: "); 
	scanf("%d", &n); 

	printf("Ingrese el valor para inicializarlo: ");
	scanf("%d", &valor_inicial); 


	v = crear_vector(n, valor_inicial); 

	for(int i = 0; i < n; i++){  // Verifico lo q hay en el vector 
		printf("%d\n", *(v + i)); 
	} 

	free(v); 
	return 0; 
}