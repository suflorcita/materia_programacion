/*Escribir un programa o función en lenguaje C para leer e imprimir el
nombre de los flags de los registros A, B, C y D del RTC y el valor actual de
sus bits.*/


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


void flags_a(){
	unsigned char reg_a, mask = 0x01, flag;
	char *bits[] = {
         "RS0: configuración onda cuadrada",
         "RS1: configuración onda cuadrada",
         "RS2: configuración onda cuadrada",
         "RS3: configuración onda cuadrada",
         "DV0: frecuencia onda cuadrada",
         "DV1: frecuencia onda cuadrada",
         "DV2: frecuencia onda cuadrada",
         "UIP", 
   };

   printf("\n-------------------Flags registro A---------------\n");

   reg_a = in(0X0A);

   for(int i = 0; i < 7; i++){
   	
   	if(mask & reg_a){
   		flag = 1; 
   	} else{
   		flag = 0; 
   	}
 
   	printf("%s : %0X\n", bits[i], flag); 
   	mask = mask * 2; 
   }

	return; 
}



void flags_b(){
	unsigned char reg_b, mask = 0x01, flag;
	char *bits[] = {
         "DSE: Daylight Saving Enable",
         "24/12",
         "DM(Data Mode)",
         "SQWE",
         "UIE: Update Interrupt Enable",
         "AIE",
         "PIE: Periodic Interrupt Enable",
         "SET", 
   };

   reg_b = in(0x0B); 
   printf("\n-------------------Flags registro B---------------\n");

   for(int i = 0; i < 7; i++){
   	
   	if(mask & reg_b){
   		flag = 1; 
   	} else{
   		flag = 0; 
   	}

   	printf("%s : %0X\n", bits[i], flag); 
   	mask = mask * 2; 
   }

	return; 
}


void flags_c(){
	unsigned char reg_c, mask = 0x01, flag;
	char *bits[] = {
         "D0",
         "D1",
         "D2",
         "D3",
         "UF: Update Flag",
         "AF: Alarm Flag",
         "PF: Periodic Flag",
         "IRQF", 
   };

   printf("\n-------------------Flags registro c---------------\n");

   reg_c = in(0x0C); 
   for(int i = 0; i < 7; i++){
   	
   	if(mask & reg_c){
   		flag = 1; 
   	} else{
   		flag = 0; 
   	}

   	printf("%s : %0X\n", bits[i], flag); 
   	mask = mask * 2; 
   }

	return; 
}


void flags_d(){
	unsigned char reg_d, mask = 0x01, flag;
	char *bits[] = {
         "D0",
         "D1",
         "D2",
         "D3",
         "D4",
         "D5",
         "D6",
         "VRT"
   };


   printf("\n-------------------Flags registro D---------------\n");
   reg_d = in(0x0D); 

   for(int i = 0; i < 7; i++){

   	if(mask & reg_d){
   		flag = 1; 
   	} else{
   		flag = 0; 
   	}


    
   	printf("%s : %0X\n", bits[i], flag); 
   	mask = mask * 2;

   }


	return; 
}



int main(){

  /* Dar permisos a los ports 70 y 71 */
  if (ioperm(P, 2, 1)) {
    perror("ioperm"); //Mueestra "ioperm" + el mensaje de error 
    exit(1);
  }


	flags_a(); 
	flags_b(); 
	flags_c(); 
	flags_d(); 

  /*Retirar permisos */
  if (ioperm(P, 2, 0)) {
    perror("ioperm");
    exit(1);
  }


	return 0; 
}