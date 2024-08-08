#include <stdio.h>
//#include "arrayqueuet6.h"
#include "linkedqueuet6.h"

int main( )
{
 srand( time( NULL ) );
 Queue q = createQueue();
 Queue p = createQueue();
 q.put( &q, 1 );
 q.put( &q, 2 );
 q.put( &q, 3 );
 q.put( &q, 4 );
 q.put( &q, 5 );
 q.put( &q, 6 );
 q.put( &q, 7 );
 q.display( &q );
 printf( ">Inserting 1000 after 4th element ...\n" );
 q.putAfter( &q, 4, 1000 );
 q.display( &q );
 printf( ">The rear element is %d\n", q.getRear( &q ) );
 printf( "There are %d elements in the queue\n", q.size( &q ) );
 printf( "Total is %d\n", q.total( &q ) );
 printf( "A random element is %d\n", q.getRandom( &q ) );
 printf( ">Replacing front with 987 ...\n" );
 q.replaceFront( &q, 987 );
 q.display( &q );
 printf( ">Saving the queue in the file colita.txt\n" );
 q.save( &q, "colita.txt" );
 printf( ">Clearing all elements ...\n" );
 q.clear( &q );
 q.display( &q );
 q.putRandom( &q, 0, 100 );
 q.putRandom( &q, 0, 100 );
 q.putRandom( &q, 0, 100 );
 q.putRandom( &q, 0, 100 );
 q.putRandom( &q, 0, 100 );
 q.putRandom( &q, 0, 100 );
 q.putRandom( &q, 0, 100 );
 q.display( &q );
 printf( ">Reversing the queue ...\n" );
 q.reverse( &q );
 q.display( &q );
 printf( ">Shuffling the queue ...\n" );
 q.shuffle( &q );
 q.display( &q );
 if( !q.empty( &q ) ){
 printf( ">The front element is %d\n", q.getFront( &q ) );
 printf( ">The rear element is %d\n", q.getRear( &q ) );
 }
 p.load( &p, "colita.txt" );
 p.display( &p );
 p.putFront( &p, 777 );
 p.display( &p );
 return 0;
}
