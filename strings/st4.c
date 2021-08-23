/*Leer 5 strings por teclado y mostrar el de mayor longitu*/


#include <stdio.h>
#include <string.h>


int main(){

	char palabra[20], mayor[20];  
	int i, len, max = -1; 

	for(i = 0; i < 5; i++){
		printf("Ingrese una palabra: "); 
		scanf("%s", palabra); 

		len = strlen(palabra); 
		
		if(len > max){
			strcpy(mayor, palabra); 
			max = strlen(palabra);  
		}; 
	}

	printf("La palabra de mayor longitud es %s\n", mayor); 


	return 0; 
}