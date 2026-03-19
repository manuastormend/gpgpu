El objetivo de este pr´actico es reflexionar sobre la jerarqu´ıa de memoria, en especial la memoria principal y los distintos niveles de cach´e, y sobre c´omo distintos patrones de acceso a los datos hacen un uso distinto de dicha jerarqu´ıa. En los siguientes ejercicios se acceder´a a una estructura de datos realizando la misma cantidad de operaciones, aunque en distinto orden. Para que los tiempos de ejecuci´on sean lo m´as estables posible se recomienda ejecutar en un sistema con poca carga, medir tiempos lo suficientemente grandes (adaptando el tama˜no de la entrada o la cantidad de repeticiones de las pruebas), y evitar la utilizaci´on de m´aquinas virtuales.

## Ejercicio 1 Localidad espacial

1. Escriba un programa en C/C++ que reserve e inicialice un arreglo de char de gran tama˜no (por ejemplo 100MB). A continuaci´on el programa debe recorrer el arreglo (por ejemplo incrementando el valor de cada posici´on) de manera secuencial (primero la posici´on 0, luego la 1, y as´ı sucesivamente). Durante la recorrida, el siguiente ´ındice a visitar debe leerse de un arreglo inicializado previamente. Registre el tiempo de ejecuci´on de la recorrida.
2. Realice otra recorrida por el arreglo que visite la misma cantidad de elementos pero realizando saltos aleatorios. Durante la recorrida, el siguiente ´ındice a visitar debe leerse de un arreglo inicializado previamente. Mida el tiempo de ejecuci´on y reflexione sobre los resultados.

## Ejercicio 2

Una estrategia muy utilizada en bibliotecas de alto desempe˜no para mejorar el uso de la cach´e en operaciones como la multiplicaci´on de matrices es trabajar por bloques peque˜nos, de tama˜no BS, ajustado de acuerdo a las caracter´ısticas del dispositivo. Un ejemplo puede ser el siguiente:

```cpp
void matrix_mult ( float *A , float *B , float *C , int N) {
int i ,j ,k ,ii , jj , kk ;
for ( ii = 0; ii < N; ii += BS )
for ( jj = 0; jj < N; jj += BS )
for ( kk = 0; kk < N; kk += BS )
for (i = ii ; i < ii + BS ; i ++)
for (j = jj ; j < jj + BS ; j ++)
for (k = kk ; k < kk + BS ; k ++)
C[i *N+j ] += A[ i*N+k ] * B[ k*N+j ];
}
```

1. Para tres matrices de tama˜no m´as grande que la capacidad del cach´e de ´ultimo nivel (LLC), determine experimentalmente el mejor valor de BS. Relacione el desempe˜no obtenido para los distintos valores de BS con los tama˜nos de la cach´e L1 y L2. ¿Los valores son los que esperar´ıa te´oricamente? En caso de encontrar diferencias con la teor´ıa ¿qu´e las explica?.
2. Compare el rendimiento de la versi´on a bloques con el tama˜no de BS ´optimo obtenido en la parte anterior con la variante lineal i, k, j del producto de matrices. Reflexione acerca de los resultados. ¿Qu´e problemas enfrenta la variante a bloques? ¿Podr´ıa modificarla de forma sencilla para mejorar su desempe˜no?
3. Compare el tiempo de ejecuci´on y rendimiento en MFLOPS (N 3/(segundos×106 )) de la versi´on lineal para distintos ordenes de loop (ijk,jik,ikj,kij,jki,kji), al menos para los tama˜nos de matriz 256, 260, 512, 550, 1024, y 1050 (puede extender el experimento incluyendo otros tama˜nos). Reflexione sobre los resultados obtenidos.