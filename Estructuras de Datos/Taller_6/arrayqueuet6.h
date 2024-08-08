#ifndef ARRAYQUEUE
#define ARRAYQUEUE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CAP 100

typedef struct Queue Queue;

struct Queue{
   int a[ CAP ];
   int front, rear, n;
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

void put( Queue * x, int e ){
   if( x->n == CAP ){
      fprintf( stderr, "Error: Queue is full\n" );
      return;
   }
   x->rear = ( x->rear + 1 ) % CAP;
   x->a[ x->rear ] = e;
   x->n++;
   return;
}

int empty( Queue * x ){
   return !x->n;
}

void delete( Queue * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      return;
   }
   x->front = ( x->front + 1 ) % CAP;
   x->n--;
   return;
}

int getFront( Queue * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      exit( 1 );
   }
   return x->a[ ( x->front + 1 ) % CAP ];
}

int getRear( Queue * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      exit( 1 );
   }
   return x->a[ x->rear ];
}

void display( Queue * x ){
   int i; 
   printf( "Queue: [front] " );
   for( i = 1; i <= x->n; i++ )
      printf( "%d ", x->a[ ( x->front + i ) % CAP ] );
   printf( "[rear]\n" );
   return;
}

int size( Queue * x )
{
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      exit( 1 );
   }   
   return x->n;
}

int total ( Queue * x )
{
   int i, suma = 0; 
   for( i = 1; i <= x->n; i++ )
      suma += x->a[ ( x->front + i ) % CAP ]; 
   return suma;
}

void clear ( Queue * x )
{
   int i, repeticiones = x->n;
   for( i = 0; i < repeticiones; i++)
   {
      delete( x );
   }
   return;
}

void putFront ( Queue * x, int e )
{  
   int i;
   put( x, x->a[ x->rear ] );
   for( i = 1; i < x->n; i++ )
   {
      x->a[ x->rear - i % CAP ] = x->a[ x->rear - (i + 1) % CAP ];
   }
   x->a[ x->front + 1 % CAP ] = e; 
   return;
}

void putAfter ( Queue * x, int p, int e )
{
   int i;
   put( x, x->a[ x->rear ] );
   for( i = 1; i < p; i++ )
   {
      x->a[ x->rear - i % CAP ] = x->a[ x->rear - (i + 1) % CAP ];
   }
   x->a[ x->front + ++p % CAP ] = e;
   return;  
}

void replaceFront ( Queue * x, int e )
{
   x->a[ x->front + 1 % CAP ] = e;
   return;
}

int getRandom ( Queue * x )
{
   srand(time(NULL));
   return x->a[ 1+rand()%(x->n-1+1) ];
}

void putRandom ( Queue * x, int a, int b )
{
   if( a > b )
   {
      put( x, b+rand()%(a-b+1) ); 
   }
   else
   {
      put( x, a+rand()%(b-a+1) );
   }
   return;
}

void reverse ( Queue * x )
{
   int i, temporal;
   for( i = 1; i <= x->n / 2; i++ )
   {
      temporal = x->a[ x->front + i % CAP ];
      x->a[ x->front + i % CAP ] = x->a[ x->rear - (i - 1) % CAP ];
      x->a[ x->rear - (i - 1) % CAP ] = temporal;
   }
   return;     
}

void shuffle ( Queue * x )
{
   int temporal[ x->n ], i, cont = 0, posicion, ubicacion = x->n;
   for( i = 1; i <= x->n; i++ )
   {
      temporal[ i - 1 ] = x->a[ (x->front + i) % CAP ];
   }
   clear( x );
   while( cont != ubicacion )
   {  
      posicion = rand() % ubicacion;
      if( temporal[ posicion ] != -1 )
      {
         put( x, temporal[ posicion ] );
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
   FILE *archivo;
   archivo = fopen( fn, "wb" );
   fwrite( &x->n, sizeof( int ), 1, archivo );
   fwrite( &x->rear, sizeof( int ), 1, archivo );
   fwrite( &x->front, sizeof( int ), 1, archivo );
   fwrite( x->a, sizeof( x->a ), 1, archivo );
   fclose( archivo );
   return;   
}

void load ( Queue * x, char * fn )
{
   FILE *archivo;
   archivo = fopen( fn, "rb" );
   fread( &x->n, sizeof( int ), 1, archivo );
   fread( &x->rear, sizeof( int ), 1, archivo );
   fread( &x->front, sizeof( int ), 1, archivo );
   fread( x->a, sizeof( x->a ), 1, archivo );
   fclose( archivo );
   return;
}

Queue createQueue( ){
   Queue q;
   q.front = q.rear = q.n = 0;
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
