#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mostrarConjutos( int arreglo[] )
{
	int mostrar;
	for( mostrar = 0; mostrar < 20; mostrar++ )
	{
		printf( "%d ", arreglo[ mostrar ] );
	} 
	printf( "\n" );
	return;
}

void llenarArreglos( int arreglo[] )
{
    int numeroAleatorio, contador;
	for( contador = 0; contador < 20; contador++)
    {
		numeroAleatorio = 1 + rand()%(10-1+1);        
       	arreglo[ contador ] = numeroAleatorio;
    }
	return;
}

void main()
{
	int contadorConjuntos, contadorConjunto, datoRepetido = 0, respuestaRepetido = 0, posicion = 0,
	A[ 20 ], B[ 20 ], C[ 20 ], D[ 20 ] = { 0 };

	srand( time( NULL ) );
	llenarArreglos( A );
	llenarArreglos( B );
	llenarArreglos( C );

	printf( "A = " );
	mostrarConjutos( A );
	printf( "B = " );
	mostrarConjutos( B );
	printf( "C = " );
	mostrarConjutos( C );

	for( contadorConjuntos = 0; contadorConjuntos < 20; contadorConjuntos++ )
	{
		for( contadorConjunto = 0; contadorConjunto < 20; contadorConjunto++ )
		{
			if( A[ contadorConjuntos ] == B[ contadorConjunto ] )
			{
				datoRepetido++;
			}
		}
		for( contadorConjunto = 0; contadorConjunto < 20; contadorConjunto++ )
		{
			if( A[ contadorConjuntos ] == C[ contadorConjunto ] )
			{
				datoRepetido++;
			}
		}
		if( datoRepetido >= 2 )
		{
			for( contadorConjunto = 0; contadorConjunto < 20; contadorConjunto++ )
			{
				if( A[ contadorConjuntos ] == D[ contadorConjunto ] )
				{
					respuestaRepetido++;
				}
			}
			if( respuestaRepetido == 0 )
			{
				D[ posicion++ ] = A[ contadorConjuntos ];
			}									
		}
		datoRepetido = respuestaRepetido = 0;	
	}
	printf( "D = " );
	mostrarConjutos( D );
}