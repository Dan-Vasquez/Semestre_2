#include <stdio.h>
#include "binarytree.h"

int main( ){
   Tree v = createTree( );
   Tree a = createTree( );
   Tree b = createTree( );
   Tree c = createTree( );
   Tree d = createTree( );
   Tree e = createTree( );
   Tree f = createTree( );
   Tree g = createTree( );
   Tree h = createTree( );
   a.makeTree( &a, 'O', &v, &v );
   b.makeTree( &b, 'V', &a, &v );
   a.makeTree( &a, 'L', &v, &v );
   c.makeTree( &c, 'L', &v, &v );
   d.makeTree( &d, 'S', &c, &a );
   a.makeTree( &a, 'L', &d, &b );
   b.makeTree( &b, 'S', &v, &v );
   c.makeTree( &c, 'A', &v, &v );
   d.makeTree( &d, 'A', &c, &b );
   b.makeTree( &b, 'N', &a, &d );
   a.makeTree( &a, 'I', &v, &v );
   c.makeTree( &c, 'R', &v, &v );
   d.makeTree( &d, 'E', &c, &a );
   a.makeTree( &a, 'U', &v, &v );
   c.makeTree( &c, 'M', &v, &v );
   e.makeTree( &e, 'R', &c, &a );
   f.makeTree( &f, 'E', &e, &d );
   a.makeTree( &a, 'Z', &v, &v );
   c.makeTree( &c, 'E', &v, &v );
   d.makeTree( &d, 'D', &c, &a );
   a.makeTree( &a, 'U', &v, &v );
   c.makeTree( &c, 'Q', &v, &v );
   e.makeTree( &e, 'N', &c, &a );
   a.makeTree( &a, 'I', &e, &d );
   c.makeTree( &c, 'A', &a, &f );
   a.makeTree( &a, 'D', &c, &b );
   printf( "Mesajes subliminales\n" );
   a.preorder( a.root );
   printf( "\n" );
   a.inorder( a.root );
   printf( "\n" );
   a.postorder( a.root );
   printf( "\n" );
   a.levelorder( a.root );
   printf( "\n" );
   printf( "empty = %d\n", a.empty( a.root ) );
   printf( "size = %d\n", a.size( a.root ) );
   printf( "height = %d\n", a.height( a.root ) );
   return 0;
}
