/*Escribir una función que reciba las coordenadas cartesianas de 2 puntos en el
espacio y devuelva la distancia euclídea.*/

#include <stdio.h>
#include <math.h> // voy a usar las funciones pow y sqrt de esta librería

/*Defino un struct para los puntos*/
struct punto{
	double x; 
	double y; 
}; 

/*Función que calcula la distancia euclídea*/
double distancia(struct punto p1, struct punto p2){
	double dist; 

	dist = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)); 

	return dist; 
}

/*Programa principal*/
int main(){
	struct punto p1, p2; 
	double res;

	printf("Ingrese la coordenada X del punto 1: "); 
	scanf("%lf", &p1.x); 

	printf("Ingrese la coordenada Y del punto 1: "); 
	scanf("%lf", &p1.y); 

	printf("Ingrese la coordenada X del punto 2: "); 
	scanf("%lf", &p2.x); 

	printf("Ingrese la coordenada Y del punto 2: "); 
	scanf("%lf", &p2.y); 


	res = distancia(p1, p2);

	printf("La distancia euclidea entre esos dos puntos y con dos decimales es de %.2f\n", res);

	return 0; 
}

//obs para compilar es: cc struct3.c -lm -o  st3