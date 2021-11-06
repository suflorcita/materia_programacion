/*Escribir un programa o función en lenguaje C que modifique el/los registros
necesarios para que se produzca una interrupción periódica 4 veces por
segundo. Luego el programa debe quedarse al menos 10 segundos
esperando por las interrupciones e imprimir un * cada vez se produzcan.

*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define P 0x70 /* RTC */

unsigned char in (unsigned char reg){
/* Esta funcion lee un byte del registro del RTC cuyo nro se recibe */ 
  outb (reg, P);
  return inb(P + 1);
}

void out (unsigned char valor, unsigned char reg){
/* Función que recibe un registro y un valor y setea ese valor en el registro*/
  outb (reg, P);
  outb (valor, P + 1);
  }



int main(){
	unsigned char reg_a, reg_b, reg_c; 

  /* Dar permisos a los ports 70 y 71 */
  if (ioperm(P, 2, 1)) {
    perror("ioperm"); //Mueestra "ioperm" + el mensaje de error 
    exit(1);
  }

  reg_b = in(0x0B); 
  out(reg_b|0x40 , 0x0B); // Habilitos las interrupciones periodicas (bit PIE)


  reg_a = in(0x0A); //Seteo una interrupción periodica de 4 veces por segundo, 4 hz 
  out(reg_b|0x0F , 0x0A); //La secuencia es 1110


  reg_c = in (0x0C); /* Borro flags anteriores */
  /* Hacer polling del reg C */
  printf ("Esperando las alarmas...\n");
  for (int i = 0; i < 20; i++){ /* Espera 10 segundos en total */
    reg_c = in (0x0C);
    /* Verif bit 5 (AF) */
    if (reg_c & 0x40) //el bit del PF es el 6 
	    printf ("* ");

    usleep(500000);   /* Esperar 500ms */ 
  }



  /*Retirar permisos */
  if (ioperm(P, 2, 0)) {
    perror("ioperm");
    exit(1);
  }


	return 0; 
}