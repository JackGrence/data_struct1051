// 1.binary search
// 2.binary search tree ( insert )
#include <stdio.h>
#include <stdlib.h>
void pary( int ary[] );
int main( void )
{
	int ary[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200 };
	int start = -1, end = 20, mid = ( start + end ) / 2;
	int key, find;
	pary( ary );

	printf( "find:" );
	while( scanf( "%d", &key ) != EOF )
	{
		start = -1;
		end = 20;
		mid = ( start + end ) / 2;
		find = 0;
		while( end - start > 1 )
		{
			if( ary[mid] == key )
			{
				find = 1;
				break;
			}
			start = ary[mid] < key ? mid : start;
			end = ary[mid] > key ? mid : end;
			mid = ( start + end ) / 2;
			//printf("%d\n", mid );
		}
		if( find )
		{
			printf( "find key in %d, value = %d\n", mid, ary[mid] );
		}
		else
		{
			printf( "not find\n" );
		}
		printf( "find:" );
	}
	return 0;
}

void pary( int ary[] )
{
	int i;
	for( i = 0; i < 20; i++ )
	{
		printf( "%d ", ary[i] );
	}
	printf( "\n" );
}
