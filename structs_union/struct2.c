/*Leer el archivo estudiantes.dat y mostrar el estudiante con el mayor promedio.*/
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
	int i = 0; 
	float mayor = -1; 
	struct estudiante est[MAX], may; // declaro vector de estudiantes

	FILE *arch; 
	
	arch = fopen("estudiantes.dat", "rb");
    
    if (arch == NULL) {
        printf("\nError al abrir el archivo\n");
        return 1;
    }

    while(fread(&est[i], sizeof est[i], 1, arch)>0){ 
    	if(est[i].promedio > mayor) {
    		mayor = est[i].promedio; 
    		may = est[i]; //almacena el estudiante con mayor promedio 
    	}
    	//printf("Su legajo es %d, su nombre es %s, su promedio es %.2f\n",est[i].legajo, est[i].nombre, est[i].promedio); 
        i++;  
    }

    fclose(arch);
    
    printf("El número de legajo del alumno con mayor promedio es %d\n", may.legajo);  
    printf("Su nombre es %s y su promedio es %.2f\n", may.nombre, may.promedio); 
 
    return 0;
}
