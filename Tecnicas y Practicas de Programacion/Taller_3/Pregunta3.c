#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void llenarArreglos( int arreglo[], int resultado[], int tamano )
{
    int numeroAleatorio, contador;
	for( contador = 0; contador < tamano; contador++)
    {
    	resultado[ contador ] = 0;
		numeroAleatorio = 1 + rand()%(70-1+1);        
       	arreglo[ contador ] = numeroAleatorio;

    }
	return;
}

void mostrarArreglos( int arreglo[], int tamano )
{
	int mostrar;
	for( mostrar = 0; mostrar < tamano; mostrar++ )
	{
		printf( "%d ", arreglo[ mostrar ] );
	} 
	printf( "\n" );
	return;
}

void main()
{
	int contador1, tamano, posicion = 0, suma = 0, cantidadSumas = 0;

	printf( "Digite cuantas posiciones tendra el arreglo: " );
	scanf( "%d", &tamano );
	int arreglo[ tamano ], resultado[ tamano ];
	srand( time( NULL ) );
	llenarArreglos( arreglo, resultado, tamano );

	printf( "arreglo = " );
	mostrarArreglos( arreglo, tamano );

	for( contador1 = 0; contador1 < tamano; contador1++ )
	{
		suma += arreglo[ contador1 ];
	 	cantidadSumas++;
	 	if( suma + arreglo[ contador1 + 1 ] > 100 )
	 	{
	 		resultado[ posicion++ ] = cantidadSumas;
	 		resultado[ posicion++ ] = suma;
	 		cantidadSumas = suma = 0;
	 	}
	}

	printf( "resultado = " );
	mostrarArreglos( resultado, tamano );

	return;
}