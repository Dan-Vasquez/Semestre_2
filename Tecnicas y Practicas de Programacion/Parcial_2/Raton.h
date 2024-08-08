#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generarTablero( int tablero[][5] );
void mostrarTablero( int tablero[][5], int filas, int columnas, int bandera );
void ubicarRaton( int tablero[][5] );
int interfaz( int vidas, int intentos );
int pegarRaton( int tablero[][5], int fila, int columna );