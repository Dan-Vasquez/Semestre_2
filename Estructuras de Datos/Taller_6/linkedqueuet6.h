#ifndef LINKEDQUEUE
#define LINKEDQUEUE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue Queue;
typedef struct Node Node;

struct Node{
   int item;
   Node * next; 
};

struct Queue{
   Node *front, *rear;
   void (*put) ( Queue *, int );
   void (*delete) ( Queue * );
   int (*getFront) ( Queue * );
   int (*getRear) ( Queue * );
   void (*display) ( Queue * );
   int (*empty) ( Queue * );
   int (*size) ( Queue * );
   int (*total) ( Queue * );
   void (*clear) ( Queue * );
   void (*putFront) ( Queue *, int );
   void (*putAfter) ( Queue *, int, int );
   void (*replaceFront) ( Queue *, int );
   int (*getRandom) ( Queue * );
   void (*putRandom) ( Queue *, int, int );
   void (*reverse) ( Queue * );
   void (*shuffle) ( Queue * );
   void (*save) ( Queue *, char * );
   void (*load) ( Queue *, char * );
};

int empty( Queue * x ){
   return x->front == NULL;
}

void put( Queue * x, int e ){
   Node * y = malloc( sizeof( Node ) );
   y->item = e;
   y->next = NULL;
   if( empty( x ) )
      x->front = y;
   else
      x->rear->next = y;
   x->rear = y;
   return;
}

void delete( Queue * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      return;
   }
   Node * y = x->front;
   x->front = x->front->next;
   free( y );
   return;
}

int getFront( Queue * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      exit( 1 );
   }
   return x->front->item;
}

int getRear( Queue * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      exit( 1 );
   }
   return x->rear->item;
}

void display( Queue * x ){
   Node * y = x->front;
   printf( "Queue: [front] " );
   while( y ){
      printf( "%d ", y->item );
      y = y->next;
   }
   printf( "[rear]\n" );
   return;
}

int size( Queue * x )
{
   int tamanio = 0;
   Node * y = x->front;
   while( y )
   {
      y = y->next;
      tamanio++;
   }
   return tamanio;
}

int total ( Queue * x )
{
   int suma = 0;
   Node * y = x->front;
   while( y )
   {
      suma += y->item;
      y = y->next;
   }
   return suma;
}

void clear ( Queue * x )
{
   x->front = x->rear = NULL;
   return;
}

void putFront ( Queue * x, int e )
{
   Node * y = malloc( sizeof( Node ) );
   y->item = e;
   y->next = x->front; 
   x->front = y;
   return;
}

void putAfter ( Queue * x, int p, int e )
{
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      exit( 1 );
   }
   int i;
   Node * z = malloc( sizeof( Node ) );
   Node * y = x->front;
   for( i = 1; i < p; i++)
   {
      y = y->next;
   }
   z->item = e;
   z->next = y->next;
   y->next = z;
   if( size( x ) == ++p)
   {
      x->rear = z;
   }  
   return;
}

void replaceFront ( Queue * x, int e )
{
   x->front->item = e;
   return;
}

int getRandom ( Queue * x )
{
   srand(time(NULL));
   int i, aleatorio = rand() % size(x);
   Node * y = x->front;
   for( i = 0; i < aleatorio; i++ )
   {
      y = y->next;
   } 
   return y->item;  
}

void putRandom ( Queue * x, int a, int b )
{
   if( a > b )
   {
      put( x, b + rand() % ( a - b + 1 ) );
   }
   else
   {
      put( x, a + rand() % ( b - a + 1 ) );
   }
   return;
}

void reverse ( Queue * x )
{
   int i, j, posicionFinal, temporal;
   Node * z = x->front;
   posicionFinal = size( x ) - 1;

   for ( i = 0; i < (size( x ) - 1) / 2; i++, posicionFinal-- )
    {
       Node * y = x->front;
       for( j = 0; j < posicionFinal; j++ )
       {
          y = y->next;
       }
      temporal = z->item;
      z->item = y->item;
      y->item = temporal;
      z = z->next;
   }    
   return;
}

void shuffle ( Queue * x )
{
   Node * y = x->front;
   Node * z = x->front;
   int temporal[ size( x ) ], i, posicion, cont = 0;
   for( i = 0; i < size( x ); i++ )
   {
      temporal[ i ] = y->item;
      y = y->next;
   }
   while( cont != size( x ) )
   {
      posicion = rand() % size( x );
      if( temporal[ posicion ] != -1 )
      {
         z->item = temporal[ posicion ];
         z = z->next;
         temporal[ posicion ] = -1;
         cont++;
      }
   }
   return;
}

void save ( Queue * x, char * fn )
{
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      exit( 1 );
   } 
   FILE * archivo;
   archivo = fopen( "fn", "wb" );
   fwrite( &x->front, sizeof( Node ), 1, archivo );
   fwrite( &x->rear, sizeof( Node ), 1, archivo );
   fclose( archivo ); 
   return;
}

void load ( Queue * x, char * fn )
{
   FILE * archivo;
   archivo = fopen( "fn", "rb" );
   fread( &x->front, sizeof( Node ), 1, archivo );
   fread( &x->rear, sizeof( Node ), 1, archivo );
   fclose( archivo );
   return;
}

Queue createQueue( ){
   Queue q;
   q.front = q.rear = NULL;
   q.put = &put;
   q.delete = &delete;
   q.getFront = &getFront;
   q.getRear = &getRear;
   q.display = &display;
   q.empty = &empty;
   q.size = &size;
   q.total = &total;
   q.clear = &clear;
   q.putFront = &putFront;
   q.putAfter = &putAfter;
   q.replaceFront = &replaceFront;
   q.getRandom = &getRandom;
   q.putRandom = &putRandom;
   q.reverse = &reverse;
   q.shuffle = &shuffle;
   q.save = &save;
   q.load = &load;
   return q;
} 

#endif