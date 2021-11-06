/*Hacer un programa que use la función del ejercicio anterior para mostrar
los valores de los primeros 13 registros del RTC. A cada valor de registro
impreso, agregarle una descripción previa, de unos pocos caracteres, que
especifique a qué registro pertenece el valor mostrado.*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define P 0x70 /* RTC */

unsigned char dec_to_BCD(int number){
/*Función que pasa un numero de dos cifras a BCD*/
  
  unsigned char BCD = 0x00, mask = 0X01; 
  int dec1, dec2, resto; 


  dec1 = number % 10;  //Cifra menos signficativa
  dec2 = number / 10; 

  while(dec1 > 0){  
    resto = dec1 % 2;
    dec1 = dec1 / 2; 

    BCD = BCD| (resto * mask); 
    mask = mask * 2;
  }



  mask = 0x10; // 5to bit 
  while(dec2 > 0){  
    resto = dec2 % 2;
    dec2 = dec2 / 2; 

    BCD = BCD| (resto * mask); 
    mask = mask * 2;
  }

  return BCD; 
}

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

  char *descripcion[] = {
         "            Segundo",
         "     Segundo Alarma",
         "             Minuto",
         "      Minuto Alarma",
         "               Hora",
         "        Hora Alarma",
         "   Dia de la semana",
         "        Dia del mes",
         "                Mes",
         "               Anio",
         "         Registro A",
         "         Registro B",
         "         Registro C",
         "         Registro D"
   };

  /* Dar permisos a los ports 70 y 71 */
  if (ioperm(P, 2, 1)) {
    perror("ioperm"); //Mueestra "ioperm" + el mensaje de error 
    exit(1);
  }

  for(int i = 0; i < 13; i++){
    printf("%s: ", descripcion[i]); 
    lee_imprime(dec_to_BCD(i)); 
    printf("\n"); 
  }

  /*Retirar permisos */
  if (ioperm(P, 2, 0)) {
    perror("ioperm");
    exit(1);
  }


  return 0;
}
