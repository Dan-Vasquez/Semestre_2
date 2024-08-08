#ifndef LINKEDSTACK
#define LINKEDSTACK

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;
typedef struct Node Node;

struct Node{
   int item;
   Node * next;
};

struct Stack{
   Node * top;
   void (*push) ( Stack *, int );
   void (*pop) ( Stack * );
   int (*peek) ( Stack * );
   void (*display) ( Stack * );
   int (*empty) ( Stack * );
};

void push( Stack * x, int e ){
   Node * y = malloc( sizeof( Node ) );
   y->item = e;
   y->next = x->top;
   x->top = y;      
   return;
}

void pop( Stack * x ){
   if( x->top == NULL ){
      fprintf( stderr, "Error: stack is empty\n" );
      return;
   }
   Node * y = x->top;
   x->top = x->top->next;
   free( y );
   return;
}

int peek( Stack * x ){
   if( x->top == NULL ){
      fprintf( stderr, "Error: stack is empty\n" );
      return;
   }
   return x->top->item;
}

void display( Stack * x ){
   Node * y = x->top;
   printf( "Stack: [top] " );
   while( y ){
      printf( "%d ", y->item );
      y = y->next;
   }
   printf( "[bottom]\n" );
   return;
}

int empty( Stack * x ){
   return x->top == NULL;
}

Stack createStack( ){
   Stack s;
   s.top = NULL;
   s.push = &push;
   s.pop = &pop;
   s.peek = &peek;
   s.display = &display;
   s.empty = &empty;
   return s;
}

#endif

