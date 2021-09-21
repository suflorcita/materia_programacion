/*
Suponga que f y p están declarados como sigue:

	struct{
		union{
			char a, b; 
			int c; 
		} d; 
		int e [5]; 
	} f, *p sx= &f;

a- p->b = ’ ’; NO VALIDO
b- p->e [3] = 10; VALIDO
c- (*p).d.a = ’*’; VALIDO
d- p->d->c = ’x’; NO VALIDO

*/


#include <stdio.h>

 

int main(){
	struct{
		union{
			char a, b; 
			int c; 
		} d; 
		int e [5]; 
	} f, *p = &f; 

	//p -> b = ' '; error de compilación - b es un char dentro de la unión, debería ser

	p -> d.c = 'h'; 
	printf("A - El valor de p -> d.c:\t%c\n", p->d.c); 

	p -> e [3] = 10; 
	printf("B - El valor de p-> e[3] es:\t%d\n", p->e[3]); 

	(*p).d.a = '*'; 
	printf("C - El valor de (*p).d.a es:\t%c\n", (*p).d.a); 

	//p->d->c = 'x'; error de compilación - d no es un puntero, es una union y además c es un entero. Debería ser;  

	p->d.c = 5; 
	printf("D - El valor de p->d.c es:\t%d\n", p->d.c); 

	return 0; 
}