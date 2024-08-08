#ifndef ARRAYLIST
#define ARRAYLIST

#include <stdio.h>
#include <stdlib.h>
#define CAP 100

typedef struct List List;

struct List{
   int a[ CAP ], n;
   void (*add) ( List *, int, int );
   void (*delete) ( List *, int );
   int (*get) ( List *, int );
   int (*search) ( List *, int );
   void (*display) ( List * );
   int (*size) ( List * );
   int (*empty) ( List * );
   int (*getLast) ( List * );
   int (*sum) ( List * );
   int (*greatest) ( List * );
   void (*increaseValue) ( List *, int );
   void (*swap) ( List *, int, int );
   void (*reverse) ( List * );
   void (*concat) ( List *, List * );
   void (*sort) ( List * );
   void (*destroyEvens) ( List * );
   void (*magic) ( List *, List * );
};

void add( List * x, int index, int e ){
   int i;
   if( index < 0 || index > x->n ){
      fprintf( stderr, "Error : invalid index\n" );
      return;
   }
   if( x->n == CAP ){
      fprintf( stderr, "Error : list is full\n" );
      return;
   }
   for( i = x->n - 1; i >= index; i-- )
      x->a[ i + 1 ] = x->a[ i ];
   x->a[ index ] = e;
   x->n++;
   return;
}

void delete( List * x, int index ){
   int i;
   if( index < 0 || index >= x->n ){
      fprintf( stderr, "Error : invalid index\n" );
      return;
   }
   for( i = index; i < x->n - 1; i++ )
      x->a[ i ] = x->a[ i + 1 ];
   x->n--;
   return;
}

int get( List * x, int index ){
   if( index < 0 || index >= x->n ){
      fprintf( stderr, "Error : invalid index\n" );
      return 0;
   }
   return x->a[ index ];
}

int search( List * x, int e ){
   int i;
   for( i = 0; i < x->n; i++ )
      if( x->a[ i ] == e )
         return i;
   return -1;
}

void display( List * x ){
   int i;
   printf( "List: " );
   for( i = 0; i < x->n; i++ )
      printf( "%d ", x->a[ i ] );
   printf( "\n" );
   return;
}

int size( List * x ){
   return x->n;
}

int empty( List * x ){
   return x->n == 0;
}

int getLast( List * x )
{
   return x->a[ x->n - 1 ];
}

int sum( List * x )
{
   int i, suma = 0;

   for ( i = 0; i < x->n; i++ )
   {
      suma += x->a[ i ];
   }
   return suma;
}

int greatest( List * x )
{
   int i, datoMayor = x->a[ 0 ];

   for ( i = 1; i < x->n; i++ )
   {
      if( x->a[ i ] > datoMayor )
      {
         datoMayor = x->a[ i ];
      }
   }
   return datoMayor;
}

void increaseValue( List * x, int e )
{
   int i;

   for ( i = 0; i < x->n; i++ )
   {
      x->a[ i ] += e;
   }  
   return;
}

void swap( List * x, int index, int index2 )
{
   int temporal;

   if( (index < 0 || index >= x->n) || (index2 < 0 || index2 >= x->n) )
   {
      fprintf( stderr, "Error : invalid index\n" );
      return;
   }

   temporal = x->a[ index ];
   x->a[ index ] = x->a[ index2 ];
   x->a[ index2 ] = temporal;
   return;
}

void reverse( List * x )
{
   int i, posicionFinal, temporal;

   posicionFinal = x->n - 1;

   if( x->n % 2 == 0)
   {
      for ( i = 0; i < x->n / 2; i++ )
      {
         temporal = x->a[ i ];
         x->a[ i ] = x->a[ posicionFinal ];
         x->a[ posicionFinal-- ] = temporal;
      }
   }
   else
   {
      for ( i = 0; i < (x->n - 1) / 2; i++ )
      {
         temporal = x->a[ i ];
         x->a[ i ] = x->a[ posicionFinal ];
         x->a[ posicionFinal-- ] = temporal;
      }
   }

   return; 
}

void concat( List * x, List * y )
{
   while( !empty( y ) )
   {
      add( x, x->n, get( y, 0 ) );
      delete( y, 0 );
   }
   return;
}

void sort( List * x )
{
   int i, j, temporal;

   for ( i = 0; i < x->n ; i++ )
   {
       for ( j = 0; j < x->n - 1; j++ )
      {
          if( x->a[ j ] > x->a[ j + 1 ] )
         {
            temporal = x->a[ j ];
            x->a[ j ] = x->a[ j + 1 ];
            x->a[ j + 1 ] = temporal;
         } 
      }
   }
   return;
}

void destroyEvens( List * x )
{
   int i;

   for ( i = 0; i < x->n ; i++ )
   {
      if( x->a[ i ] % 2 == 0 )
      {
         delete( x, i );
         i--;
      }
   }  
   return;
}

void magic( List * x, List * y )
{
   int i, suma = 0, repeticion = 0;
   y->n = 0;
   for( i = 0; i < x->n; i++ )
   {
      suma += x->a[ i ];
      repeticion++;
      if( suma + x->a[ i + 1 ] > 100 && suma < 100 )
      {
         y->a[ y->n++ ] = repeticion;
         y->a[ y->n++ ] = suma;
         repeticion = suma = 0;
      }
      else if( i == x->n - 1 )
      {
         y->a[ y->n++ ] = repeticion;
         y->a[ y->n++ ] = suma;         
      }
   }
   return;
}

List createList( ){
   List l;
   l.n = 0;
   l.add = &add;
   l.delete = &delete;
   l.get = &get;
   l.search = &search;
   l.display = &display;
   l.size = &size;
   l.empty = &empty;
   l.getLast = &getLast;
   l.sum = &sum;
   l.greatest = &greatest;
   l.increaseValue = &increaseValue;
   l.swap = &swap;
   l.reverse = &reverse;
   l.concat = &concat;
   l.sort = &sort;
   l.destroyEvens = &destroyEvens;
   l.magic = &magic;
   return l;
}

#endif
