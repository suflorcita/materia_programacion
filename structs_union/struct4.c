/*Escribir una función que reciba las coordenadas de dos vectores en el plano y
devuelva las coordenadas del vector que resulta de componer ambos vectores*/

#include <stdio.h>

/*Defino una estructura para los vectores*/
struct vector{
	float x; 
	float y; 
// Representa las componentes x e y de un vector
}; 

/*Función a la que se le ingresan dos vectores y retorna un vector que es la composición de ambos*/

struct vector composicion(struct vector v1, struct vector v2){
	struct vector comp;  
	
	comp.x = v1.x + v2.x; 
	comp.y = v1.y + v2.y; 

	return comp; 
}

/* Programa principal */
int main(){
	struct vector v1, v2, v3; 

	printf("Ingreso el valor del componente x del vector 1: ");
	scanf("%f", &v1.x);

	printf("Ingreso el valor del componente y del vector 1: ");
	scanf("%f", &v1.y);

	printf("Ingreso el valor del componente x del vector 2: ");
	scanf("%f", &v2.x);

	printf("Ingreso el valor del componente y del vector 2: ");
	scanf("%f", &v2.y);

	v3 = composicion(v1, v2);

	printf("El vector (%.2f, %.2f) es el que resulta de la composición de ambos vectores\n", v3.x, v3.y); 

	return 0; 
}