/*Leer por teclado los detalles (legajo, nombre, promedio) de n estudiantes (n <
100) y almacenarlo en el archivo estudiantes.dat.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/*Defino un struct con los datos del estudiante*/
struct estudiante{
	int legajo; 
	char nombre[100]; 
	float promedio;

}; 

int main(){
	int leg, i = 0; 
	struct estudiante ve[MAX]; // declaro vector de estudiantes

	FILE *arch; 
	

	arch = fopen("estudiantes.dat", "wb"); //abro el archivo 

	if (arch == NULL){
		printf("Error al abrir el archivo para escritura \n"); 
		exit(1); 
	}

	printf("Ingrese el número de legajo, si ingresa 0 termina el programa: "); 
	scanf("%d", &leg); 

	while (leg != 0){
		ve[i].legajo = leg; 

		printf("Ingrese el nombre del alumno: "); 
		scanf("%s", ve[i].nombre); 

		printf("Ingrese el promedio del estudiante: "); 
		scanf("%f", &ve[i].promedio); 

		fwrite(&ve[i], sizeof ve[i],1,arch); //Escribo en el archivo la información de cada estudiante 

		i++; 
		
		printf("Ingrese el número de legajo, si ingresa 0 termina el programa: "); 
		scanf("%d", &leg); 

	}

	fclose(arch); //cierro el archivo

	

	return 0; 
}