/*Leer el archivo estudiantes.dat y mostrar el estudiante con el mayor promedio.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#define MAX 100

/*Defino un struct con los datos del estudiante*/
struct estudiante{
	int legajo; 
	char nombre[100]; 
	float promedio;

}; 

int main(){
	float mayor = -1; 
	struct estudiante est, may; // declaro vector de estudiantes

	FILE *arch; 
	
	arch = fopen("estudiantes.dat", "rb");
    
    if (arch == NULL) {
        printf("\nError al abrir el archivo\n");
        return 1;
    }

    while(fread(&est, sizeof(est), 1, arch)>0){
    	if(est.promedio > mayor) {
    		mayor = est.promedio; 
    		may = est; //almacena el estudiante con mayor promedio 
    	}
    	//printf("Su legajo es %d, su nombre es %s, su promedio es %.2f\n", est.legajo, est.nombre, est.promedio); 
    }

    printf("El legajo del alumno con mayor promedio es %d, su nombre es %s, su promedio es %.2f\n", may.legajo, may.nombre, may.promedio); 
    fclose(arch); 
    return 0;
}
