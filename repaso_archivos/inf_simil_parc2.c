/*
Informatica UNSAM
Autor: David Lopez
Año: 2020
Escribir un programa que ofrece el siguiente menu en forma ciclica hasta salir:
1. Leer una matriz de enteros de 5x5 desde el archivo matrix.dat
2. Grabar la matriz al archivo matrix.dat
3. Inicializar la matriz de forma tal que m(i,j) se vea ij, es decir: 11, 12, 13, 14, 15, 21, 22, ... , 55
4. Ingresar el valor de un elemento por teclado
5. Generar vector con la suma de cada columna
6. Mostrar la matriz y el vector
7. Salir
Usar al menos una funcion por cada opcion del menu (menos la 7)
*/

#include <stdio.h>
#include <stdlib.h>
#define F 5
#define C 5

int imprime_menu (void) {
   int op;
   printf ("\n1. Leer matriz desde archivo");
   printf ("\n2. Grabar matriz al archivo");
   printf ("\n3. Inicializar matriz");
   printf ("\n4. Ingresar elemento");
   printf ("\n5. Generar vector");
   printf ("\n6. Mostrar todo");
   printf ("\n7. Salir");
   printf ("\nOpcion:");
   scanf ("%d", &op);
   return op;
}

/*Lee un archivo que contiene F*C datos enteros y los almacena en una matriz de FxC*/
void lee_archivo (int m [F][C]) {
    int n;
    FILE *arch;

    arch=fopen("matrix.dat", "r");
    if(arch != NULL) {
        n = fread (m, sizeof m[0][0], F*C, arch);
        if(n != F*C){
            printf("Error al leer\n");
            fclose(arch);
            exit(1);
        }
        if(fclose(arch) != 0){
            printf("Error al cerrar\n");
            exit(2);
        }
    }
    else {
        printf("Error al abrir el archivo para lectura\n");
        exit(3);
    }
}

/*Graba los datos de una matriz de FxC a un archivo que contiene F*C datos enteros*/
void graba_archivo (int m [F][C]) {
    int n;
    FILE *arch;

    arch=fopen("matrix.dat", "w");
    if(arch != NULL) {
        n = fwrite (m, sizeof m[0][0], F*C, arch);
        if(n != F*C){
            printf("Error al grabar\n");
            fclose(arch);
            exit(4);
        }
        if( fclose(arch) != 0){
            printf("Error al cerrar\n");
            exit(5);
        }
    }
    else {
        printf("Error al abrir el archivo para escritura\n");
        exit(6);
    }
}

/*LLena la matriz con los valores 11, 12, 13, 14, 15, 21, 22, ... , 55 */
void llena_mat (int m [F][C]) {
   int i, j;

   for (i = 0; i < F; i++)
      for (j = 0; j < C; j++)
         m [i][j] = 10 * (i + 1) + j + 1;
}

/*Permite al usuario ingresar el valor para una posicion de la matriz */
void lee_elem (int m [F][C]) {
   int f,c;

   printf ("\nFila:");
   scanf ("%d", &f);
   printf ("Col:");
   scanf ("%d", &c);
   printf ("Valor:");
   scanf ("%d", &m [f][c]);
}

/*Genera vector con las sumas de cada columna*/
void calc_vec (int m [F][C], int v []) {
   int f, c;

   for (c = 0; c < C; c++) {
      v [c] = 0;
      for (f = 0; f < F; f++) {
         v [c] += m [f][c];
      }
   }
}

/*Muestra en pantalla la matriz y el vector*/
void muestra (int m [F][C], int v []) {
   int i, j;

   for (i = 0; i < F; i++) {
      printf ("\n");
      for (j = 0; j < C; j++) {
         printf ("%6d", m [i][j]);
      }
   }
   printf ("\n-------------------------------\n");
   for (i = 0; i < C; i++)
      printf ("%6d", v [i]);
}

/* Programa principal */
int main() {
   int mat [F][C], vec [C], op;

   do {
      op = imprime_menu();
      switch (op) {
         case 1:
            lee_archivo (mat);
            break;
         case 2:
            graba_archivo(mat);
            break;
         case 3:
            llena_mat (mat);
            break;
         case 4:
            lee_elem (mat);
            break;
         case 5:
            calc_vec (mat, vec);
            break;
         case 6:
            muestra (mat, vec);
            break;
         case 7:
            break;
         default:
            printf ("\nOpcion invalida");
            break;
      } /* switch */
   } while (op != 7);

    return 0; /* Si llego hasta aca entonces no hubo error */
}
