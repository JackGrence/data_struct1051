// 1. Topological Order
// 2. Bipartite Graph
#include <stdio.h>
#include <stdlib.h>
#define ASIZE 6

void dfs( int v, int c );
int class = 1;
int error = 0;
int graph[ASIZE][ASIZE] =
{
	{0,0,0,1,0,0},
	{0,0,1,0,1,0},
	{0,1,0,0,0,0},
	{1,0,0,0,1,0},
	{0,1,0,1,0,1},
	{0,0,0,0,1,0}
};
int visited[ASIZE];
int main( void )
{
	int i, j;
	for( i = 0; i < ASIZE; i++ ) visited[i] = 0;
	dfs(0, 1);
	if( error ) printf( "error\n" );
	else
	{
		for( i = 1; i <= 2; i++ )
		{
			for( j = 0; j < ASIZE; j++ )
			{
				if( visited[j] == i ) printf( "%d ", j );
			}
			printf( "\n" );
		}
	}
	return 0;
}

void dfs( int v, int c )
{
	int i;
	visited[v] = c;
	c = c == 1 ? 2 : 1;
	for( i = 0; i < ASIZE; i++ )
	{
		if( graph[v][i] && !visited[i] ) dfs( i, c );
		if( graph[v][i] && visited[i] )
		{
			if( visited[i] == visited[v] )
			{
				error = 1;
				break;
			}
		}
	}
}
