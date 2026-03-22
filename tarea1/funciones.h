// funciones.h
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>

const int tam = 100000000; // 100 millones

void recorrida(int arr[tam], int index[tam]);
void recorridaChars(char arr[tam],int index[tam]);
void inicializar(int arr[tam]);
void inicializarChars(char arr[tam]);
void mezclar(int arr[tam]);
void imprimirTiempo(double tiempoSegundos);
void matrix_mult ( float *A , float *B , float *C , int N, int BS);
void matrix_mult_lineal(float *A, float *B, float *C, int N);
void matrix_mult_por_orden(float *A, float *B, float *C, int N, int orden);
const char* nombre_orden_recorrida(int orden);
int pedir_n_interactivo();
int pedir_orden_interactivo();

#endif