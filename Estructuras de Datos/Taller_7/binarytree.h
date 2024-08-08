#ifndef BINARYTREE
#define BINARYTREE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode TreeNode;
typedef struct Tree Tree;

struct TreeNode{
   int item;
   TreeNode * left;
   TreeNode * right;
};

struct Tree{
   TreeNode * root;
   void (*makeTree) ( Tree *, int, Tree *, Tree * );
   void (*preorder) ( TreeNode * ); 
   void (*inorder) ( TreeNode * ); 
   void (*postorder) ( TreeNode * ); 
   void (*levelorder) ( TreeNode * );
   int (*empty) ( TreeNode * );
   int (*size) ( TreeNode * ); 
   int (*height) ( TreeNode * );
   int (*suma) ( TreeNode * );
   int (*isFull) ( TreeNode * );
   int (*isComplete) ( TreeNode *, int, int );
   void (*mirror) ( TreeNode * ); 
};

void makeTree( Tree * x, int e, Tree * l, Tree * r ){
   x->root = malloc( sizeof( TreeNode ) );
   x->root->item = e;
   x->root->left = l->root;
   x->root->right = r->root;
   l->root = r->root = NULL;
   return;
}

void preorder( TreeNode * p ){
   if( p ){
      printf( "%c ", p->item );
      preorder( p->left );
      preorder( p->right );
   }
}

void inorder( TreeNode * p ){
   if( p ){
      inorder( p->left );
      printf( "%c ", p->item );
      inorder( p->right );
   }
}

void postorder( TreeNode * p ){
   if( p ){
      postorder( p->left );
      postorder( p->right );
      printf( "%c ", p->item );
   }
}

void givenLevel( TreeNode * p, int level ){
   if( !p )
      return;
   if( level == 1 )
      printf( "%c ", p->item );
   else if( level > 1 ){
      givenLevel( p->left, level - 1 );
      givenLevel( p->right, level - 1 );
   }
}

int height( TreeNode * p ){
   int hl, hr;
   if( p ){
      hl = height( p->left );
      hr = height( p->right );
      if( hl > hr ) return ++hl;
      else return ++hr;
   }
   else
      return 0;
}

void levelorder( TreeNode * p ){
   int h = height( p );
   int i;
   for( i = 1; i <= h; i++)
      givenLevel( p, i );
}

int empty( TreeNode * p ){
   return p == NULL;
}
 
int size( TreeNode * p ){
   if( p )
      return 1 + size( p->left ) + size( p->right );
   else
      return 0;
}

int suma( TreeNode * p )
{  
   if( p )
      return p->item + suma( p->left ) + suma( p->right );
   else
      return 0;
}

int isFull( TreeNode * p )
{
   if( p )
      if( size( p ) == pow(2, height( p )) - 1 )
         return 1;
      else
         return 0;
   else
      return 0;
}

int isComplete( TreeNode * p, int level, int flag )
{
   int comprobar;
   if( level == 2 )
   {
      if( flag == 1)
      {
         if( ( !p->left && !p->right ) || ( p->left && !p->right ) )
            return 1;
         else
            return 0;
      }
      else if( flag == 2 )
      {
         if( ( !p->left && !p->right ) )
            return 1;
         else
            return 0;         
      }
      else
      {
         if( ( p->left && p->right ) )
            return 1;
         else if( ( p->left && !p->right ) )
            return 2;
         else
            return 0;
      }

   }
   else if( level > 2 )
   {
      comprobar = isComplete( p->left, level - 1, 0 );
      if( comprobar == 1 )
         isComplete( p->right, level - 1, 1 );
      else if( comprobar == 2 )
         isComplete( p->right, level - 1, 2 );
      else
         return 0; 
   }
}

void mirror( TreeNode * p )
{
   if( p )
   {
      TreeNode * temp = p->left;
      p->left = p->right;
      p->right = temp;
      mirror( p->left );
      mirror( p->right );
   }
}

Tree createTree( ){
   Tree t;
   t.root = NULL;
   t.makeTree = &makeTree;
   t.preorder = &preorder;
   t.inorder = &inorder;
   t.postorder = &postorder;
   t.levelorder = &levelorder;
   t.empty = &empty;
   t.size = &size;
   t.height = &height;
   t.suma = &suma;
   t.isFull = &isFull;
   t.isComplete = &isComplete;
   t.mirror = &mirror;
   return t;
}

#endif
