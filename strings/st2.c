/* Leer un string por teclado y luego mostrarlo en orden inverso sin usar las
funciones de string.h */


#include <stdio.h>
#include <string.h>

int main(){
	char palabra[20]; 
	int tam, i; 

	printf("Ingrese una palabra: "); 
	scanf("%s", palabra);

	tam = strlen(palabra); 

	for(i = 0; i < tam + 1; i++){
		printf("%c", palabra[tam - i]); 
	}


	return 0; 
}