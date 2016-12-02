// 1. Topological Order
// 2. Bipartite Graph
#include <stdio.h>
#include <stdlib.h>
#define ASIZE 6

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
	int i, j, judge, exist;
	for( i = 0; i < ASIZE; i++ ) visited[i] = 0;
	exist = 1;
	while( exist )
	{
		exist = 0;
		for( i = 0; i < ASIZE; i++ )
		{
			judge = 0;
			for( j = 0; j < ASIZE; j++ )
			{
				if( graph[j][i] == 1 )
				{
					judge = 1;
					break;
				}
			}
			if( !judge )
			{
				printf( "%d ", i );
				for( j = 0; j < ASIZE; j++ ) graph[i][j] = 0;
				graph[i][i] = 1;
				exist = 1;
			}
		}
	}
	for( i = 0; i < ASIZE; i++ ) if( !graph[i][i] )
	{
		printf( "error" );
		break;
	}
	printf( "\n" );
	return 0;
}
