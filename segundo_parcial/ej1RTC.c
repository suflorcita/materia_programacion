/* Escribir una función en lenguaje C que reciba como argumento un nro de
registro (0-13), lea el valor de ese registro del RTC y lo imprima por
pantalla como hexadecimal. */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define P 0x70 /* RTC */

/* Esta funcion lee un byte del registro del RTC cuyo nro se recibe */ 
unsigned char in (unsigned char reg){
  outb (reg, P);
  return inb(P + 1);
  }


/* Esta funcion recibe como argumente un numero de regsitro, lee el valor de ese registro
y lo imprime por pantalla como hexadecimal*/
void lee_imprime (unsigned char reg){
  unsigned char valor; 

  outb (reg, P);
  valor = inb(P + 1);
  printf("%02x", valor); 
}
  

int main(){
  unsigned char registro; 

  /* Dar permisos a los ports 70 y 71 */
  if (ioperm(P, 2, 1)) {
    perror("ioperm"); //Mueestra "ioperm" + el mensaje de error 
    exit(1);
  }
  printf("La hora es: ");
  lee_imprime(0x04);
  printf(":");
  lee_imprime(0x02);
  printf(":");
  lee_imprime(0x00); 
  printf("\n");

  printf("La hora en que está seteada la alarma es: ");
  lee_imprime(0x05);
  printf(":");
  lee_imprime(0x03);
  printf(":");
  lee_imprime(0x01);
  printf("\n"); 


  printf("Hoy es el dia ");
  lee_imprime(0x06);
  printf(" del ");
  lee_imprime(0x07);
  printf(" del ");
  lee_imprime(0x08);
  printf(" del ");
  lee_imprime(0x09);
  //lee_imprime(0x0A);
  //lee_imprime(0x0B);
  //lee_imprime(0x0C);
  //lee_imprime(0x0D);

  /*Retirar permisos */
  if (ioperm(P, 2, 0)) {
    perror("ioperm");
    exit(1);
  }


  return 0;
}
