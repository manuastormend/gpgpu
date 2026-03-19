#include <stdio.h>
#include "funciones.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>


int main() {

    srand((unsigned int)time(NULL));

    // Parametros interactivos
    int N = pedir_n_interactivo();
    int orden = pedir_orden_interactivo();
 
    float *A = new float[N*N]; //Inicializo matriz A
    float *B = new float[N*N]; //Inicializo matriz B
    float *C = new float[N*N]; //Inicializo matriz C
 
    for (int i = 0; i < N*N; i++) //Inicializo matriz C en 0
        C[i] = 0;

    for (int i = 0; i < N*N; i++) {
        A[i] = rand() % 10;
        B[i] = rand() % 10;
    }

    //tomo el tiempo que le lleva multiplicar las matrices
    clock_t inicio, fin;
    double tiempo;
    inicio = clock();
    matrix_mult_por_orden(A, B, C, N, orden);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    std::cout << "Orden utilizado: " << nombre_orden_recorrida(orden) << "\n";
    imprimirTiempo(tiempo);
    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
