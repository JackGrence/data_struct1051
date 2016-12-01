#include <stdio.h>
#include <stdlib.h>
#define ARYSIZE 10
int visited[ARYSIZE];
int graph[ARYSIZE][ARYSIZE];
void dfs( int v );
int main( void )
{
	int i, j, count = 0, c1, c2;
	printf( "input:\n" );
	while( scanf( "%d", &c1 ) != EOF )
	{
		count = 0;
		for( i = 0; i < ARYSIZE; i++ ) for( j = 0; j < ARYSIZE; j++ ) graph[i][j] = 0;
		while( c1 >= 0 )
		{
			do scanf( "%d", &c2 );
			while( c2 < 0 );
			graph[c1][c2] = 1;
			graph[c2][c1] = 1;
			scanf( "%d", &c1 );
		}
		for( i = 0; i < ARYSIZE; i++ ) visited[i] = 0;
		printf( "output:\n" );
		for( i = 0; i < ARYSIZE; i++ )
		{
			if( !visited[i] )
			{
				dfs(i);
				printf( "\n" );
				count++;
			}
		}
		printf( "have %d class\n", count );
		printf( "input:\n" );
	}
	return 0;
}

void dfs( int v )
{
	printf( "%d ", v );
	visited[v] = 1;
	int i;
	for( i = 0; i < ARYSIZE; i++ )
	{
		if( graph[v][i] && visited[i] == 0 ) dfs(i);
	}
}

