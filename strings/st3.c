/* Leer 5 strings por teclado y mostrar el “mayor” (alfabéticamente)  */

#include <stdio.h>
#include <string.h>

int main(){

	char palabra[20], mayor[20]; 
	int comp, i;


	printf("Ingrese una palabra: "); 
	scanf("%s", mayor); 


	for(i = 0; i < 4; i++){
		printf("Ingrese otra palabra: ");
		scanf("%s", palabra); 

		comp = strcmp(palabra, mayor);

		if(comp > 0) strcpy(mayor, palabra); 
	}

	printf("%s", mayor); 

	return 0; 

}