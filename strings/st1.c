/*Leer un string por teclado y luego convertirlo a mayúsculas sin usar las
funciones de string.h (ayuda: piense en los códigos ASCII y el nro. 32)*/

#include <stdio.h>
#include <string.h>

int main(){
	char palabra[20]; 
	int tam, i; 

	printf("Ingrese una palabra\n"); 
	scanf("%s", palabra);

	tam = strlen(palabra); 

	for(i = 0; i < tam; i++){
		printf("%c", palabra[i] - 32); 
	}


	return 0; 
}