#include <stdio.h>
#include "arrayqueue.h"

int **pixel, size, i, j;

typedef struct Position Position;

struct Position{
   int row, col; 
};

void inputImage( ){
   printf( "Enter image size: " );
   scanf( "%d", &size );
   pixel = malloc( ( size + 2 ) * sizeof( int * ) );
   for( i = 0; i < size + 2; i++ )
      pixel[i] = malloc( ( size + 2 ) * sizeof( int ) );
   printf( "Enter the pixel array in row-major order\n" );
   for( i = 1; i <= size; i++ )
      for( j = 1; j <= size; j++ )
         scanf( "%d", &pixel[ i ][ j ] );
   return;
}

void labelComponents( ){
   int numOfNbrs = 4, id = 1, r, c;
   Position nbr, here, offset[ 4 ] = {
      { 0, 1 },   // right
      { 1, 0 },   // down
      { 0, -1 },  // left
      { -1, 0 }   // up
   };
   for( i = 0; i <= size + 1; i++ ){
      pixel[ 0 ][ i ] = pixel[ size + 1 ][ i ] = 0; 
      pixel[ i ][ 0 ] = pixel[ i ][ size + 1 ] = 0; 
   }
   Queue qx = createQueue();
   Queue qy = createQueue();
   for( r = 1; r <= size; r++ )
      for( c = 1; c <= size; c++ )
         if( pixel[ r ][ c ] == 1 ){
            pixel[ r ][ c ] = ++id;
            here = (Position) { r, c };
            while( 1 ){ 
               for( i = 0; i < numOfNbrs; i++ ){
                  nbr.row = here.row + offset[ i ].row; 
                  nbr.col = here.col + offset[ i ].col;
                  if( pixel[ nbr.row ][ nbr.col ] == 1 ){
                     pixel[ nbr.row ][ nbr.col ] = id;
                     qx.put( &qx, nbr.row );
                     qy.put( &qy, nbr.col );
                  }
               }
               if( qx.empty( &qx ) ) break;
               here.row = qx.getFront( &qx );
               here.col = qy.getFront( &qy );
               qx.delete( &qx );
               qy.delete( &qy );
            }
         }
   return;
}

void outputImage( ){
   printf( "\nThe labeled image is\n\n" );
   for( i = 1; i <= size; i++ ){
      for( j = 1; j <= size; j++ )
         printf( "%d ", pixel[ i ][ j ] );
      printf( "\n" );
   }
}

int main( ){
   inputImage( );
   labelComponents( );
   outputImage( );
   return 0;
}
