#include <stdio.h>
#include "ProyectoFinal.h"

int main(){
	Project datos = createProject();
	datos.add( &datos, 10, 1 );
	datos.add( &datos, 2, 2 );
	datos.add( &datos, 5, 1 );
	datos.add( &datos, 7, 1 );
	datos.add( &datos, 10, 2 );
	datos.add( &datos, 6, 3 );
	datos.add( &datos, 3, 2 );
	datos.display( &datos );
	datos.sort_and_list( &datos );
	datos.display( &datos );
	datos.displaySet( &datos, 1 );
	datos.displaySet( &datos, 2 );
	datos.displaySet( &datos, 3 );
	printf("0. Hay datos, 1. No: %d\n", datos.empty( &datos ) );
	printf("Hay un total de %d datos\n", datos.size( &datos ) );
	datos.search( &datos, 10 );
	printf("El dato en la posicion 1 es: %d\n", datos.get( &datos, 1 ) );
	datos.delete( &datos, 1 );
	datos.display( &datos );
	printf("Hay un total de %d datos\n", datos.size( &datos ) );
	datos.search( &datos, 10 );
	printf("Un dato optenido al azar es: %d\n", datos.getRandom( &datos ) );
	datos.save( &datos, "copia.txt" );
	datos.clear( &datos );
	datos.display( &datos );
	datos.load( &datos, "copia.txt" );
	datos.display( &datos );
	datos.add( &datos, 6, 3 );
	datos.add( &datos, 3, 2 );
	datos.display( &datos );
	return 0;
}