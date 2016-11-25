#include <stdio.h>
#include <stdlib.h>

int visited[5], cycle;
int graph[5][5] =
/*
{
	{0,1,1,0,0},
	{1,0,0,1,1},
	{1,0,0,0,0},
	{0,1,0,0,0},
	{0,1,0,0,0}
};
*/
{
	{0,0,1,1,0},
	{0,0,0,1,1},
	{1,0,0,0,0},
	{1,1,0,0,0},
	{0,1,0,0,0}
};
void dfs( int v, int *a, int last );
int main( void )
{
	int i, j;

	int result[5][5];
	cycle = 0;
	for( i = 0; i < 5; i++ )
	{
		for( j = 0; j < 5; j++ ) visited[j] = 0;
		dfs(i, result[i], -1);
		printf( "\n" );
	}
	if( cycle ) printf( "have cycle\n" );
	else printf( "no cycle\n" );

	return 0;
}

void dfs( int v, int *a, int last )
{
	printf( "%d ", v );
	*a = v;
	visited[v] = 1;
	int i;
	for( i = 0; i < 5; i++ )
	{
		if( graph[v][i] && visited[i] && i != last )
		{
			cycle = 1;
		}
		if( graph[v][i] && visited[i] == 0 ) dfs(i, a+1, v );
	}
}

