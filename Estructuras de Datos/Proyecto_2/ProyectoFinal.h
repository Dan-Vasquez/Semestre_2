#ifndef LIKEDPROJECT
#define LIKEDPROJECT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Project Project;
typedef struct Node Node;

struct Node{
	int item;
	int set;
	Node * next;
};

struct Project{
 	Node * firstNode;
 	int n;
	void (*add) ( Project *, int, int);
	void (*delete) ( Project *, int );
	int (*get) ( Project *, int );
	void (*search) ( Project *, int );
	void (*display) ( Project * );
	void (*displaySet) ( Project *, int );
	int (*size) ( Project * );
	int (*empty) ( Project * );
	void (*sort_and_list) ( Project * );
 	int (*getRandom) ( Project * );
 	void (*clear) ( Project * );
 	void (*save) ( Project *, char * );
 	void (*load) ( Project *, char * );
};

void add( Project * x, int e, int s ){
	int i;
	Node * y = malloc( sizeof( Node ) );
	y->item = e;
	y->set = s;
	if( x->n == 0 ){
		y->next = x->firstNode;
		x->firstNode = y;
	}
	else{
		Node * p = x->firstNode;
		for( i = 0; i < x->n - 1; i++ )
			p = p->next;
		y->next = p->next;
		p->next = y;
	}
	x->n++;
	return;
}
void delete( Project * x, int index ){
   int i;
   if( x->n == 0 ){
    	fprintf( stderr, "Error: project is empty" );
    	return;
   }
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
int get( Project * x, int index ){
	int i;
	if( index < 0 || index >= x->n ){
	fprintf( stderr, "Error : invalid index\n" );
		return -1;
	}
	Node * y = x->firstNode;
	for( i = 0; i < index; i++ ){
		y = y->next;
		return y->item;
	}   
}
void search( Project * x, int e ){
	int i;
	Node * y = x->firstNode;
	for( i = 0; i < x->n; i++ ){
		if( y->item == e )
			printf( "Index: %d\nSet: %d\n", i, y->set );
		y = y->next;
	}
	return;   
}
void display( Project * x ){
	int i;
	printf( "Sets: " );
	Node * y = x->firstNode;
	for( i = 0; i < x->n; i++ ){
		printf( "[ %d / %d ]", y->item, y->set );
		y = y->next;
	}
	printf( "\n" );
	return;
}
void displaySet( Project * x, int s ){
	int i, cont = 0;
	Node * y = x->firstNode;
	printf( "Items of set_%d: ", s );
	for( i = 0; i < x->n; i++ ){
		if( y->set == s ){
			printf( "%d ", y->item );
			cont++;
		}
		y = y->next;
	}
	if( cont == 0 ){
		fprintf( stderr, "Error : invalid set\n" );
	}
	printf( "\n" );
	return;   
}
int size( Project * x ){
	return x->n;
}
int empty( Project * x ){
	return x->n == 0;
}
void sort_and_list( Project * x ){
   int i, j, temp, temp2, setTemp;
   for ( i = 0; i < x->n - 1; i++ )
   {
      Node * y = x->firstNode;
      Node * p = x->firstNode;
       for ( j = 0; j < x->n - 1; j++ )
      {
         p = p->next;
         if( y->set >= p->set )
         {
            temp = y->item;
            y->item = p->item;
            p->item = temp;
            temp = y->set;
            y->set = p->set;
            p->set = temp;            
         } 
         y = y->next;
      }
   }
   Node * y = x->firstNode;
   setTemp = y->set;
   printf( "Set_0: %d\n", setTemp );
	for( i = 0, j = 1; i < x->n; i++ ){
		if( y->set != setTemp ){
			setTemp = y->set;
			printf( "Set_%d: %d\n", j++, setTemp );
		}
		y = y->next;
	}
   return;
}
int getRandom( Project * x )
{
   srand( time( NULL ) );
   int i, index = rand() % x->n;
   Node * y = x->firstNode;
   for( i = 0; i < index; i++ )
      y = y->next;
   return y->item;  
}
void clear( Project * x ){
	while( !empty( x ) )
		delete( x, 0 );
	return;
}
void save( Project * x, char * fn ){
	int i = 0, temp[ x->n ], temp2[ x->n ];
	Node * y = x->firstNode;
	for( i = 0; i < x->n; i++ ){
		temp[ i ] = y->item;
		temp2[ i ] = y->set;
		y = y->next;
	}
	FILE * f = fopen( fn, "wb" );
	if( f ){
		fwrite( &x->n, sizeof( int ), 1, f );
		fwrite( temp, sizeof( temp ), 1, f );
		fwrite( temp2, sizeof( temp2 ), 1, f );
	}
	fclose( f );
	return;

}
void load( Project * x, char * fn ){
	int i, nn;
	clear( x );
	FILE * f = fopen( fn, "rb" );
	if( f ){
		fread( &nn, sizeof( int ), 1, f );
		int temp[ nn ], temp2[ nn ];
		fread( temp, sizeof( temp ), 1, f );
		fread( temp2, sizeof( temp2 ), 1, f );
	   for( i = 0; i < nn; i++ ){
	   	add( x, temp[ i ], temp2[ i ] );
		}		
	}
	fclose( f );
	return;	
}

Project createProject(){
	Project p;
	p.firstNode = NULL;
	p.n = 0;
	p.add = &add;
	p.delete = &delete;
	p.get = &get;
	p.search = &search;
	p.display = &display;
	p.displaySet = &displaySet;
	p.size = &size;
	p.empty = &empty;
	p.sort_and_list = &sort_and_list;
	p.getRandom = &getRandom;
	p.clear = &clear;
	p.save = &save;
	p.load = &load;
	return p;
}

#endif
