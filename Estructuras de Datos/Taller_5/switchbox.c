#include <stdio.h>
#include "arraystack.h"

void checkBox( int * net, int n ){
   int i;
   Stack s = createStack( );
   for( i = 0; i < n; i++ )
      if( !s.empty( &s ) )
         if( net[ i ] == net[ s.peek( &s ) ] )
            s.pop( &s );
         else s.push( &s, i );
      else s.push( &s, i );
   if( s.empty( &s ) ){
      printf( "Switch box is routable\n" );
      return;
   }
   printf( "Switch box is not routable\n" );
   return;
}

int main( ){
   int i, n, * net;   
   printf( "Type number of pins in switch box\n" );
   scanf( "%d", &n );
   net = ( int * ) malloc( sizeof( int ) * n );
   printf( "Type net numbers for pins 1 through %d\n", n );
   for( i = 0; i < n; i++ )
      scanf( "%d", &net[ i ] );
   checkBox( net, n );
   return 0;
}
