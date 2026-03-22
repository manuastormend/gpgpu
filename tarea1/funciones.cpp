#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <iostream>
#include <iomanip> 
#include <limits>
#include "funciones.h"


void recorrida(int arr[tam],int index[tam]){
    //accedo a las posiciones de memoria segun me indique mi arreglo index
    for(int i = 0; i<tam; i++){
        arr[index[i]]= i;
    }
}

void recorridaChars(char arr[tam],int index[tam]){
    //accedo a las posiciones de memoria segun me indique mi arreglo index
    for(int i = 0; i<tam; i++){
        arr[index[i]]= 'b';
    }
}

void inicializar(int arr[tam]){
    for(int i = 0; i<tam; i++){
        arr[i]= i;
    }
}

void inicializarChars(char arr[tam]){
    for(int i = 0; i<tam; i++){
        arr[i]= 'a';
    }
}

void mezclar(int arr[tam]){
    for(int j = 0; j < tam/2; j++){
        int r1 = rand() % tam;
        int r2 = rand() % tam;

        int temp = arr[r1];
        arr[r1] = arr[r2];
        arr[r2] = temp;
    }  
}

void imprimirTiempo(double tiempoSegundos) {
    std::cout << "Tiempo de ejecucion: " 
              << std::fixed << std::setprecision(6) // 6 decimales
              << tiempoSegundos 
              << " segundos\n";
}

void matrix_mult ( float *A , float *B , float *C , int N, int BS) {
    int i ,j ,k ,ii , jj , kk ;
    for ( ii = 0; ii < N; ii += BS )
        for ( jj = 0; jj < N; jj += BS )
            for ( kk = 0; kk < N; kk += BS )
                for (i = ii ; i < ii + BS ; i ++)
                    for (j = jj ; j < jj + BS ; j ++)
                        for (k = kk ; k < kk + BS ; k ++)
                            C[i *N+j ] += A[ i*N+k ] * B[ k*N+j ];
    }

void matrix_mult_lineal(float *A, float *B, float *C, int N) {
    for (int i = 0; i < N; i++)
        for (int k = 0; k < N; k++)
            for (int j = 0; j < N; j++)
                C[i * N + j] += A[i * N + k] * B[k * N + j];
}

const char* nombre_orden_recorrida(int orden) {
    switch (orden) {
        case 1: return "ijk";
        case 2: return "ikj";
        case 3: return "jik";
        case 4: return "jki";
        case 5: return "kij";
        case 6: return "kji";
        default: return "ikj";
    }
}

void matrix_mult_por_orden(float *A, float *B, float *C, int N, int orden) {
    switch (orden) {
        case 1: // ijk
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    for (int k = 0; k < N; k++)
                        C[i * N + j] += A[i * N + k] * B[k * N + j];
            break;
        case 2: // ikj
            for (int i = 0; i < N; i++)
                for (int k = 0; k < N; k++)
                    for (int j = 0; j < N; j++)
                        C[i * N + j] += A[i * N + k] * B[k * N + j];
            break;
        case 3: // jik
            for (int j = 0; j < N; j++)
                for (int i = 0; i < N; i++)
                    for (int k = 0; k < N; k++)
                        C[i * N + j] += A[i * N + k] * B[k * N + j];
            break;
        case 4: // jki
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    for (int i = 0; i < N; i++)
                        C[i * N + j] += A[i * N + k] * B[k * N + j];
            break;
        case 5: // kij
            for (int k = 0; k < N; k++)
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < N; j++)
                        C[i * N + j] += A[i * N + k] * B[k * N + j];
            break;
        case 6: // kji
            for (int k = 0; k < N; k++)
                for (int j = 0; j < N; j++)
                    for (int i = 0; i < N; i++)
                        C[i * N + j] += A[i * N + k] * B[k * N + j];
            break;
        default:
            matrix_mult_lineal(A, B, C, N);
            break;
    }
}

int pedir_n_interactivo() {
    int N = 0;
    while (true) {
        std::cout << "Ingrese N (tamano de la matriz NxN, entero positivo): ";
        std::cin >> N;
        if (std::cin.fail() || N <= 0) {
            std::cout << "Valor invalido. Intente nuevamente.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return N;
    }
}

int pedir_orden_interactivo() {
    int orden = 0;
    while (true) {
        std::cout << "\nSeleccione orden de recorrida:\n";
        std::cout << "1) ijk\n";
        std::cout << "2) ikj\n";
        std::cout << "3) jik\n";
        std::cout << "4) jki\n";
        std::cout << "5) kij\n";
        std::cout << "6) kji\n";
        std::cout << "Opcion: ";
        std::cin >> orden;

        if (std::cin.fail() || orden < 1 || orden > 6) {
            std::cout << "Opcion invalida. Intente nuevamente.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return orden;
    }
}