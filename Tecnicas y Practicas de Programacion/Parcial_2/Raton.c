#include "Raton.h"

void generarTablero( int tablero[][5] )
{
	int repeticiones, *pTablero;
	pTablero = &tablero[0][0];
	for( repeticiones = 0; repeticiones < 25; repeticiones++ )
	{
		*( pTablero + repeticiones ) = 0;
	}
}

void mostrarTablero( int tablero[][5], int filas, int columnas, int bandera )
{
	if( bandera == 0 )
	{
		printf( "%d ", filas );
		bandera = 1;
	}
		
	if( columnas < 5 )
	{
			printf( "[ " );
			if( tablero[ filas ][ columnas ] == 2 )
			{
				printf( "%c", 'X' );
				printf( " ]" );	
			}
			else
			{
				printf( "%c", 'O' );
				printf( " ]" );	
			}
		mostrarTablero( tablero, filas, columnas + 1, bandera );

	}
	else if( filas < 4 )
	{
		bandera = 0;
		printf( "\n" );
		mostrarTablero( tablero, filas + 1, 0, bandera );
	}
}

void ubicarRaton( int tablero[][5] )
{
	int filaRaton, columnaRaton;

	srand( time( NULL ) );
	filaRaton = rand() % 5;
	columnaRaton = rand() % 5;
	tablero[ filaRaton ][ columnaRaton ] = 1;
	printf( "\n[Pruebas] el raton estan en: %d %d\n", filaRaton, columnaRaton );

}

int interfaz( int vidas, int intentos )
{
	if( vidas == 0 )
	{
		printf( "\n!GANASTE!\n\n" );
		return 1;
	}
	else if( intentos == 0 )
	{
		printf( "\nPERDISTE D=\n\n" );
		return 2;
	}
	printf( "Vidas del raton: %d\n", vidas );
	printf( "Intentos restantes: %d\n", intentos );
	return 0;
}

int pegarRaton( int tablero[][5], int fila, int columna )
{

	if( tablero[ fila ][ columna ] == 1 )
	{
		tablero[ fila ][ columna ] = 2;
		ubicarRaton( tablero );
		printf( "\nLe pegaste al raton\n\n" );
		return 1;
	}
	else
	{
		printf( "\nNo le pegaste al raton\n\n" );
		return 0;
	}

}



