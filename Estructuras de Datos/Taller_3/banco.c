#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CAPACIDAD 100 

void calendario( char* fechaActual )
{
    time_t t;
    struct tm *tm;
    char fecha[ 100 ], hora[ 100 ], textosUnidos[ 100 ];
    const char* datofecha = fecha;
    const char* datoHora = hora;
    t = time( NULL );
    tm = localtime(&t);
    strftime( fecha, 100, "%d/%m/%Y ", tm );
    strftime( hora, 100, "%H:%M:%S", tm );
    strcat( strcpy( textosUnidos, datofecha ), datoHora );
    strcpy( fechaActual, textosUnidos );
    return;
}

typedef struct cliente
{
  char nombre[ 10 ], tipoCuenta[ 1 ];
  int saldo;
} cliente;

void menu()
{
   printf( "\nBANCO ELEMENTAL\n" );
   printf( "==============\n" );
   printf( "1. agregar\n" );
   printf( "2. consultar\n" );
   printf( "3. eliminar\n" );
   printf( "4. editar\n" );
   printf( "5. depositar\n" );
   printf( "6. retirar\n" );
   printf( "7. listar\n" );
   printf( "8. reporte\n" );
   printf( "9. transferir\n" );
   printf( "10. loteria\n" );
   printf( "0. salir\n" );
   printf( "opcion: " );
   return;
}

void main()
{
	int contador1, contador2, contador3, opcion, numeroUsuario = 0, dinero, 
	sumaSaldo = 0, naoyGana = 0, bandera = 0, loteria, cuentasA = 0, cuentasC = 0;	
	char nombre[ 10 ], fechaActual[ 100 ];
	calendario( fechaActual );
	FILE *datosBanco;
	FILE *log = fopen( "log.txt", "a" );
	cliente usuarios[ CAPACIDAD ];
	cliente temporal;
	datosBanco = fopen( "banco.dat", "rb" );
	fread( &numeroUsuario, sizeof( int ), 1, datosBanco );
	fread( usuarios, sizeof( usuarios ), 1, datosBanco );
	fclose( datosBanco );
	fprintf( log, "%s el programa inicio\n", fechaActual );
	do
	{
		menu();
		scanf( "%d", &opcion );
		switch( opcion )
		{
			case 1:		
               printf( "Digite su nombre de usuario: " );
               scanf( "%s", usuarios[ numeroUsuario ].nombre );
               printf( "Digite el saldo que desea agregar: " );
               scanf( "%d", &usuarios[ numeroUsuario ].saldo );
               printf( "Cuenta de Ahorro = A\n" );
               printf( "Cuenta de Corriente = C\n" );
               printf( "Digite su tipo de cuenta: " );
               scanf( "%s", usuarios[ numeroUsuario++ ].tipoCuenta );
               fprintf( log, "%s %s fue añadido con %d de saldo\n", fechaActual, 
               usuarios[ numeroUsuario - 1 ].nombre, usuarios[ numeroUsuario - 1 ].saldo  ); 

				break;
			case 2:
               printf( "Digite el nombre del usuario que desea consultar: " );
               scanf( "%s", nombre );
               for( contador1 = 0; contador1 < numeroUsuario; contador1++ )
               {
                  if( strcmp( nombre, usuarios[ contador1 ].nombre ) == 0 )
                  {
                    	printf( "Querido usuario/a %s su saldo actual es %d\n", 
                    	usuarios[ contador1 ].nombre, usuarios[ contador1 ].saldo );
                    	fprintf( log, "%s %s fue buscado\n", fechaActual, usuarios[ contador1 ].nombre ); 
                  }
               }
				break;
			case 3:
              	printf( "Digite el nombre del usuario que desea eliminar: " );
               scanf( "%s", nombre );
		      	for( contador1 = 0; contador1 < numeroUsuario; contador1++ )
		        	{
		        		if( strcmp( nombre, usuarios[ contador1 ].nombre ) == 0 )
		         	{
		            	for( contador2 = contador1; contador2 < numeroUsuario - 1; contador2++ )
		            	{
		              		usuarios[ contador2 ] = usuarios[ contador2 + 1 ];
		            	}
		            	fprintf( log, "%s %s fue eliminado/a\n", fechaActual, usuarios[ contador1 ].nombre );
		         	}
		        	}
		        	numeroUsuario--;		
				break;
			case 4:
               printf( "Digite el nombre del usuario que desea modificar: " );
               scanf( "%s", nombre );
               for( contador1 = 0; contador1 < numeroUsuario; contador1++ )
               {
                  if( strcmp( nombre, usuarios[ contador1 ].nombre ) == 0 )
                  {
                  	fprintf( log, "%s %s cambio su nombre a ", fechaActual, usuarios[ contador1 ].nombre );
	                  printf( "Querido usuario/a digite su nuevo nombre de usuario: " );
							scanf( "%s", usuarios[ contador1 ].nombre ); 
							fprintf( log, "%s\n", usuarios[ contador1 ].nombre );
                  }
               }
				break;
			case 5:
               printf( "Digite el nombre del usuario que desea depositar: " );
               scanf( "%s", nombre );
               for( contador1 = 0; contador1 < numeroUsuario; contador1++ )
               {
                  if( strcmp( nombre, usuarios[ contador1 ].nombre ) == 0 )
                  {
                    	printf( "Digite el monto a depositar " );
                    	scanf( "%d", &dinero );
                    	if( dinero < 0)
                    	{
                    		printf("Cantidad de dinero invalida\n");
                    	}
                    	else
                    	{
                    		usuarios[ contador1 ].saldo += dinero;
                    	}

                  }
                  fprintf( log, "%s %s deposito %d\n", fechaActual, usuarios[ contador1 ].nombre, dinero );
               }				
				break;
			case 6:
              	printf( "Digite el nombre del usuario que desea retirar: " );
               scanf( "%s", nombre );
               for( contador1 = 0; contador1 < numeroUsuario; contador1++ )
               {	
                  if( strcmp( nombre, usuarios[ contador1 ].nombre ) == 0 )
                  {
                    	printf( "Digite el monto a retirar " );
                    	scanf( "%d", &dinero );
                    	if( dinero > usuarios[ contador1 ].saldo || dinero < 0)
                    	{
                    		printf("Cantidad de dinero invalida\n");
                    	}
                    	else
                    	{
                    		usuarios[ contador1 ].saldo -= dinero;
                    	}                    
                  }
                  fprintf( log, "%s %s retiro %d\n", fechaActual, usuarios[ contador1 ].nombre, dinero );
               }
				break;
			case 7:
            	printf( "NOMBRE           SALDO\n"
                       "========== ===========\n" );
               for( contador1 = 0; contador1 < numeroUsuario; contador1++ )
               {
                	printf( "%-11s %10d\n", usuarios[ contador1 ].nombre, usuarios[ contador1 ].saldo );
               }
               fprintf( log, "%s se genero una lista\n", fechaActual );    				
				break;
			case 8:          	
	            for( contador1 = 0; contador1 < numeroUsuario; contador1++ )
	            {	
		            for( contador2 = 0, contador3 = 1; contador3 < numeroUsuario; contador2++, contador3++ )
		            {	
		            	if( usuarios[ contador2 ].saldo > usuarios[ contador3 ].saldo )
		            	{
		            		temporal = usuarios[ contador3 ];
		            		usuarios[ contador3 ] = usuarios[ contador2 ];
		            		usuarios[ contador2 ] = temporal;    
		            	}
		            }	            	
	            }
	            datosBanco = fopen( "reporte.txt", "w" );
            	fprintf( datosBanco, "NOMBRE           SALDO\n"
                       "========== ===========\n" );
               for( contador1 = 0; contador1 < numeroUsuario; contador1++ )
               {
                	fprintf( datosBanco, "%-11s %10d\n", usuarios[ contador1 ].nombre, usuarios[ contador1 ].saldo );
                	sumaSaldo += usuarios[ contador1 ].saldo;
                	if( strcmp ("A", usuarios[ contador1 ].tipoCuenta ) == 0 || strcmp ("a", usuarios[ contador1 ].tipoCuenta ) == 0)
                	{
                		cuentasA++;
                	}
                	else if( strcmp ("C", usuarios[ contador1 ].tipoCuenta ) == 0 || strcmp ("c", usuarios[ contador1 ].tipoCuenta ) == 0 )
                	{
                		cuentasC++;
                	}               	
              	}
               fprintf( datosBanco, "Total saldos %d\n", sumaSaldo );
               fprintf( datosBanco, "Existen en total %d cuentas de ahorro\n", cuentasA );
               fprintf( datosBanco, "Existen en total %d cuentas corrientes\n", cuentasC );
               fclose( datosBanco );
               system( "notepad reporte.txt" );
               sumaSaldo = 0;
               cuentasA = 0;
               cuentasC = 0;
               fprintf( log, "%s se genero un reporte en reporte.txt\n", fechaActual );
				break;
			case 9:
               printf( "Digite su nombre de usuario: " );
               scanf( "%s", nombre );
               for( contador1 = 0; contador1 < numeroUsuario; contador1++ )
               {
                  if( strcmp( nombre, usuarios[ contador1 ].nombre ) == 0 )
                  {
                    	printf( "Digite el monto a tranferir: " );
                    	scanf( "%d", &dinero );

	                  if( dinero > usuarios[ contador1 ].saldo )
	                  {
	                  	printf( "Transferencia invalida\n" );
	                  }
	                  else
	                  {
	              		 	printf( "Nombre del usuario a tranferir: " );
	               		scanf( "%s", nombre );                 	
			               for( contador2 = 0; contador2 < numeroUsuario; contador2++ )
			               {
			               	fprintf( log, "%s %s le transfirio a %s %d\n", fechaActual, usuarios[ contador1 ].nombre, usuarios[ contador2 ].nombre, dinero );
			                  if( strcmp( nombre, usuarios[ contador2 ].nombre ) == 0 )
			                  {
			                  	usuarios[ contador1 ].saldo -= dinero;
			                  	usuarios[ contador2 ].saldo += dinero;
			                  }
			               }               	
	                  }
       
                  }
               }
				break;
			case 10:
					srand(time(NULL));
					loteria = 0 + rand()%( numeroUsuario-0+1);
					usuarios[ loteria ].saldo += 1000000;
				break;					
			case 777:		
               for( contador1 = 0; contador1 < numeroUsuario; contador1++ )
               {
                  if( strcmp( "naoy_noznip", usuarios[ contador1 ].nombre ) == 0 )
                  {
							bandera++;                  	
                  }
               }
               if( bandera == 0 )
               {
              		strcpy( usuarios[ numeroUsuario ].nombre, "naoy_noznip" );              		
               	usuarios[ numeroUsuario ].saldo = 0;
               	usuarios[ numeroUsuario++ ].tipoCuenta, "B";
               }
               for( contador1 = 0; contador1 < numeroUsuario; contador1++ )
               {
                  if( strcmp( "naoy_noznip", usuarios[ contador1 ].nombre ) != 0 )
                  {
                    	usuarios[ contador1 ].saldo -= 10;
                    	naoyGana += 10;
                  }
               }
               for( contador1 = 0; contador1 < numeroUsuario; contador1++ )
               {
                  if( strcmp( "naoy_noznip", usuarios[ contador1 ].nombre ) == 0 )
                  {
							usuarios[ contador1 ].saldo += naoyGana;                 	
                  }
               }
               naoyGana = 0;               					
				break;		
			case 0:
					fprintf( log, "%s el programa termino\n", fechaActual );
				break;				
			default: 
				printf( "Opcion digitada incorrecta, vuelve a intentar\n" );
		}

	}while( opcion != 0 );
	datosBanco = fopen( "banco.dat", "wb" );
	fwrite( &numeroUsuario, sizeof(int), 1, datosBanco);
	fwrite( usuarios, sizeof( usuarios ), 1, datosBanco );
	fclose( datosBanco );
	return;
}