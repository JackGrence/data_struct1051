// 1.array time
// 2.graph  { nodes, edges }
//   0  1  2  3  4
// 0
// 1
// 2
// 3
// 4
#include <stdio.h>
#include <stdlib.h>
#define COL 5 
#define ROW 5

int main( void )
{
	int g[ROW][COL] = { { 0,1,0,1,1 },{ 1,0,1,0,0 },{ 0,1,0,1,0},{1,0,1,0,0},{1,0,0,0,0}};
	int c[ROW][COL];
	int *p;
	
	int i, j;
	for( i = 0; i < ROW * COL; i++)
	{
		c[i/COL][i%COL] = 0;
		for( j = 0; j < COL; j++)
		{
			p = &c[0][0] + i;
			*p = *p || ( g[i/COL][j] && g[j][i%COL] );
		}
	}
	for( i = 0; i < ROW; i++ )
	{
		for( j = 0; j < COL; j++ )
		{
			printf( "%d\t", c[i][j] );
		}
		printf( "\n" );
	}
	return 0;
}
