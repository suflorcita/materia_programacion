
/**Suponga que se ejecutan las siguientes instrucciones:
int a = {5, 15, 34, 54, 14, 2, 52, 72};
int *p = &a [1], *q = &a [5];

¿Cuál es el valor de *(p+3)? 14
¿Cuál es el valor de *(q-3)? 34
¿Cuál es el valor de q-p?
¿La condición p<q es verdadera o falsa? verdadera 
¿La condición *p<*q es verdadera o falsa? falsa*/




#include <stdio.h>


int main(){

	int a[10] = {5, 15, 34, 54, 14, 2, 52, 72}; 
	int *p = &a[1], *q = &a[5]; 

	printf("A - El valor de *(p + 3) es: %d \n", *(p + 3));
	printf("B - El valor de *(q - 3) es: %d \n", *(q - 3)); 

	printf("C - El valor de q - p es: %ld\n", q - p); //Posiciones de q hasta p

	if(p < q){
		printf("D - La condición es verdadera \n");
	} else {
		printf("D - La condición es falsa \n"); 
	}	

	if(*p < *q){
		printf("E - La condición es verdadera\n"); 
	} else {
		printf("E - La condición es falsa\n"); 
	}



	return 0; 
}