/*Leer los strings del archivo del ej. anterior y mostrarlos en pantalla.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	int i, n; 
	char palabra[20]; 
	
	FILE *arch; 

	arch = fopen("palabras.dat", "rb"); 

	if (arch != NULL){
		for(i = 0; i < 5; i++){
			n = fread(&palabra, sizeof palabra, 1, arch); 
			
			if(n != 1){
				printf("Error al leer\n"); 
				fclose(arch);
				exit(1);
			}

			printf("%s \n", palabra); 	
		}
		
	} else {
		printf("Error al abrir el archivo para escritura \n"); 
		exit(2); 
	}

	fclose(arch); 

}


