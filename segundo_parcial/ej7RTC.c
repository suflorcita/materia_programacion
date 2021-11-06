/*Escribir un programa que muestre la fecha leída del RTC en el formato
DD/MM/AAAA.*/


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


void lee_fecha (){
/*Función que lee los registros correspondientes a la alarma 
y muestra la hora minutos y segundos de la alarma en formato HH:MM:SS.*/
   unsigned char dd, mm, aa1, aa2; 

   dd = in(0x07); 
   mm = in(0x08); 
   aa1 = in(0x09); 
   aa2 = in(0x32); 
   
   printf("La hora es: %02X:%02X:%02X%02X\n", dd, mm, aa1, aa2);
}


int main(){

  /* Dar permisos a los ports 70 y 71 */
  if (ioperm(P, 2, 1)) {
    perror("ioperm"); //Mueestra "ioperm" + el mensaje de error 
    exit(1);
  }

  lee_fecha(); 

  /*Retirar permisos */
  if (ioperm(P, 2, 0)) {
    perror("ioperm");
    exit(1);
  }  



	return 0; 
}