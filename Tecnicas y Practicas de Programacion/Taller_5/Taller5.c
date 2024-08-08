#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
La recursion utilizada en este punto es:
Recursion directa, no final y lineal
*/
int sumaMultiplo( int a, int b)
{
	if( a > b )
	{
		return 0;
	}
	else if( a % 3 == 0 )
	{
		return a + sumaMultiplo( a + 1, b );
	}
	else
	{
		sumaMultiplo( a + 1, b );
	}
}

/*
La recursion utilizada en este punto es:
Recursion directa, final y lineal.
*/
int MaximoComunDivisor( int a, int b )
{
	int residuo = a % b;
	if(b > a)
	{
		residuo = b % a;
		b = a;
	}
	if( residuo == 0 )
	{
		return b;
	}
	else
	{
		return MaximoComunDivisor( b, residuo );
	}
}

void llenarLista( int lista[] )
{
	int i;
	srand(time(NULL));
	for( i = 0; i < 10; i++ )
	{
		lista[ i ] = 1+rand()%(100-1+1);
	}
}

/*
La recursion utilizada en este punto es:
Recursion directa, final y lineal
*/
int valorMayor( int lista[], int repeticiones, int numeroMayor )
{
	if( repeticiones == 0)
	{
		return numeroMayor;
	}
	else
	{
		if( lista[ repeticiones ] > numeroMayor )
		{
			numeroMayor = lista[ repeticiones ];
			return valorMayor( lista, repeticiones - 1, numeroMayor );
		}
		else
		{
			return valorMayor( lista, repeticiones - 1, numeroMayor );
		}
	}
}

/*
La recursion utilizada en este punto es:
Recursion directa, final y lineal
*/
int serieFibonacci( int elementos, int numero, int numero2 )
{
	int temporal;
	if( elementos == 0 )
	{
		return 0;
	}
	else
	{
		printf("%d ", numero2);
		temporal = numero2;
		numero2 = numero + numero2;
		numero = temporal; 
		return serieFibonacci( elementos - 1, numero, numero2 );
	} 
}

/*
La recursion utilizada en este punto es:
Recursion directa, no final y lineal
*/

int fibonacci( int numero, int salida )
{
	if( numero == salida)
	{
		return numero;
	} 
	else
	{
		return numero - 1 + fibonacci( numero - 2, salida );
	}
}

/*
La recursion utilizada en este punto es:
Recursion directa, final y lineal.
*/

int evaluarMatriz( int tamanio, int matriz[ tamanio ][ tamanio ], int filas, int columnas, int suma, int diagonal)
{
	suma += matriz[ filas ][ columnas];
	if( filas == columnas && matriz[ filas ][ columnas ] == 1 )
	{
		diagonal += matriz[ filas ][ columnas ];
	}
	if( filas == tamanio - 1 && columnas == tamanio - 1 )
	{
		return suma == diagonal;
	}
	if( columnas < tamanio - 1 )
	{
		evaluarMatriz( tamanio, matriz, filas, columnas + 1, suma, diagonal );

	}
	else if( filas < tamanio - 1 )
	{
		evaluarMatriz( tamanio, matriz, filas + 1, 0, suma, diagonal );
	}
}

void llenarMatriz( int a, int matriz[a][a] )
{
	int j, i;
	for ( j = 0; j < a; j++ )
	{
		for ( i = 0; i < a; i++ )
		{
			printf( "fila %d columna %d: ", j, i );
			scanf( "%d", &matriz[ j ][ i ] );
		}
	}
	printf("Matriz:\n");
	for ( j = 0; j < a; j++ )
	{
		printf("[ ");
		for ( i = 0; i < a; i++ )
		{
			printf( "%d ", matriz[ j ][ i ] );
		}
		printf("]\n");
	}	
}

void opciones()
{
	printf("==============================\n"
		   "             MENU\n"
		   "1. Suma rango multiplos 3\n"
		   "2. Maximo comun divisor\n"
		   "3. Valor maximo de arreglo\n"
		   "4. Serie de Fibonacci\n"
		   "5. Encontrar matriz identidad\n"
		   "0. Salir\n"
		   "==============================\n"
		   "Opcion: ");
}

void menu( int opcion )
{
	int a = 0, b, i, j;
	int matriz[ a ][ a ];
	int lista[ 10 ];
	if( opcion != 0 )
	{
		switch( opcion )
		{
			case 1:
				printf( "Digite un rango de numeros\n"
			   		    "para encontrar la suma de\n"
			   		    "multiplos de 3\nA: " );
				scanf( "%d", &a );
				printf( "B: " );
				scanf( "%d", &b );
				printf( "Respuesta: %d\n", sumaMultiplo( a, b ) );			
				break;
			case 2:
				printf( "Digite dos numeros para\n"
			   		    "encontrar el maximo comun\n"
			   		    "divisor de los numeros\nA: " );
				scanf( "%d", &a );
				printf( "B: " );
				scanf( "%d", &b );
				printf( "Respuesta: %d\n", MaximoComunDivisor( a, b ) );				
				break;
			case 3:
				llenarLista( lista );
				printf( "Lista: " );			
				for( i = 0; i < 10; i++ )
				{
					printf( "%d ", lista[ i ] );
				}
				printf( "\nEl dato mas alto es: %d\n", valorMayor( lista, 9, lista[ 0 ] ));
				break;
			case 4:
				printf( "Digite un numeros para\n"
			   		    "mostrar cuantos elementos\n"
			   		    "de la serie quiere ver y\n"
			   		    "Para encontrar su numero\n"
			   		    "De fibonacci\nA: " );
				scanf( "%d", &a );
				printf( "Datos mostrados de la serie fibonacci: " );			
				serieFibonacci( a, 0, 1 );
				printf( "\n" );
				printf( "El fibonacci de %d es: %d\n", a, fibonacci( a, a - 2 ) );
				break;
			case 5:
				printf( "Digite un numero para\n"
			   		    "hacer una matriz cuadrara y\n"
			   		    "comenzar a llenarla\nA: " );
			   	scanf( "%d", &a );
				matriz[a][a];
				llenarMatriz( a, matriz );				
				printf( "Respuesta: %d\n", evaluarMatriz( a, matriz, 0, 0, 0, 0 ) );				
				break;
			default:
				printf( "valor invalido\n" );
				break;
		}
		opciones();
		scanf( "%d", &opcion );
		menu( opcion );
	}
    
}

void main()
{
	int opcion;
	opciones();
	scanf("%d", &opcion);
    menu(opcion);
}
