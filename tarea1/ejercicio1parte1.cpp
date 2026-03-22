#include <stdio.h>
#include "funciones.h"
#include <time.h>


char arreglo[tam];//100 Millones de chars = 100MB
int indicesOrdenados[tam];

int main() {

    //inicializo arreglos
    inicializarChars(arreglo);  
    inicializar(indicesOrdenados);


    //tomo el tiempo que le lleva recorrer el arreglo
    clock_t inicio, fin;
    double tiempo;
    inicio = clock();
    recorridaChars(arreglo,indicesOrdenados);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", tiempo);


    return 0;
}

