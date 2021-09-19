/*Escribir un programa que imprima los elementos de un vector de enteros en orden
inverso utilizando punteros (no usar subíndices []).
int v[10] = {1,2,3,4,5,6,7,8,9,10};
int *p; */


#include <stdio.h>


int main(){
	int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	int *p; 

	p =  &v[9]; //hago que el vector apunte al último elemento del vector 

	for(int i = 0; i < 10; i++){
		printf("El valor del elemento %d es %d\n", 9 - i, *(p-i)); 
	}

	return 0; 
}