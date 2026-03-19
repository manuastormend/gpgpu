#include <stdio.h>
#include "funciones.h"
#include <time.h>


int arreglo[tam];//100 Millones de chars = 100MB
int indicesOrdenados[tam];

int main() {

    //inicializo arreglos
    inicializar(arreglo);  
    inicializar(indicesOrdenados);


    //tomo el tiempo que le lleva recorrer el arreglo
    clock_t inicio, fin;
    double tiempo;
    inicio = clock();
    recorrida(arreglo,indicesOrdenados);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", tiempo);


    return 0;
}

