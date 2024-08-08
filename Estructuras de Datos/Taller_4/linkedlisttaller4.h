#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdio.h>
#include <stdlib.h>

typedef struct List List;
typedef struct Node Node;

struct Node{
   int item;
   Node * next;
};

struct List{
   Node * firstNode;
   int n;
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
   Node * y = malloc( sizeof( Node ) );
   y->item = e;
   if( index == 0 ){
      y->next = x->firstNode;
      x->firstNode = y;
   }
   else{
      Node * p = x->firstNode;
      for( i = 0; i < index - 1; i++ )
         p = p->next;
      y->next = p->next;
      p->next = y;
   }
   x->n++;       
   return;
}

void delete( List * x, int index ){
   int i;
   if( index < 0 || index >= x->n ){
      fprintf( stderr, "Error : invalid index\n" );
      return;
   }
   Node * y;
   if( index == 0 ){
      y = x->firstNode;
      x->firstNode = x->firstNode->next;
   }
   else{
      Node * p = x->firstNode;
      for( i = 0; i < index - 1; i++ )
         p = p->next;
      y = p->next;
      p->next = p->next->next;
   }
   free( y );
   x->n--;
   return;
}

int get( List * x, int index ){
   int i;
   if( index < 0 || index >= x->n ){
      fprintf( stderr, "Error : invalid index\n" );
      return 0;
   }
   Node * p = x->firstNode;
   for( i = 0; i < index; i++ )
      p = p->next;
   return p->item;
}

int search( List * x, int e ){
   int i;
   Node * p = x->firstNode;
   for( i = 0; i < x->n; i++ ){
      if( p->item == e )
         return i;
      p = p->next;
   }
   return -1;
}

void display( List * x ){
   int i;
   printf( "List: " );
   Node * y = x->firstNode;
   for( i = 0; i < x->n; i++ ){
      printf( "%d ", y->item );
      y = y->next;
   }
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
   int i;
   Node * y = x->firstNode;
   for( i = 0; i < x->n; i++ )
   {
      if( i == x->n - 1)
      {
         return y->item;
      }
      y = y->next;
   }
}

int sum( List * x )
{
   int i, suma = 0;
   Node * y = x->firstNode;
   for ( i = 0; i < x->n; i++ )
   {
      suma += y->item;
      y = y->next;
   }
   return suma;
}

int greatest( List * x )
{
   Node * y = x->firstNode;
   int i, datoMayor = y->item;
   y = y->next;

   for ( i = 1; i < x->n; i++ )
   {
      if( y->item > datoMayor )
      {
         datoMayor = y->item;
      }
      y = y->next;
   }
   return datoMayor;
}

void increaseValue( List * x, int e )
{
   int i;
   Node * y = x->firstNode;
   for ( i = 0; i < x->n; i++ )
   {
      y->item += e;
      y = y->next;
   }  
   return;
}

void swap( List * x, int index, int index2 )
{
   int i, j, temporal;
   Node * y = x->firstNode;
   Node * p = x->firstNode;
   if( (index < 0 || index >= x->n) || (index2 < 0 || index2 >= x->n) )
   {
      fprintf( stderr, "Error : invalid index\n" );
      return;
   }
   for( i = 0; i < index; i++ )
   {
      y = y->next;
   }
      for( i = 0; i < index2; i++ )
   {
      p = p->next;
   }
   temporal = y->item;
   y->item = p->item;
   p->item = temporal;
   return;
}

void reverse( List * x )
{
   int i, j, posicionFinal, temporal;

   Node * p = x->firstNode;

   posicionFinal = x->n - 1;

   for ( i = 0; i < ( x->n - 1) / 2 ; i++, posicionFinal-- )
    {
       Node * y = x->firstNode;
       for( j = 0; j < posicionFinal; j++ )
       {
          y = y->next;
       }
      temporal = p->item;
      p->item = y->item;
      y->item = temporal;
      p = p->next;
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

   for ( i = 0; i < x->n - 1; i++ )
   {
      Node * y = x->firstNode;
      Node * p = x->firstNode;
       for ( j = 0; j < x->n - 1; j++ )
      {
         p = p->next;
         if( y->item > p->item )
         {
            temporal = y->item;
            y->item = p->item;
            p->item = temporal;
         } 
         y = y->next;
      }
   }
   return;
}

void destroyEvens( List * x )
{
   int i;

   Node * y = x->firstNode;

   for ( i = 0; i < x->n; i++ )
   {
      if( y->item % 2 == 0 )
      {
         y = y->next;
         delete( x, i );
         i--;
      }
      else
      {
         y = y->next;
      }
   }

   return;
}

void magic( List * x, List * y )
{
   int i, j = 0, suma = 0, repeticion = 0;
   y->n = 0;
   Node * p = x->firstNode;
   for( i = 0; i < x->n - 1; i++ )
   {
      suma += p->item;
      repeticion++;
      p = p->next;
      if( suma + p->item > 100 && suma < 100 )
      {
         add( y, j++, repeticion );
         add( y, j++, suma );
         repeticion = suma = 0;
      }
      else if( i == x->n - 2 )
      {
         suma += p->item;
         repeticion++;
         add( y, j++, repeticion );
         add( y, j++, suma );         
      }
   }
   return;
}

List createList( ){
   List l;
   l.firstNode = NULL;
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
