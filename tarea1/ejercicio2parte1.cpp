#include <stdio.h>
#include "funciones.h"
#include <time.h>


int main() {

    //Inicializo A, B, C, N y BS

    int N = 1024;
    //1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024
    int BS = 1024;
    //N debe ser divisible por Bs si no se puede romper, se sale de rango, los cuadrados no quedan bien
    
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
    matrix_mult(A, B, C, N, BS);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", tiempo);
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
