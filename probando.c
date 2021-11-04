/* Escribir una función en lenguaje C que reciba como argumento un nro de
registro (0-13), lea el valor de ese registro del RTC y lo imprima por
pantalla como hexadecimal. */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define P 0x70 /* RTC */

unsigned char dec_to_BCD(int number){
/*Función que pasa un numero de dos cifras a BCD*/
  unsigned char BCD = 0x00, mask = 0X01; //lo pongo en 0 
  int dec1, dec2, resto; 
  dec1 = number % 10;  //Cifra menos signficativa
  dec2 = number / 10; 
  printf("skks%d", dec2); 

  while(dec1 > 0){  
    resto = dec1 % 2;
    //printf("%d\n", resto);
    dec1 = dec1 / 2; 

    BCD = BCD| (resto * mask); 
    mask = mask * 2; 
    //printf("%x\n", mask);
    printf("%x\n", BCD);
  }



  mask = 0x10; 
  while(dec2 > 0){  
    resto = dec2 % 2;
    //printf("%d\n", resto);
    dec2 = dec2 / 2; 

    BCD = BCD| (resto * mask); 
    mask = mask * 2; 
    //printf("%x\n", mask);
    printf("%x\n", BCD);
  }

  return BCD; 
}

int main(){
  int h=44;
  printf("%x",dec_to_BCD(h));


  return 0;
}
