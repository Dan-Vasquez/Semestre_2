#ifndef ARRAYSTACK
#define ARRAYSTACK

#include <stdio.h>
#include <stdlib.h>
#define CAP 100

typedef struct Stack Stack;

struct Stack{
   int a[ CAP ];
   int top;
   void (*push) ( Stack *, int );
   void (*pop) ( Stack * );
   int (*peek) ( Stack * );
   void (*display) ( Stack * );
   int (*empty) ( Stack * );
};

void push( Stack * x, int e ){
   if( x->top == CAP - 1 ){
      fprintf( stderr, "Error: stack is full\n" );
      return;
   }
   x->a[ ++x->top ] = e;
   return;
}

void pop( Stack * x ){
   if( x->top == -1 ){
      fprintf( stderr, "Error: stack is empty\n" );
      return;
   }
   x->top--;
   return;
}

int peek( Stack * x ){
   if( x->top == -1 ){
      fprintf( stderr, "Error: stack is empty\n" );
      return;
   }
   return x->a[ x->top ];
}

void display( Stack * x ){
   int i;
   printf( "Stack: [top] " );
   for( i = x->top; i >= 0; i-- )
      printf( "%d ", x->a[ i ] );
   printf( "[bottom]\n" );
   return;
}

int empty( Stack * x ){
   return x->top == -1;
}

Stack createStack( ){
   Stack s;
   s.top = -1;
   s.push = &push;
   s.pop = &pop;
   s.peek = &peek;
   s.display = &display;
   s.empty = &empty;
   return s;
}

#endif