#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define CAPACIDAD 100

typedef struct pedidos
{
	char nombre[ 12 ];
	int panes,
	galletas,
	pasteles, 
	cuenta;
} pedidos;

void calendario( char* fecha )
{
	time_t t;
	struct tm *tm;
	char fechaActual[ 100 ], hora[ 100 ], textosUnidos[ 100 ];
	const char* datosFecha = fechaActual;
	const char* datosHora = hora;
	t = time( NULL );
	tm = localtime( &t );
	strftime( fechaActual, 100, "%d/%m/%Y ", tm );
	strftime( hora, 100, "%H:%M:%S", tm );
	strcat( strcpy( textosUnidos, datosFecha ), datosHora );
	strcpy( fecha, textosUnidos );
	return;
}

void menu()
{
	printf( "        Panederia Elemenal\n" );
	printf( "=================================\n" );
	printf( "1.  Comprar ingredientes\n" );
	printf( "2.  Hacer pan, pastel o galletas\n" );
	printf( "3.  Carta de precios\n" );
	printf( "4.  Recibir pedidos\n" );
	printf( "5.  Consultar pedido\n" );
	printf( "6.  Eliminar pedidos\n" );
	printf( "7.  Modificar pedidos\n" );
	printf( "8.  Listar pedidos\n" );
	printf( "9.  Generar reporte\n" );
	printf( "10. Vender pedido\n" );
	printf( "11. Hacer rebaja a todos los clientes\n" );
	printf( "12. Regalar pedido a un cliente aleatorio\n" );
	printf( "44. Regalar x5 de un producto a todos los clientes (Secreto)\n" );
	printf( "0.  Salir\n" );
	printf( "Opcion: " );
}

void main()
{
	int opcion, productos, producto, numeroClientes = 0, mostrar, contador1, contador2, contador3, regalo, 
	sumaCuenta = 0, harina = 0, huevos = 0, leche = 0, panes = 0, galletas = 0, pasteles = 0,
	dinero = 100000;
	char nombre[ 12 ], fecha[ 100 ];
	calendario( fecha ); 
	pedidos cliente[ CAPACIDAD ];
	pedidos temporal;
	FILE *log = fopen( "log.txt", "a" );	
	FILE *copiaSegura;
	copiaSegura = fopen( "copia.dat", "rb" );
	fread( &numeroClientes, sizeof( int ), 1, copiaSegura );
	fread( &harina, sizeof( int ), 1, copiaSegura );
	fread( &huevos, sizeof( int ), 1, copiaSegura );
	fread( &leche, sizeof( int ), 1, copiaSegura );
	fread( &panes, sizeof( int ), 1, copiaSegura );
	fread( &galletas, sizeof( int ), 1, copiaSegura );
	fread( &pasteles, sizeof( int ), 1, copiaSegura );
	fread( &dinero, sizeof( int ), 1, copiaSegura );
	fread( cliente, sizeof( cliente ), 1, copiaSegura );
	fclose( copiaSegura );
	fprintf( log, "%s El programa inicio\n", fecha);
	do
	{
		menu();
		scanf( "%d", &opcion );
		switch( opcion )
		{
			case 1:
				printf( "==================================\n" 
						"          1. harina\n" 
						"          2. huevos\n" 
						"          3. leche\n"
						"          4. harina + huevos\n" 
						"          5. harina + huevos + leche\n"  
						"==================================\n" );
				printf( "Que producto/s va a comprar: " );
				scanf( "%d", &productos );
				if( productos == 1 || productos == 4 || productos == 5 )
				{
					printf( "Cuanta harina va a llevar: " );
					scanf( "%d", &producto );
					if( dinero >= 8 * producto )
					{
						harina += producto;
						dinero -= 8 * producto;
						fprintf( log, "%s Se compraron %d paquetes de harina\n", fecha, producto );						
					}
					else
					{
						printf( "Dinero insuficiente hay %d\n", dinero );
					}
					
				}
				if( productos == 2 || productos == 4 || productos == 5 )
				{
					printf( "Cuantos huevos va a llevar: " );
					scanf( "%d", &producto );
					if( dinero >= 2 * producto )
					{	
						huevos += producto;				
						dinero -= 2 * producto;
						fprintf( log, "%s Se compraron %d huevos\n", fecha, producto );
					}
					else
					{
						printf( "Dinero insuficiente hay %d\n", dinero );
					}
					
				}
				if( productos == 3 || productos == 5 )
				{
					printf( "Cuanta leche va a llevar: " );
					scanf( "%d", &producto );
					if( dinero >= 10 * producto )
					{	
						leche += producto;				
						dinero -= 10 * producto;
						fprintf( log, "%s Se compraron %d cajas de leche\n", fecha, producto );
					}
					else
					{
						printf( "Dinero insuficiente hay %d\n", dinero );
					}

				}
				printf( "El dinero de la panaderia es %d\n", dinero );
			   break;
			case 2:
				printf( "==================================\n" 
						"          1. Panes\n" 
						"          2. galletas\n" 
						"          3. pasteles\n"
						"          4. panes + galletas\n" 
						"          5. panes + galletas + pasteles\n"  
						"==================================\n" );
				printf( "Que producto/s va a hacer: " );
				scanf( "%d", &productos );
				if( productos == 1 || productos == 4 || productos == 5 )
				{
					printf( "Cuantos panes va a hacer: " );
					scanf( "%d", &producto );
					if( leche = huevos = harina >= 2 * producto )
					{
						panes += producto;
						leche = huevos = harina -= 2 * producto;
						fprintf( log, "%s Se realizaron %d panes\n", fecha, producto);						
					}
					else
					{
						printf( "ingredientes insuficiente hay\nharina %d\nhuevos %d\nleche %d\n", harina, huevos, leche );
					}
				}
				if( productos == 2 || productos == 4 || productos == 5 )
				{
					printf( "Cuantas galletas va a hacer: " );
					scanf( "%d", &producto );
					if( leche = huevos = harina >= 1 * producto )
					{					
						galletas += producto;
						leche = huevos = harina -= 1 * producto;
						fprintf( log, "%s Se realizaron %d galletas\n", fecha, producto);
					}
					else
					{
						printf( "ingredientes insuficiente hay\nharina %d\nhuevos %d\nleche %d\n", harina, huevos, leche  );
					}
				}
				if( productos == 3 || productos == 5 )
				{
					printf( "Cuantos pasteles va a hacer: " );
					scanf( "%d", &producto );
					if( leche = huevos = harina >= 3 * producto )
					{	
						pasteles += producto;
						leche = huevos = harina -= 3 * producto;
						fprintf( log, "%s Se realizaron %d pasteles\n", fecha, producto);
					}
					else
					{
						printf( "ingredientes insuficiente hay\nharina %d\nhuevos %d\nleche %d\n", harina, huevos, leche  );
					}											
				}
			   break;
			case 3:
				printf( "BIENVENIDO/A A PANADERIA ELEMENTAL\n" 
						"==================================\n" 
						"          galleta = 50\n" 
						"          Pan = 100\n" 
						"          Pastel = 200\n" 
						"==================================\n" );
				fprintf( log, "%s Se consulto la carta de precios\n", fecha);
			   break;
			case 4:
				printf( "Digite un nombre: " );
				scanf( "%s", cliente[ numeroClientes ].nombre );
				printf( "==================================\n" 
						"          1. Panes\n" 
						"          2. galletas\n" 
						"          3. pasteles\n"
						"          4. panes + galletas\n" 
						"          5. panes + galletas + pasteles\n"  
						"==================================\n" );
				printf( "Digite cuantos que producto/s llevara: " );
				scanf( "%d", &productos );
				if( productos == 1 || productos == 4 || productos == 5 )
				{
					printf( "Cuantos panes va a llevar: " );
					scanf( "%d", &producto );
					if( panes >= producto )
					{
						cliente[ numeroClientes ].panes = producto;
						cliente[ numeroClientes ].cuenta = ( producto * 100 );
						panes -= producto;
					}
					else
					{
						printf( "Panes insuficiente hay %d\n", panes );
					}					
				}
				if( productos == 2 || productos == 4 || productos == 5 )
				{
					printf( "Cuantas galletas va a llevar: " );
					scanf( "%d", &producto );
					if( galletas >= producto )
					{
						cliente[ numeroClientes ].galletas = producto;
						cliente[ numeroClientes ].cuenta += ( producto * 50 );
						galletas -= producto;
					}
					else
					{
						printf( "Galletas insuficiente hay %d\n", galletas );
					}					
				}
				if( productos == 3 || productos == 5 )
				{
					printf( "Cuantos pasteles va a llevar: " );
					scanf( "%d", &producto );
					if( panes >= producto )
					{
						cliente[ numeroClientes ].pasteles = producto;
						cliente[ numeroClientes ].cuenta += ( producto * 200 );
						pasteles -= producto;
					}
					else
					{
						printf( "Pasteles insuficiente hay %d\n", pasteles );
					}											
				}
				if( cliente[ numeroClientes ].cuenta > 0 )
				{
					printf( "La cuenta es: %d\n", cliente[ numeroClientes++ ].cuenta );
					fprintf( log, "%s El pedido de %s fue registrado con una cuenta de %d\n", fecha, 
						     cliente[ numeroClientes - 1 ].nombre, cliente[ numeroClientes - 1 ].cuenta);					
				}				
			   break;
			case 5:
				printf( "Digite el nombre del pedido a consultar: " );
				scanf( "%s", nombre );
				for( contador1 = 0; contador1 < numeroClientes; contador1++ )
				{
					if( strcmp( nombre, cliente[ contador1 ].nombre ) == 0 )
					{
						printf( "Los productos del usuario %s son:\n", nombre );
						printf( "panes %d, galletas %d, pasteles %d\n", cliente[ contador1 ].panes, 
						cliente[ contador1 ].galletas, cliente[ contador1 ].pasteles  );
						printf( "Cuenta total: %d\n", cliente[ contador1 ].cuenta );
						fprintf( log, "%s Se consulto el pedido de %s\n", fecha, nombre);
					}
				}
			   break;
			case 6:
				printf( "Digite el nombre del pedido a eliminar: " );
				scanf( "%s", nombre );
				for( contador1 = 0; contador1 < numeroClientes; contador1++ )
				{
					if( strcmp( nombre, cliente[ contador1 ].nombre ) == 0 )
					{
						for( contador2 = contador1; contador2 < numeroClientes - 1; contador2++ )
						{
							cliente[ contador2 ] = cliente[ contador2 + 1 ];							
						}
						fprintf( log, "%s Se elimino %s\n", fecha, nombre );
					}
				}
				numeroClientes--;
			   break;
			case 7:
				printf( "Digite el nombre del pedido a editar: " );
				scanf( "%s", nombre );
				for( contador1 = 0; contador1 < numeroClientes; contador1++ )
				{
					if( strcmp( nombre, cliente[ contador1 ].nombre ) == 0 )
					{
						printf( "Querido usuario %s digite: 1. para añadir o 2 para eliminar: ", nombre );
						scanf( "%d", &mostrar );
						if( mostrar == 1 )
						{
							printf( "==================================\n" 
									"          1. Panes\n" 
									"          2. galletas\n" 
									"          3. pasteles\n"
									"          4. panes + galletas\n" 
									"          5. panes + galletas + pasteles\n"  
									"==================================\n" );							
							printf( "Digite cuantos productos va a adicionar: ");
							scanf( "%d", &productos );
							if( productos == 1 || productos == 4 || productos == 5 )
							{
								printf( "Cuantos panes va a adicionar: " );
								scanf( "%d", &producto );
								if( panes >= producto )
								{
									cliente[ contador1 ].panes += producto;
									cliente[ contador1 ].cuenta += ( producto * 100 );
									panes -= producto;
								}
								else
								{
									printf( "Panes insuficiente hay %d\n", panes );
								}
							}
							if( productos == 2 || productos == 4 || productos == 5 )
							{
								printf( "Cuantas galletas va a adicionar: " );
								scanf( "%d", &producto );
								if( galletas >= producto )
								{
									cliente[ contador1 ].galletas += producto;
									cliente[ contador1 ].cuenta += ( producto * 50 );
									galletas -= producto;
								}
								else
								{
									printf( "Galletas insuficiente hay %d\n", galletas );
								}								
							}
							if( productos == 3 || productos == 5 )
							{
								printf( "Cuantos pasteles va a adicionar: " );
								scanf( "%d", &producto );
								if( pasteles >= producto )
								{								
									cliente[ contador1 ].pasteles += producto;
									cliente[ contador1 ].cuenta += ( producto * 200 );
									pasteles -= producto;
								}	
								else
								{
									printf( "Pasteles insuficiente hay %d\n", pasteles );
								}					
							}
						}
						else if( mostrar == 2 )
						{
							printf( "==================================\n" 
									"          1. Panes\n" 
									"          2. galletas\n" 
									"          3. pasteles\n"
									"          4. panes + galletas\n" 
									"          5. panes + galletas + pasteles\n"  
									"==================================\n" );							
							printf( "Digite cuantos productos va a adicionar: ");
							scanf( "%d", &productos );
							if( productos == 1 || productos == 4 || productos == 5 )
							{
								printf( "Cuantos panes va a eliminar: " );
								scanf( "%d", &producto );
								if( panes >= producto )
								{								
									cliente[ contador1 ].panes += producto;
									cliente[ contador1 ].cuenta += ( producto * 100 );
									panes -= producto;
								}
								else
								{
									printf( "Panes insuficiente hay %d\n", panes );
								}								
							}
							if( productos == 2 || productos == 4 || productos == 5 )
							{
								printf( "Cuantas galletas va a eliminar: " );
								scanf( "%d", &producto );
								if( galletas >= producto )
								{								
									cliente[ contador1 ].galletas += producto;
									cliente[ contador1 ].cuenta += ( producto * 50 );
									galletas -= producto;
								}
								else
								{
									printf( "Galletas insuficiente hay %d\n", galletas );
								}
							}
							if( productos == 3 || productos == 5 )
							{
								printf( "Cuantos pasteles va a eliminar: " );
								scanf( "%d", &producto );
								if( pasteles >= producto )
								{									
									cliente[ contador1 ].pasteles += producto;
									cliente[ contador1 ].cuenta += ( producto * 200 );
									pasteles -= producto;
								}
								else
								{
									printf( "Panes insuficiente hay %d\n", panes );
								}								
							}							
						}
						printf( "Su nueva cuenta es %d\n", cliente[ contador1 ].cuenta );		
						fprintf( log, "%s Se modifico el pedido de %s, con una nueva cuenta de %d\n", fecha, nombre,
							     cliente[ contador1 ].cuenta );
					}
				}
			   break;
			case 8:
					printf( "==================================\n" 
							"          1. Pedidos\n" 
							"          2. Invetario\n" 
							"          3. Ingredientes\n" 
							"==================================\n" );			
					printf( "Que lista quiere: "); 
					scanf( "%d", &mostrar );
					if( mostrar == 1 )
					{
						printf( "NOMBRE         CUENTA                  PEDIDO\n" );
						printf( "==========  =============  =====================================\n" );
						for( contador1 = 0; contador1 < numeroClientes; contador1++ )
						{
							printf( "%-11s %-14d panes %d, galletas %d, pasteles %d\n", cliente[ contador1 ].nombre, 
							cliente[ contador1 ].cuenta, cliente[ contador1 ].panes, 
							cliente[ contador1 ].galletas, cliente[ contador1 ].pasteles );
						}
						fprintf( log, "%s Se listaron los pedidos\n", fecha);
					}
					else if( mostrar == 2 )
					{
						printf( "INVENTARIO\n" );
						printf( "=====================================\n" );
						printf( "panes %d\ngalletas %d\npasteles %d\n", panes, galletas, pasteles );
						printf( "=====================================\n" );
						fprintf( log, "%s Se listo el inventario\n", fecha);						
					}
					else if( mostrar == 3 )
					{
						printf( "INGREDIENTES\n" );
						printf( "=====================================\n" );
						printf( "harina %d\nhuevos %d\nleche %d\n", harina, huevos, leche );
						printf( "=====================================\n" );
						fprintf( log, "%s Se listaron los ingredientes\n", fecha);						
					}

			   break;
			case 9:
				for( contador1 = 0; contador1 < numeroClientes; contador1++ )
				{
					for( contador2 = 0, contador3 = 1; contador3 < numeroClientes; contador2++, contador3++ )
					{
						if( cliente[ contador2 ].cuenta > cliente[ contador3 ].cuenta )
						{
							temporal = cliente[ contador3 ];
							cliente[ contador3 ] = cliente[ contador2 ];
							cliente[ contador2 ] = temporal;
						}
					}
				}
				copiaSegura = fopen( "reporte.txt", "w" );
				fprintf( copiaSegura, "NOMBRE         CUENTA                  PEDIDO\n" );
				fprintf( copiaSegura, "==========  =============  =====================================\n" );
				for( contador1 = 0; contador1 < numeroClientes; contador1++ )
				{
						fprintf( copiaSegura, "%-11s %-14d panes %d, galletas %d, pasteles %d\n", cliente[ contador1 ].nombre, 
						cliente[ contador1 ].cuenta, cliente[ contador1 ].panes, 
						cliente[ contador1 ].galletas, cliente[ contador1 ].pasteles );
						sumaCuenta += cliente[ contador1 ].cuenta;
				}
				fprintf( copiaSegura, "INVENTARIO\n" );
				fprintf( copiaSegura, "=====================================\n" );
				fprintf( copiaSegura, "panes %d\ngalletas %d\npasteles %d\n", panes, galletas, pasteles );
				fprintf( copiaSegura, "=====================================\n" );						
				fprintf( copiaSegura, "INGREDIENTES\n" );
				fprintf( copiaSegura, "=====================================\n" );
				fprintf( copiaSegura, "harina %d\nhuevos %d\nleche %d\n", harina, huevos, leche );
				fprintf( copiaSegura, "=====================================\n" );
				fprintf( copiaSegura, "Total de cuenta %d\n", sumaCuenta );
				fclose( copiaSegura );
				system( "notepad reporte.txt" );
				sumaCuenta = 0;
				fprintf( log, "%s Se genero un reporte\n", fecha);						

			   break;
			case 10:
				printf( "Digite el nombre del pedido a vender: " );
				scanf( "%s", nombre );
				for( contador1 = 0; contador1 < numeroClientes; contador1++ )
				{
					if( strcmp( nombre, cliente[ contador1 ].nombre ) == 0 )
					{
						dinero += cliente[ contador1 ].cuenta;
						for( contador2 = contador1; contador2 < numeroClientes - 1; contador2++ )
						{
							cliente[ contador2 ] = cliente[ contador2 + 1 ];							
						}
						printf( "El saldo de la panaderia es: %d\n", dinero );
						fprintf( log, "%s Se vendio el pedido de %s\n", fecha, nombre );
					}
				}
				numeroClientes--;
			   break;
			case 11:
				printf( "=====================================\n"
						"               DESCUENTOS\n"					
						"            1. 10 porciento\n"
						"            2. 20 porciento\n"
						"            3. 30 porciento\n"
						"=====================================\n" );
				printf( "Que descuento realizara: " );
				scanf( "%d", &mostrar );			
				for( contador1 = 0; contador1 < numeroClientes; contador1++ )
				{											
					if( mostrar == 1 )
					{
						cliente[ contador1 ].cuenta *= 0.9;
					}
					else if( mostrar == 2 )
					{
						cliente[ contador1 ].cuenta *= 0.8;
					}
					else if( mostrar == 3 )
					{
						cliente[ contador1 ].cuenta *= 0.7;
					}					
				}
				fprintf( log, "%s Se realizo un descuento a todos \n", fecha );
			   break;
			case 12:
				srand( time( NULL ) );
				regalo = 0 + rand()%(numeroClientes-0+1);
				cliente[ regalo ].cuenta = 0;
				printf("Estimado cliente %s hemos decidido regalarte tu pedido\nTu cuenta queda en %d\n",
				       cliente[ regalo ].nombre, cliente[ regalo ].cuenta );
				fprintf( log, "%s Se le regalo el pedido a %s\n", fecha, cliente[ regalo ].nombre);
			   break;
			case 44:
				printf( "==================================\n" 
						"          1. Panes\n" 
						"          2. galletas\n" 
						"          3. pasteles\n" 
						"==================================\n" );	
				printf( "Que producto va a regalar: " );
				scanf( "%d", &mostrar );
				for( contador1 = 0; contador1 < numeroClientes; contador1++ )
				{					
					if( mostrar == 1 )
					{
						cliente[ contador1 ].panes += 5;
					}
					else if( mostrar == 2 )
					{
						cliente[ contador1 ].galletas += 5;
					}
					else if( mostrar == 3 )
					{
						cliente[ contador1 ].pasteles += 5;
					}
				}
				fprintf( log, "%s Se les regalo a todos los clientes 5 productos\n", fecha );
			   break;
			case 0:
				printf( "Hasta luego, vuelve pronto =D\n" );
				fprintf( log, "%s El programa termino\n", fecha );
			   break;
			default:
				printf( "Opcion mal digitada\n" );

		}
	} while(opcion != 0);
	copiaSegura = fopen( "copia.dat", "wb" );
	fwrite( &numeroClientes, sizeof( int ), 1, copiaSegura );
	fwrite( &harina, sizeof( int ), 1, copiaSegura );
	fwrite( &huevos, sizeof( int ), 1, copiaSegura );
	fwrite( &leche, sizeof( int ), 1, copiaSegura );
	fwrite( &panes, sizeof( int ), 1, copiaSegura );
	fwrite( &galletas, sizeof( int ), 1, copiaSegura );
	fwrite( &pasteles, sizeof( int ), 1, copiaSegura );
	fwrite( &dinero, sizeof( int ), 1, copiaSegura );
	fwrite( cliente, sizeof( cliente ), 1, copiaSegura );
	fclose( copiaSegura );
	return;
}