#include <stdio.h>

int calcularTamanio( char cadena[] )
{
	int cantidadCarecteres = 0, bandera = 0, contador;

	for( contador = 0; bandera == 0; contador++ )
	{
		if( cadena[ contador ] != '\0' )
		{
			cantidadCarecteres++;
		}
		else
		{
			bandera = 1;
		}
	}
	return cantidadCarecteres;
}

void modificarHistoria( char cadena[] )
{
	int cantidadCarecteres = calcularTamanio( cadena ), bandera = 0, contador;

	for( contador = 0; contador < cantidadCarecteres; contador++ )
	{
		if( contador == 0 && cadena[ contador ] >= 97 && cadena[ contador ] <= 122)
		{
			cadena[ contador ] -= 32; 
		}
		else if( cadena[ contador ] == 'g' && cadena[ contador + 1] == 'a' && cadena[ contador + 2 ] == 'b' ||
		         cadena[ contador ] == 'g' && cadena[ contador + 1] == 'a' && cadena[ contador + 2 ] == 'r' && bandera < 2)
		{	
			cadena[ contador ] -= 32;
			bandera++;
		}
	}
}

void contarVocal( char cadena[], char vocal[] )
{
	int cantidadCarecteres = calcularTamanio( cadena ), cantidadVocales = 0, contador;

	for( contador = 0; contador < cantidadCarecteres; contador++ )
	{
		if( vocal[0] == 'a' || vocal[0] == 'e' || vocal[0] == 'i' || vocal[0] == 'o' || vocal[0] == 'u' )
		{
			if( cadena[ contador ] == vocal[0] || cadena[ contador ] == vocal[0] - 32 )
			{
				cantidadVocales++;
			}
		}
		else if( vocal[0] == 'A' || vocal[0] == 'E' || vocal[0] == 'I' || vocal[0] == 'O' || vocal[0] == 'U' )
		{
			if( cadena[ contador ] == vocal[0] || cadena[ contador ] == vocal[0] + 32 )
			{
				cantidadVocales++;
			}
		}
	}
	printf( "\nSe repite %d la vocal digitada en la cadena\n\n", cantidadVocales, vocal );
}

void convertirVocal( char cadena[], char vocal[] )
{
	int cantidadCarecteres = calcularTamanio( cadena ), contador, bandera = 0;

	for( contador = 0; contador < cantidadCarecteres; contador++ )
	{
		if( vocal[0] == 'a' || vocal[0] == 'e' || vocal[0] == 'i' || vocal[0] == 'o' || vocal[0] == 'u' )
		{
			if( cadena[ contador ] == vocal[0] - 32 && bandera == 0 )
			{
				bandera++;
			}
			else if( cadena[ contador ] == vocal[0] && bandera == 0)
			{
				cadena[ contador ] -= 32;
				bandera++;
			}
		}
		else if( vocal[0] == 'A' || vocal[0] == 'E' || vocal[0] == 'I' || vocal[0] == 'O' || vocal[0] == 'U' )
		{
			if( cadena[ contador ] == vocal[0] && bandera == 0)
			{
				bandera++;
			}
			else if( cadena[ contador ] == vocal[0] + 32 && bandera == 0 )
			{
				bandera++;
				cadena[ contador ] -= 32;
			}
		}
	}
	printf( "\n%s\n\n", cadena );	
}

void intercambioVocal( char cadena[], char vocal[] )
{
	int cantidadCarecteres = calcularTamanio( cadena ), contador, bandera = 0;

	for( contador = 0; contador < cantidadCarecteres; contador++ )
	{
		if( vocal[0] == 'a' || vocal[0] == 'e' || vocal[0] == 'i' || vocal[0] == 'o' || vocal[0] == 'u' )
		{
			if( cadena[ contador ] == vocal[0] - 32 && bandera == 0 )
			{
				bandera++;
			}
			else if( cadena[ contador ] == vocal[0] && bandera == 0)
			{
				cadena[ contador ] -= 32;
				bandera++;
			}
			else if( cadena[ contador ] == vocal[0] - 32 && bandera == 1 )
			{
				cadena[ contador ] += 32;
				bandera--;
			}
			else if( cadena[ contador ] == vocal[0] && bandera == 1)
			{
				bandera--;
			}
		}
		else if( vocal[0] == 'A' || vocal[0] == 'E' || vocal[0] == 'I' || vocal[0] == 'O' || vocal[0] == 'U' )
		{
			if( cadena[ contador ] == vocal[0] && bandera == 0)
			{
				bandera++;
			}
			else if( cadena[ contador ] == vocal[0] + 32 && bandera == 0 )
			{
				bandera++;
				cadena[ contador ] -= 32;
			}
			else if( cadena[ contador ] == vocal[0] && bandera == 1 )
			{
				cadena[ contador ] -= 32;
				bandera--;
			}
			else if( cadena[ contador ] == vocal[0] + 32 && bandera == 1)
			{
				bandera--;
			}
		}
	}
	printf( "\n%s\n\n", cadena );	
}

void eliminarCamara( char cadena[] )
{
	int cantidadCarecteres = calcularTamanio( cadena ), contador, contador2, contador3;

	for( contador = 0; contador < cantidadCarecteres; contador++ )
	{
		if( cadena[ contador ] == 'c' && cadena[ contador + 1 ] == 'a' && cadena[ contador + 2 ] == 'm' &&
		    cadena[ contador + 3 ] == 'a' && cadena[ contador + 4 ] == 'r' && cadena[ contador + 5 ] == 'a' )
		{
			for( contador2 = 0; contador2 <= 6; contador2++ )
			{
				for (contador3 = contador; contador3 < cantidadCarecteres ; contador3++ )
				{
					cadena[ contador3 ] = cadena[ contador3 + 1];
				}
			}
		}	
	}
	printf( "\n%s\n\n", cadena );

}

void main()
{
	int opcion;
	char cadena[ 100 ];
	char historiaGabriel[] = "en un comienzo, gabriel garcia Marquez penso en titular su novela La "
							 "Casa, pero se decidio por Cien anios de soledad para evitar confusiones "
							 "con la novela La Casa Grande, publicada en 1954 por su amigo, Alvaro Cepeda Samudio." ;
	char vocal[ 1 ];
	char historiaProfe[] = "Mi profe consiguio una camara vieja antes de la pandemia, pero como "
					       "ahora es un profe digital, el profe se consiguio una camara nueva mas "
					       "bonita. Pasado el tiempo se dio cuenta que la camara nueva aunque bonita "
					       "era una camara mala, pero que bobada, al fin y al cabo, ya sea con una "
					       "camara vieja o una camara nueva, nunca la muestra en clase.";

	do
	{
		printf( "=========================\n"
				"        BIENVENIDO\n"
				"   1. Contar caracteres\n"
				"   2. Corregir a Marquez\n"
				"   3. Cambios con vocales\n"
				"   4. Eliminar camara\n"
				"   0. salir\n"
				"=========================\n" );
		printf( "opcion: " );
		scanf( "%d", &opcion );
		switch( opcion )
		{
			case 1:
					printf( "\nEstimado usuario digite una cadena: " );
					fflush(stdin);
					fgets( cadena, 100, stdin );
					printf( "\nLa cadena digitada tiene %d caracteres\n", calcularTamanio( cadena ) - 1 );
				break;
			case 2:
					printf( "\n%s\n", historiaGabriel );
					modificarHistoria( historiaGabriel );
					printf( "\n%s\n", historiaGabriel );
				break;
			case 3:
					printf( "======================================\n"
							"                Punto 3\n"
							"   1 Contar vocales\n"
							"   2 Primer vocal mayuscula\n"
							"   3 Vocales mayus, minus, mayus...\n"
							"======================================\n" );
					printf( "opcion: " );
					scanf( "%d", &opcion );
					fflush(stdin);
					printf( "\nEstimado usuario digite una vocal: " );
					scanf( "%c", vocal );
					if( opcion == 1 )
					{
						contarVocal( historiaGabriel, vocal );
					}
					else if( opcion == 2 )
					{
						convertirVocal( historiaGabriel, vocal );
					}
					else if( opcion == 3 )
					{
						intercambioVocal( historiaGabriel, vocal );
					}
				break;
			case 4:
					printf( "\n%s\n", historiaProfe );
					eliminarCamara( historiaProfe );
				break;
			case 0:
				break;
			default:
					printf( "opcion invalida" );
		}
	}while( opcion != 0 );

}
