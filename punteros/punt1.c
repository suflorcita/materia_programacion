/* Considere las siguientes instrucciones:
     int *p; 
     int i; 
     int k;

     i = 42; 
     k = i; 
     p = &i; 

Luego de esas instrucciones, ¿Cúál de las siguientes cambia el valor de i a 75?

A - k = 75
B - *k = 75 
C - p = 75;
D - *p = 75;
E - Dos o más de las anteriores.

Punto D
*/ 


#include <stdio.h>

int main(){
	int *p; 
	int i; 
	int k; 

	i = 42; 
	k = i; // k = 42

	p = &i;

	k = 75; 
	printf("A - El valor de i es %d\n", i); 

	/**k = 75; 
	printf("B - El valor de i es %d", i); 

	El B da error porque k no es un puntero; 
	*/

	/*p = 75; 
	printf("C - El valor de i es %d", i ); *

	Violación de segmento. 
	*/

	*p = 75; 
	printf("D - El valor de i es %d \n", i); 
	return 0; 
}