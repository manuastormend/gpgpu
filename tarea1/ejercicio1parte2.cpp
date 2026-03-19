#include <stdio.h>
#include "funciones.h"
#include <time.h>


int arreglo[tam];//100 Millones de chars = 100MB
int indicesMezclados[tam];

int main() {
    
    //tomo el tiempo que le lleva inicializar + mezclar
    clock_t inicioMezcla, finMezcla;
    double tiempoMezcla;
    inicioMezcla = clock();
    inicializar(arreglo);
    inicializar(indicesMezclados);
    //mezclamos los numeros
    mezclar(indicesMezclados);
    finMezcla = clock();
    tiempoMezcla = (double)(finMezcla - inicioMezcla) / CLOCKS_PER_SEC;
    printf("Tiempo mezcla: %f segundos\n", tiempoMezcla);

    //tomo el tiempo que le lleva recorrer el arreglo
    clock_t inicio, fin;
    double tiempo;
    inicio = clock();
    recorrida(arreglo,indicesMezclados);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", tiempo);
    return 0;
}

