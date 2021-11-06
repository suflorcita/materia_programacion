/*Modifique el programa del ejercicio anterior. Además de mostrar la
descripción y el valor de cada registro leído, imprima sobre la misma línea
de la pantalla el valor del registro en formato binario de 8 caracteres.
Recuerde que en la guía de sistemas de numeración debió realizar la
función para convertir a binario.*/

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


/* Esta funcion recibe como argumente un numero de regsitro, lee el valor de ese registro,
lo imprime por pantalla como hexadecimal y retorna el valor*/
int lee_imprime (unsigned char reg){
  unsigned char valor; 

  outb (reg, P);
  valor = inb(P + 1);
  printf("%02x", valor);
  return valor;  
}


void  int_to_bin(unsigned char valor){
/*Función recibe numero y muestra su valor en binario tal cual se lee*/
   unsigned char binary[8]; 

   for(int i = 0; i < 8; i++){
      if(valor & 0x01 != 0){
         binary[i] = 1; 
      } else {
         binary[i] = 0; 
      }
      valor = valor >> 1; // corre un bit a la derecha 
   }

   for(int i = 7; i >= 0; i--){
      printf("%d", binary[i]); 
   }

   printf(" "); 
   return; 
}


int BCD_decimal(unsigned char valor){
/*Función que recibe un número en BCD y lo pasa a decimal*/
   int dec1 = 0, dec2 = 0, dec = 0, j = 1;  
   
   for(int i = 0; i < 4; i++){
   //Paso a decimal los primeros 4 bits (los 4 menos significativos)
      if(valor & 0x01 != 0){         
         dec1 += j;
      } 

      
      valor = valor >> 1; 
      j *= 2; 

   } 

   j = 1;  
   
   for(int i = 0; i < 4; i++){
   //Paso a decimal los ultimos 4 bits (los 4 mas significativos)
      if(valor & 0x01 != 0){
         dec2 += j;  
      } 
      valor = valor >> 1; 
      j *= 2;      
   } 

   dec = dec1 + dec2 * 10; 

   return dec; 

}

  

int main(){
  unsigned char registro, valor; 

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
    valor = lee_imprime(dec_to_BCD(i)); 
    
    printf("BCD: "); 
    int_to_bin(valor); 
    
    printf("Binario puro: "); 
    int_to_bin(BCD_decimal(valor)); 
  }

  /*Retirar permisos */
  if (ioperm(P, 2, 0)) {
    perror("ioperm");
    exit(1);
  }


  return 0;
}
