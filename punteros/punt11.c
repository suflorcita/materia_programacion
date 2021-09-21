/*Suponga que el puntero p está declarado como sigue:


struct mi_estructura {
   char a, b;
   int c;
   int e [5];
};

struct mi_estructura me;
struct mi_estructura *p = &me;

¿Cuáles de las siguientes instrucciones son válidas?

p->b = ’ ’; VALIDA
p->e [3] = 10; VALIDA 
(*p).a = ’*’; VALIDA 
*p.b = ’?’; NO VALIDA
me.c = 1;  VALIDA 
p.c = 1; NO VALIDA  
*/

#include <stdio.h>


struct mi_estructura{
	char a, b; 
	int c; 
	int e [5]; 
}; 


int main(){
	struct mi_estructura me; 
	struct mi_estructura *p = &me; 

	p -> b = 'd'; 
	printf("A-Imprimo p -> b:\t %c \n", p ->b); //Pongo una "d" para que sea más evidente

	p->e [3] = 10;
	printf("B-Imprimo p -> e[3]:\t %d \n", p -> e[3]); 

	(*p).a = '*'; 
	printf("C-Imprimo (*p).a:\t %c \n", (*p).a); 

	//*p.b = '?'; Error de compilación

	me.c = 1; 
	printf("D-Imprimo me.c:\t %d \n", me.c); 

	//p.c = 1; Error de compilación
}