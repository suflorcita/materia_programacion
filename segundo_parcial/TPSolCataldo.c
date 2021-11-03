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
/* Esta funcion que lee un byte del registro del RTC cuyo nro se recibe */ 
  outb (reg, P);
  return inb(P + 1);
}



void mostrar_tabla(){
   unsigned char segundos, segundos_alarma, minuto, minuto_alarma, hora_alarma, hora,
   dia_semana, dia_mes, anio, mes, reg_A, reg_B, reg_C, reg_D; 

   
   reg_A = in (0x0A);
   if ((reg_A  & 0x80) != 0) //Verif. bit 7 (UIP). Ojo prioridades operadores
      usleep (1984); //Esperar lo que dura la actualiz. en el peor caso (1984us)


   segundos = in(0x00);
   segundos_alarma = in(0x01); 
   minuto = in(0x02); 
   minuto_alarma = in(0x03); 
   hora = in(0x04); 
   hora_alarma = in(0x05); 
   dia_semana = in(0x06); 
   dia_mes = in(0x07); 
   mes = in(0x08); 
   anio = in(0x09); 

   reg_B = in(0x0B); 
   reg_C = in(0x0C); 
   reg_D = in(0x0D); 



   printf("-----------------------------------------------------\n"); 
   printf("| NUMERO DE |  VALOR  |   VALOR   |   DESCRIPCIÓN   |\n"); 
   printf("|  REGISTRO | BINARIO |HEXADECIMAL|                 |\n"); 
   printf("-----------------------------------------------------\n");
   printf("|    0x00   |         |%02x       |          Segundo|\n", segundos);
   printf("|    0x01   |         |%02x       |   Segundo Alarma|\n", segundos_alarma);
   printf("|    0x02   |         |%02x       |           Minuto|\n", minuto);
   printf("|    0x03   |         |%02x       |   Minuto Alarma |\n", minuto_alarma);
   printf("|    0x04   |         |%02x       |             Hora|\n", hora);
   printf("|    0x05   |         |%02x       |      Hora Alarma|\n",hora_alarma);
   printf("|    0x06   |         |%02x       | Dia de la semana|\n", dia_semana);
   printf("|    0x07   |         |%02x       |      Dia del mes|\n", dia_mes);
   printf("|    0x08   |         |%02x       |             Anio|\n", mes);
   printf("|    0x09   |         |%02x       |              Mes|\n", anio);
   printf("|    0x0A   |         |%02x       |       Registro A|\n", reg_A);
   printf("|    0x0B   |         |%02x       |       Registro B|\n", reg_B);
   printf("|    0x0C   |         |%02x       |       Registro C|\n", reg_C);
   printf("|    0x0D   |         |%02x       |       Registro D|\n", reg_D);
   printf("-----------------------------------------------------\n");
   
}

int imprime_menu (void) {
   int op;

   printf ("\n1. MOSTRAR TABLA DE REGISTROS ");
   printf ("\n2. MOSTRAR Y CONFIGURAR ALARMA");
   printf ("\n3. LEER Y MOSTRAR DATOS DE UN REGISTRO INGRESADO POR TECLADO");
   printf ("\n4. SALIR ");
   printf("\nSeleccione una opción: ");
   scanf ("%d", &op);
   return op;
}


/* Programa principal */
int main() {
   int op;

   printf("TP Programación\n");
   printf("Alumno: Cataldo Sol Ayelen\n");
   printf("Materia: Programación\n");
   printf("Segundo cuatrimestre 2021 \n");

  /* Dar permisos a los ports 70 y 71 */
  if (ioperm(P, 2, 1)) {
    perror("ioperm"); //Mueestra "ioperm" + el mensaje de error 
    exit(1);
  }
  

   do {
      op = imprime_menu();
      switch (op) {
         case 1:
            break;
         case 2:
            break;
         case 3:
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
