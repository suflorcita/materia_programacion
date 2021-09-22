/*Suponga que se ejecutan las siguientes instrucciones:
struct punto {int x;
int y;
};
struct rectangulo {
struct punto superior_izq;
struct punto inferior_der;
};
struct rectangulo *p;
Escriba las líneas necesarias para que p apunte a una estructura rectangulo
válida que tenga (10,25) como esquina superior izquierda y (20,15) como esquina
inferior derecha*/

#include <stdio.h>
#include <stdlib.h>

struct punto{
	int x;
	int y;  
}; 

struct rectangulo{
	struct punto superior_izq; 
	struct punto inferior_der; 
}; 


int main(){
	struct rectangulo *p;
	struct punto pun1, pun2; 

	p = malloc(sizeof (struct rectangulo)); //reservo un lugar de memoria 

	pun1.x = 10;
	pun1.y = 25;

	pun2.x = 20;
	pun2.y = 15; 

	p -> superior_izq = pun1; 
	p -> inferior_der = pun2; 

	printf("El punto (%d, %d) es la esquina superior izquierda.\n.", p -> superior_izq.x, p->superior_izq.y);
	printf("El punto (%d, %d) es la esquina inferior derecha.\n", p -> inferior_der.x, p -> inferior_der.y); 
	free(p); 

}