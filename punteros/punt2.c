/*2. Explicar qué está mal en el siguiente fragmento de código:
char c = 'A';
double *p = &c;

El puntero tiene que ser del mismo tipo de la variable a la que estoy apuntando. 
Lo correcto sería:


*/

#include <stdio.h>


int main(){
	char c = 'A'; 
	char *p = &c;

	printf("C se encuentra en la posición %p y vale %c\n", &c, c); 
	printf("P se encuentra en la posición %p y vale %c\n", &p, *p); 

	return 0; 
}