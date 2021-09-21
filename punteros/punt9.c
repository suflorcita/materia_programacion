/*Implemente la siguiente función para calcular el producto escalar de dos vectores:
double prod_esc (const double *a, const double *b, int n);
Donde a y b apuntan a vectores de longitud n.
La función debe retornar a[0]*b[0]+a[1]*b[1]+ … + a[n-1]*b[n-1]
Usar notación aritmética de punteros (no subíndices []) para recorrer los vectores.*/


#include <stdio.h>

double prod_esc(const double *a, const double *b, int n){
/*Función que calcula el producto escalar de dos vectores*/
	double producto = 0; 

	for(int i = 0; i < n; i ++){
		producto += (*(a + i) )* (*(b  + i));  
	}

	return producto; 
}

int main(){
	const double vec1[3] = {1, 2, 3}, vec2[3] = {1, 2, 3}; 
	double producto_escalar; 
	int longitud = 3; 

	producto_escalar = prod_esc(vec1, vec2, longitud); 


	printf("El producto escalar de los dos vectores es %.2lf\n", producto_escalar); 

	return 0; 
}