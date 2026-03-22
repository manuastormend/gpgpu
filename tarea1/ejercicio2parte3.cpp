#include <stdio.h>
#include "funciones.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>


int main() {

    srand((unsigned int)time(NULL));

    // Parametro interactivo
    int N = pedir_n_interactivo();
 
    float *A = new float[N*N]; //Inicializo matriz A
    float *B = new float[N*N]; //Inicializo matriz B
    float *C = new float[N*N]; //Inicializo matriz C

    for (int i = 0; i < N*N; i++) {
        A[i] = rand() % 10;
        B[i] = rand() % 10;
    }

    std::cout << "\nResultados para N = " << N << ":\n";
    std::cout << "----------------------------------------\n";

    for (int orden = 1; orden <= 6; orden++) {
        for (int i = 0; i < N * N; i++) // Reinicio C para cada medicion
            C[i] = 0.0f;

        // tomo el tiempo que le lleva multiplicar las matrices
        clock_t inicio = clock();
        matrix_mult_por_orden(A, B, C, N, orden);
        clock_t fin = clock();
        double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
        double mflops = ((double)N * N * N) / (tiempo * 1e6);

        std::cout << "Orden utilizado: " << nombre_orden_recorrida(orden) << "\n";
        imprimirTiempo(tiempo);
        std::cout << "Rendimiento: " << mflops << " MFLOPS\n\n";
    }

    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
