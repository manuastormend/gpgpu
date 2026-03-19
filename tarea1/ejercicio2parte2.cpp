#include <stdio.h>
#include "funciones.h"
#include <time.h>


int main() {

    //Inicializo A, B, C, N 
    int N = 1024;
 
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
    matrix_mult_lineal(A, B, C, N);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    imprimirTiempo(tiempo);
    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
