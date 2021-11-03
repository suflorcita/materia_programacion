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


   primeras_cifras_anio = in(0x32); 

   printf("---------------------------------------------------\n"); 
   printf("| NUMERO DE |  VALOR  |   VALOR   |   DESCRIPCIÓN|\n"); 
   printf("|  REGISTRO | BINARIO |HEXADECIMAL|              |\n"); 
   printf("--------------------------------------------------\n");
   

   for(int i = 0; i < 13; i++){
      printf("|t0x%02X |", i);
      chequea_regA(); 
      lee_reg = in(0x00 + i); 
      int_to_bin(lee_reg); 
      printf("| 00x%02X     | %s|\n",lee_reg, descripcion[i]);  
   }

   printf("|0x32   |         |0x%02x       |Anio(primeras cifras)|\n", primeras_cifras_anio);
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

   puts("Presione enter para continuar");
   getchar();

   return; 
}


/* Programa principal */
int main() {
   int op;
   char c; 

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
         printf("Presione cualquier caracter para continuar: ");
         c = getchar(); 
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


