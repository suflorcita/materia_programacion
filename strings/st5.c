
/*Leer 5 strings por teclado y almacenarlos en un archivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	int i, n; 
	char palabra[20]; 
	
	FILE *arch; 

	arch = fopen("palabras.dat", "wb"); 

	if (arch != NULL){
		for(i = 0; i < 5; i++){

			printf("Ingrese una palabra: "); 
			scanf("%s", palabra); 

			n = fwrite(&palabra, sizeof(palabra), 1, arch); 
			if (n != 1){
				printf("Error al grabar\n"); 
				fclose(arch); 
				exit(1);
			} 
		}
	} else {
		printf("Error al abrir el archivo para escritura \n"); 
		exit(2); 
	}

	fclose(arch); 

}


