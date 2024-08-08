#include <stdio.h>
#include <string.h>
#include "arraystack.h"

void printMatchedPairs( char* expr ){
   int i;
   Stack s = createStack( );
   int n = strlen( expr );
   for( i = 0; i < n; i++ )
      if( expr[ i ] == '(' )
         s.push( &s, i );
      else if( expr[ i ] == ')' )
         if( !s.empty( &s ) ){
             printf( "%d %d\n", s.peek( &s ), i );
             s.pop( &s );
         }
         else{
            printf( "No match for right parenthesis at %d\n", i );
         }
   while( !s.empty( &s ) ){
      printf( "No match for left parenthesis at %d\n", s.peek( &s ) );
      s.pop( &s );
   }
}

int main( ){
   char x[256];
   printf( "Type an expression \n" );
   gets( x );
   printf( "The pairs of matching parentheses in %s are:\n", x );
   printMatchedPairs( x );
   return 0;
}
