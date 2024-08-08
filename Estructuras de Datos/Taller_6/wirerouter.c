#include <stdio.h>
#include "arrayqueue.h"

int **grid, size, pathLength, i, j;

typedef struct Position Position;

struct Position{
   int row, col; 
};

Position start, finish, path[100];

void inputData( ){
   printf( "Enter grid size: " );
   scanf( "%d", &size );
   printf( "Enter the start position\n" );
   scanf( "%d %d", &start.row, &start.col );
   printf( "Enter the finish position\n" );
   scanf( "%d %d", &finish.row, &finish.col );
   grid = malloc( ( size + 2 ) * sizeof( int * ) );
   for( i = 0; i < size + 2; i++ )
      grid[i] = malloc( ( size + 2 ) * sizeof( int ) );
   printf( "Enter the grid array in row-major order\n" );
   for( i = 1; i <= size; i++ )
      for( j = 1; j <= size; j++ )
         scanf( "%d", &grid[ i ][ j ] );
   return;
}

int findPath( ){
   int numOfNbrs = 4;
   Position here, nbr, offset[ 4 ] = {
      { 0, 1 },   // right
      { 1, 0 },   // down
      { 0, -1 },  // left
      { -1, 0 }   // up
   };
   for( i = 0; i <= size + 1; i++ ){
      grid[ 0 ][ i ] = grid[ size + 1 ][ i ] = 1; 
      grid[ i ][ 0 ] = grid[ i ][ size + 1 ] = 1; 
   }
   if( ( start.row == finish.row ) && ( start.col == finish.col ) )
      return 1;
   here = (Position) { start.row, start.col };
   grid[ start.row ][ start.col ] = 2; 
   Queue qx = createQueue();
   Queue qy = createQueue();
   while( 1 ){
      for( i = 0; i < numOfNbrs; i++ ){ 
         nbr.row = here.row + offset[ i ].row;
         nbr.col = here.col + offset[ i ].col;
         if( grid[ nbr.row ][ nbr.col ] == 0 ){
            grid[ nbr.row ][ nbr.col ] = grid[ here.row ][ here.col ] + 1;
            if( ( nbr.row == finish.row ) && ( nbr.col == finish.col ) )
               break;
            qx.put( &qx, nbr.row );
            qy.put( &qy, nbr.col );
         }
      }
      if( ( nbr.row == finish.row ) && ( nbr.col == finish.col ) )
         break;
      if( qx.empty( &qx ) ) return 0;
      here.row = qx.getFront( &qx );
      here.col = qy.getFront( &qy );
      qx.delete( &qx );
      qy.delete( &qy );
   }
   pathLength = grid[ finish.row ][ finish.col ] - 2;
   here = finish;
   for( j = pathLength - 1; j >= 0; j-- ){
      path[ j ] = here;
      for( i = 0; i < numOfNbrs; i++ ){
         nbr.row = here.row + offset[ i ].row;
         nbr.col = here.col + offset[ i ].col;
         if( grid[ nbr.row ][ nbr.col ] == j + 2 ) break;
      }
      here = (Position) { nbr.row, nbr.col };
   }
   return 1;
}

void outputPath( ){
   printf( "The wire path is\n" );
   for( i = 0; i < pathLength; i++ )
      printf( "%d %d\n", path[ i ].row, path[ i ].col );
   return;
}

int main( ){
   inputData( );
   if( findPath( ) ) outputPath( );
   else printf( "There is no wire path" );
   return 0;
}
