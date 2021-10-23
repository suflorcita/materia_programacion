/* 
Este programa permite el ingreso de la hora (hh:mm:ss) de alarma y la programa en el RTC 
Notas: 
-Tener en cuenta la zona horaria. El RTC puede estar configurado para usar GMT
-La hora del RTC puede ser distinta de la hora del Sistema Operativo
-Si esta instalado se puede usar el comando de Linux hwclock -r para visualizar la hora del RTC
-La alarma no funciona sobre VirtualBox y puede no funcionar con otras máquinas virtuales
Programacion UNSAM
Autor: David Lopez
Año: 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#define P 0x70 /* RTC */

unsigned char in (unsigned char reg){
  outb (reg, P);
  return inb(P + 1);
  }

void out (unsigned char valor, unsigned char reg){
  outb (reg, P);
  outb (valor, P + 1);
  }

int main(){
  unsigned char hora, min, seg, a, b, c, i;

  printf ("Ingrese la hora de alarma (hh:mm:ss):");
  scanf ("%hhx:%hhx:%hhx", &hora, &min, &seg);

  /* Dar permisos a los ports 70 y 71 */
  if (ioperm(P, 2, 1)) {perror("ioperm"); exit(1);}
  
  out (seg, 0x01);  /* Setear segundos alarma */
  out (min, 0x03);  /* Setear minutos alarma */
  out (hora, 0x05); /* Setear hora alarma */

  c = in (0x0C); /* Borro flags anteriores */
  /* Hacer polling del reg C */
  printf ("Esperando las alarmas...\n");
  for (i = 0; i < 120; i++){ /* Espera 60 segundos en total */
    c = in (0x0C);
    /* Verif bit 5 (AF) */
    if (c & 0x20)
	    printf ("Alarma\n");
    usleep(500000);   /* Esperar 500ms */ 
  }

  /* Retirar permisos */
  if (ioperm(P, 2, 0)) {perror("ioperm"); exit(1);}
  return 0;
}
