#include "Raton.h"

void main()
{	
	printf( "\nBIENVENIDO A EL JUEGO DEL RATON\n" ); 
	int tablero[5][5], vidas = 3, intentos = 10, fila, columna, resultado;
	generarTablero( tablero );
	ubicarRaton( tablero );
	while( interfaz( vidas, intentos ) == 0 )
	{
		printf( "    0    1    2    3    4\n" );
		mostrarTablero( tablero, 0, 0, 0 );
		printf( "\nEs momento de jugar digita la fila\n" 
				"y columna donde crees que estara\n"
				"el raton\nFila: ");
		scanf( "%d", &fila );
		printf( "columna: " );
		scanf( "%d", &columna );
		resultado = pegarRaton( tablero, fila, columna );
		if(  resultado == 1 )
		{
			vidas -= 1;
		}
		else
		{
			intentos -= 1;
		}
	}
	printf( "    0    1    2    3    4\n" );
	mostrarTablero( tablero, 0, 0, 0 );
	printf("\n\n");
}