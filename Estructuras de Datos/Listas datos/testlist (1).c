#include <stdio.h>
#include "arraylist.h"

int main(){
   List maria = createList( );
   maria.add( &maria, 0, 100 );
   maria.add( &maria, 1, 80 );
   maria.add( &maria, 2, 15 );
   maria.add( &maria, 3, 24 );
   maria.add( &maria, 4, 135 );
   maria.display( &maria );
   maria.delete( &maria, 2 );
   maria.display( &maria );
   printf( "La lista tiene %d elementos\n", maria.size( &maria ) );
   printf( "El segundo elemento es %d\n", maria.get( &maria, 1 ) );
   printf( "El numero 24 tiene posicion %d\n", maria.search( &maria, 24 ) );
   return 0;
}
