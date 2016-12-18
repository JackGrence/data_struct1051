// select sort
// insertion sort (link list)
// quick sort *Ranking
#include <stdio.h>
#include <stdlib.h>

void swap( int *a, int *b );
void selectSort( int ary[], int size );
int main( void )
{
	int ary[10] = { 10, 20, 40, 30, 5, 100, 8, 90, 11, 111 };
	selectSort( ary, 10 );
	int i;
	for( i = 0; i < 10; i++ ) printf( "%d\n", ary[i] );
	return 0;
}

void selectSort( int ary[], int size )
{
	int i, j, min;
	for( i = 0; i < size; i++ )
	{
		min = i;
		for( j = i; j < size; j++ )
		{
			min = ary[j] < ary[min] ? j : min;
		}
		swap( &ary[i], &ary[min] );
	}
}

void swap( int *a, int *b )
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
