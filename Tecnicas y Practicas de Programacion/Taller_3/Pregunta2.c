#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mostrarArreglos( int arreglo[] )
{
	int mostrar, *pArreglo = arreglo;
	for( mostrar = 0; mostrar < 40; mostrar++ )
	{
		printf( "%d ", *(pArreglo++) );
	} 
	printf( "\n" );
}

void llenarArreglos( int arreglo[] )
{
    int numeroAleatorio, contador, *pArreglo = arreglo;
	for( contador = 0; contador < 40; contador++)
    {
		numeroAleatorio = 100 + rand()%(2500-100+1);        
       	*(pArreglo++) = numeroAleatorio;
    }
}

void main()
{
	int arreglo[ 40], *pArreglo = arreglo, contador, menorDiferencia = 0, numeroTemporal = 0,
	*clave1, *clave2;
	srand( time( NULL ) );
	llenarArreglos( arreglo );
	printf( "arreglo = " );
	mostrarArreglos( arreglo );
	for( contador = 0; contador < 40; contador++ )
	{
		if( *(pArreglo) + *(pArreglo + 1) >= 3333)
		{
			printf( "Posicion X %d\nPosicion Y %d\n", *(pArreglo), *(pArreglo + 1) );
			printf( "Suma posiciones %d\n", *(pArreglo) + *(pArreglo + 1) );
			if( menorDiferencia == 0)
			{
				numeroTemporal = *(pArreglo) - *(pArreglo + 1);
				if(numeroTemporal < 0)
				{
					numeroTemporal *= -1;
					menorDiferencia = numeroTemporal;
					clave1 = (pArreglo);
					clave2 = (pArreglo + 1);

				}
				else
				{
					menorDiferencia = numeroTemporal;
					clave1 = (pArreglo);
					clave2 = (pArreglo + 1);				
				}
			}
			else
			{
				numeroTemporal = *(pArreglo) - *(pArreglo + 1);
				if( numeroTemporal < 0 )
				{
					numeroTemporal *= -1;
					if( numeroTemporal < menorDiferencia )
					{
						menorDiferencia = numeroTemporal;
					clave1 = (pArreglo);
					clave2 = (pArreglo + 1);					
					}
				}
				else
				{
					if( numeroTemporal < menorDiferencia )
					{
						menorDiferencia = numeroTemporal;
					clave1 = (pArreglo);
					clave2 = (pArreglo + 1);						
					}	
				}				
			}
		}
		pArreglo++;
	}
	printf("menor diferencia %d\n", menorDiferencia );
	printf( "Las claves son\nClave1 %x\nClave2 %x\n", clave1, clave2 );
}