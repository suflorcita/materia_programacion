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


void  int_to_bin(unsigned char valor){
/*Función que muestra el valor en binario*/
   unsigned char binary[8]; 

   //0x01 -> mascara para ver si 
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
   

void chequea_regA(){
   unsigned char reg_A; 
   reg_A = in (0x0A);
   if ((reg_A  & 0x80) != 0) //Verifica el bit 7 del reg_a (UIP)
      usleep (1984); //Esperar lo que dura la actualiz. en el peor caso (1984us)
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

   //primeras_cifras_anio = in(0x32); 

   printf("-----------------------------------------------------\n"); 
   printf("| \tNUMERO DE |  VALOR  |   VALOR   |   DESCRIPCIÓN   |\n"); 
   printf("| \t REGISTRO | BINARIO |HEXADECIMAL|                 |\n"); 
   printf("-----------------------------------------------------\n");
   for(int i = 0; i < 16; i++){
      printf("|\t0x%02X|\t", i);
      chequea_regA(); 
      lee_reg = in(0x00 + i); 
      int_to_bin(lee_reg); 
      printf("| %02X | %s\n",lee_reg, descripcion[i]);  
   }

   //printf("|    0x32   |         |0x%02x       |Anio(primeras cifras)|\n", primeras_cifras_anio);
   printf("-----------------------------------------------------\n");
   
}

int imprime_menu () {
   int op;

   printf ("\n1. MOSTRAR TABLA DE REGISTROS ");
   printf ("\n2. MOSTRAR Y CONFIGURAR ALARMA");
   printf ("\n3. LEER Y MOSTRAR DATOS DE UN REGISTRO INGRESADO POR TECLADO");
   printf ("\n4. SALIR ");
   printf("\nSeleccione una opción: ");
   scanf ("%d", &op);
   return op;
}

void lee_registro(){
   unsigned char registro, lectura_reg; 

   printf("Ingrese el número de un registro: "); 
   scanf("%hhx", &registro); 

   if(registro < 11)
      chequea_regA(); 

   lectura_reg = in(0x00 + registro); 

   printf("El valor en binario es (tal cual se leyó) es: ");  
   int_to_bin(lectura_reg); 


   return; 
}


/* Programa principal */
int main() {
   int op;

   printf("TP Programación\n");
   printf("Alumno: Cataldo Sol Ayelen\n");
   printf("Materia: Programación\n");
   printf("Segundo cuatrimestre 2021 \n");
   printf("Tiempo en horas: 20hs");

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





   /*

   reg_A = in (0x0A);
   if ((reg_A  & 0x80) != 0) //Verifica el bit 7 del reg_a (UIP)
      usleep (1984); //Esperar lo que dura la actualiz. en el peor caso (1984us)




   printf("|    0x00   |         |0x%02x       |              Segundo|\n", segundos);
   printf("|    0x01   |         |0x%02x       |       Segundo Alarma|\n", segundos_alarma);
   printf("|    0x02   |         |0x%02x       |               Minuto|\n", minuto);
   printf("|    0x03   |         |0x%02x       |       Minuto Alarma |\n", minuto_alarma);
   printf("|    0x04   |         |0x%02x       |                 Hora|\n", hora);
   printf("|    0x05   |         |0x%02x       |          Hora Alarma|\n",hora_alarma);
   printf("|    0x06   |         |0x%02x       |     Dia de la semana|\n", dia_semana);
   printf("|    0x07   |         |0x%02x       |          Dia del mes|\n", dia_mes);
   printf("|    0x08   |         |0x%02x       |                  Mes|\n", mes);
   printf("|    0x09   |         |0x%02x       | Anio(ultimas cifras)|\n", anio);
   printf("|    0x0A   |         |0x%02x       |           Registro A|\n", reg_A);
   printf("|    0x0B   |         |0x%02x       |           Registro B|\n", reg_B);
   printf("|    0x0C   |         |0x%02x       |           Registro C|\n", reg_C);
   printf("|    0x0D   |         |0x%02x       |           Registro D|\n", reg_D);

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

   primeras_cifras_anio = in(0x32); */