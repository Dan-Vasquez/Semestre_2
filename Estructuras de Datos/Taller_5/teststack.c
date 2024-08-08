#include <stdio.h>
//#include "arrayCopia.h"
#include "linkedCopia.h"

int main(){
   Stack maria = createStack( );
   maria.push( &maria, 100 );
   maria.push( &maria, 80 );
   maria.push( &maria, 15 );
   maria.push( &maria, 24 );
   maria.push( &maria, 135 );
   maria.display( &maria );
   maria.pop( &maria );
   maria.display( &maria );
   while( !maria.empty( &maria ) ){
      printf( "Deleting top element %d\n", maria.peek( &maria ) );
      maria.pop( &maria );
   }
   return 0;
}