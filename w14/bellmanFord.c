#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define E 214748364
#define ARYSIZE 7

typedef struct node
{
	int data;
	struct node *next;
} path;
path *shortest[ARYSIZE];
int graph[7][7] =
{
	{E,6,5,5,E,E,E},
	{E,E,E,E,-1,E,E},
	{E,-2,E,E,1,E,E},
	{E,E,-2,E,E,-1,E},
	{E,E,E,E,E,E,3},
	{E,E,E,E,E,E,3},
	{E,E,E,E,E,E,E}
};
void bellmanFord( int ary[ARYSIZE][ARYSIZE], int size, int start );
void pList( path *head );
void cpNodes( path **head1, path *head2 );
void freeNodes( path *head );
void addI( path **head, int item );
int main( void )
{
	int dist[ARYSIZE][ARYSIZE];
	int i, j;

	//path *t1, *t2, *t3;
	//t1 = NULL;
	//addI( &t1, 1 );
	//addI( &t1, 2 );
	//addI( &t1, 5 );
	//cpNodes( &t2, t1 );
	//for( t3 = t2; t3 != NULL; t3 = t3->next ) printf( "%d\n", t3->data );

	bellmanFord( dist, ARYSIZE, 0 );
	for( i = 1; i < ARYSIZE; i++ )
	{
		for( j = 0; j < ARYSIZE; j++ )
		{
			if( dist[i][j] == E ) printf( "E\t" );
			else printf( "%d\t", dist[i][j] );
		}
		printf( "\n" );
	}
	for( i = 1; i < ARYSIZE; i++ )
	{
		printf( "%d -> %d:\t", 0, i );
		pList( shortest[i] );
		freeNodes( shortest[i] );
	}
	return 0;
}

void pList( path *head )
{
	path *cur;
	for( cur = head; cur != NULL; cur = cur->next )
	{
		printf( "%d ", cur->data );
	}
	printf( "\n" );
}

void bellmanFord( int ary[ARYSIZE][ARYSIZE], int size, int start )
{
	int i, j, k;
	for( i = 0; i < size; i++ ) shortest[i] = NULL;
	for( i = 0; i < size; i++ )
	{
		ary[1][i] = graph[start][i];
		if( graph[start][i] != E )
		{
			addI( &shortest[i], start );
			addI( &shortest[i], i );
		}
	}
	ary[1][start] = 0;
	for( i = 2; i < size; i++ ) // setp
	{
		for( j = 0; j < size; j++ ) // each node
		{
			//if( j == start ) continue;
			//*( ary + i * size + j ) = *( ary + (i-1) * size + j );
			ary[i][j] = ary[i-1][j];
			for( k = 0; k < size; k++ ) // each can arrived node
			{
				if( graph[k][j] == E ) continue;
				if( ary[i][j] > ary[i-1][k] + graph[k][j] )
				{
					freeNodes( shortest[j] );
					shortest[j] = NULL;
					cpNodes( &shortest[j], shortest[k] );
					addI( &shortest[j], j );
					ary[i][j] = ary[i-1][k] + graph[k][j];
				}
			}
		}
	}
}

void addI( path **head, int item )
{
	path *newItem = (path *) malloc( sizeof(path) );
	newItem->data = item;
	newItem->next = NULL;
	path *i;
	if( *head == NULL )
	{
		*head = newItem;
		return;
	}
	for( i = *head; i->next != NULL; i = i->next );
	i->next = newItem;
}

void freeNodes( path *head )
{
	path *i;
	for( i = head; i != NULL; i = head )
	{
		head = i->next;
		free(i);
	}
}

void cpNodes( path **head1, path *head2 )
{
	path *cur, *copy;
	path *tmp;
	tmp = (path *) malloc( sizeof(path) );
	*tmp = *head2;
	*head1 = tmp;
	for( cur = head2->next, copy = *head1; cur != NULL; cur = cur->next, copy = copy->next )
	{
		tmp = (path *) malloc( sizeof( path ) );
		*tmp = *cur;
		copy->next = tmp;
	}
}
