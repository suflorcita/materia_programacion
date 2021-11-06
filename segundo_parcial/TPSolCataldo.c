/*
TP Ports. 


Al iniciar el programa, en líneas separadas y por única vez, muestre por pantalla:
- Título del programa.
- Apellido y Nombre de quien lo desarrolló.
- Nombre de la materia.
- Cuatrimestre y Año actual.
- Tiempo en horas que le llevó realizarlo
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



void  int_to_bin(unsigned char valor){
/*Función recibe numero y muestra su valor en binario*/
   unsigned char binary[8]; 
   int i; 

   for(i = 0; i < 8; i++){
      if(valor & 0x01 != 0){
         binary[i] = 1; 
      } else {
         binary[i] = 0; 
      }
      valor = valor >> 1; // corre un bit a la derecha 
   }

   for(i = 7; i >= 0; i--){
      printf("%d", binary[i]); 
   }

   printf(" "); 
   return; 
}


int BCD_decimal(unsigned char valor){
/*Función que recibe un número en BCD y lo pasa a decimal*/
   int i, dec1 = 0, dec2 = 0, dec = 0, j = 1;  
   
   for(i = 0; i < 4; i++){
   //Paso a decimal los primeros 4 bits (los 4 menos significativos)
      if(valor & 0x01 != 0){         
         dec1 += j;
      } 

      
      valor = valor >> 1; 
      j *= 2; 

   } 

   j = 1;  
   
   for(i = 0; i < 4; i++){
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

  if(dec2 == 0)
   return BCD; 


  mask = 0x10; // 5to bit 
  while(dec2 > 0){  
    resto = dec2 % 2;
    dec2 = dec2 / 2; 

    BCD = BCD| (resto * mask); 
    mask = mask * 2;
  }

  return BCD; 
}


void chequea_regA(){
   unsigned char reg_A; 
   reg_A = in (0x0A);
   if ((reg_A  & 0x80) != 0) //Verifica el bit 7 del reg_a (UIP)
      usleep (1984); //Esperar lo que dura la actualiz. en el peor caso (1984us)
}

void lee_hora (){
/*Función que lee los registros correspondientes a la alarma 
y muestra la hora minutos y segundos de la alarma en formato HH:MM:SS.*/
   unsigned char hora_alarma, minutos_alarma, segundos_alarma; 

   hora_alarma = in(0x04); 
   minutos_alarma = in(0x02); 
   segundos_alarma = in(0x00); 
   
   printf("La hora es: %02X:%02X:%02X\n", hora_alarma, minutos_alarma, segundos_alarma);
}



void lee_alarma (){
/*Función que lee los registros correspondientes a la alarma 
y muestra la hora minutos y segundos de la alarma en formato HH:MM:SS.*/
   unsigned char hora_alarma, minutos_alarma, segundos_alarma;
   hora_alarma = in(0x05); 
   minutos_alarma = in(0x03); 
   segundos_alarma = in(0x01); 
   
   printf("La hora de la alarma es: %02X:%02X:%02X\n", hora_alarma, minutos_alarma, segundos_alarma);
}

void mostrar_tabla(){
   unsigned char lee_reg, primeras_cifras_anio; 
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
   char tecla; 
   int i; 

   primeras_cifras_anio = in(0x32); 

   printf("---------------------------------------------------------\n"); 
   printf("| NUMERO DE |  VALOR  |   VALOR   |   DESCRIPCIÓN       |\n"); 
   printf("|  REGISTRO | BINARIO |HEXADECIMAL|                     |\n"); 
   printf("---------------------------------------------------------\n");
   

   for(i= 0; i < 14; i++){
      printf("|0x%02X       |", i);
      chequea_regA(); 
      lee_reg = in(0x00 + i); 
      int_to_bin(lee_reg); 
      printf("|0x%02X       |  %s|\n",lee_reg, descripcion[i]);  
   }
           
   printf("|0x32       |"); 
   int_to_bin(primeras_cifras_anio); 
   printf("|0x%02x       |Anio(primeras cifras)|\n", primeras_cifras_anio);
   printf("---------------------------------------------------------\n");

   
   printf("Ingrese un caracter (letra o numero) para continuar: ");
   scanf("%s", &tecla); 
}

void mostrar_configurar_alarma(){
/*Muestra el horario de la alarma y lo configura*/
   unsigned char reg_c, reg_b;
   int segundos, minutos, horas, i;  
   

   //Muestro la hora de la alarma 
   chequea_regA();
   lee_alarma();
   
   //Configuro alarma para los proximos cinco segundos  
   //Leo los segundos actuales y los paso a decimal para hacer las cuentas
   chequea_regA();
   segundos = BCD_decimal(in(0x00));   
   minutos = BCD_decimal(in(0x02));
   horas = BCD_decimal(in(0x04)); 

  
   chequea_regA();   
   
   //Seteo los valores en el reloj de la alarma 
   if(segundos < 55){
       out(dec_to_BCD(segundos + 5), 0x01);
       out(dec_to_BCD(minutos), 0x03);
       out(dec_to_BCD(horas), 0x05);
   } else{
      out(dec_to_BCD((segundos + 5) % 10), 0x01); 
      if(minutos != 59){
         out(dec_to_BCD(minutos + 1), 0x03);  
      } else {
         out(00, 0x03); 
         if (horas != 23){
            out(dec_to_BCD(horas + 1), 0x05); 
         } else{
            out(00, 0x05); 
         }
      }
   }  
   
   //lee_alarma(); 
   //lee_hora();  //me sirven para chequear si voy bien

   reg_c = in(0x0C); // Borro flags anteriores

   /* Hago polling del reg C */
   printf ("\nEspero la alarma..\n");
   for (i = 0; i < 20; i++){ /* Espera 10 segundos en total */
    reg_c = in(0x0C); 
    
    if (reg_c & 0x20){  // Verifico el bit 5
      printf ("ALARMA: ¡beep! ¡beep!\n");
      usleep(1000000); //Espero 1 segundo 
      
      chequea_regA();
      lee_alarma(); //Muestro el valor por pantalla
      
      usleep(1000000); //Espero 1 segundo 
      return; 
    }
       

    usleep(500000);   /* Esperar 100ms */ 
  } 

   return; 
}

void lee_registro(){
   unsigned char registro, lectura_reg; 
   char tecla; 

   printf("Ingrese el número de un registro: "); 
   scanf("%hhd", &registro); 
   printf("%X", registro);

   if(registro < 11)
      chequea_regA(); 

   if(registro < 0x64){
      lectura_reg = in(0x00 + registro); 
      printf("\nEl valor en binario es (tal cual se leyó) es: ");  
      int_to_bin(lectura_reg);
      printf("\n"); 
   } else{
      printf("El registro no existe\n"); 
   }

   printf("\nIngrese un caracter (letra o numero) para continuar: ");
   scanf("%s", &tecla); 

   return; 
}



int imprime_menu () {
   int op;

   printf ("\n1. MOSTRAR TABLA DE REGISTROS ");
   printf ("\n2. MOSTRAR Y CONFIGURAR ALARMA");
   printf ("\n3. LEER Y MOSTRAR DATOS DE UN REGISTRO INGRESADO POR TECLADO");
   printf ("\n4. SALIR\n ");
   printf("\nSeleccione una opción (numerica unicamente): ");
   scanf ("%d", &op);
   return op;
}




/* Programa principal */
int main() {
   int op;
   char c, tecla; 

   printf("\nTP Programación\n");
   printf("Alumno: Cataldo Sol Ayelen\n");
   printf("Materia: Programación\n");
   printf("Segundo cuatrimestre 2021 \n");
   printf("Tiempo en horas: 20hs\n");

  /* Dar permisos a los ports 70 y 71 */
  if (ioperm(P, 2, 1)) {
    perror("ioperm"); //Mueestra "ioperm" + el mensaje de error 
    exit(1);
  }
  

   do {
      op = imprime_menu();
      switch (op) {
         case 1:
         mostrar_tabla();
            break;
         case 2:
         mostrar_configurar_alarma(); 
            break;
         case 3:
         lee_registro(); 
            break;
         case 4:
            break;
         default:
            printf ("\nOpcion invalida");
            break;
      } /* switch */
   } while (op != 4);


   /*Retirar permisos */
   if (ioperm(P, 2, 0)) {
      perror("ioperm");
      exit(1);
   }


    return 0; 
}


