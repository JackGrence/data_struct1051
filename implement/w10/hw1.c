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
#define COL 3
#define ROW 3

int main( void )
{
	int a[3][3] = { { 1, 2, 3 },{ -1, 0, 4},{ 5, -2, 6} };
	int b[3][3] = { { 1, 0, 1 },{ -1, -1, 2 },{ 3, 1, 0 } };
	int c[ROW][COL];
	
	int i, j;
	for( i = 0; i < ROW * COL; i++)
	{
		c[i/COL][i%COL] = 0;
		for( j = 0; j < COL; j++)
		{
			c[i/COL][i%COL] += a[i/COL][j] * b[j][i%COL];
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
