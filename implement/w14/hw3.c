// select sort
// insertion sort (link list)
// quick sort *Ranking
// 6 5 2 9 3
// input 3 output 2
// 		 6		  4
#include <stdio.h>
#include <stdlib.h>



int quickSortExtra( int ary[], int size, int key );
void quickSort( int ary[], int size );
void swap( int *a, int *b );
int main( void )
{
	int ary[10] = { 10, 20, 40, 30, 5, 100, 8, 90, 11, 111 };
	int item;
	//quickSort( ary, 10 );
	for( item = 0; item < 10; item++ ) printf( "%d, ", ary[item] );
	printf( "\ninput: " );
	while( scanf( "%d", &item ) != EOF )
	{
		item = quickSortExtra( ary, 10, item );
		printf( "output: %d\n", item );
		printf( "input: " );
	}
	return 0;
}

int quickSortExtra( int ary[], int size, int key )
{
	int i = 0, j = size - 1;
	if( size <= 1 ) return 1;
	for( i = 0, j = size - 1; j > i; )
	{
		if( ary[i] >= ary[0] && ary[j] < ary[0] ) swap( &ary[i], &ary[j] );
		if( ary[i] < ary[0] ) i++;
		if( ary[j] >= ary[0] ) j--;
	}
	if( ary[j] > ary[0] ) j--;
	swap( &ary[0], &ary[j] );
	if( key < ary[j] ) return quickSortExtra( &ary[0], j, key );
	if( key > ary[j] ) return j + 1 + quickSortExtra( &ary[j+1], size - j - 1, key );
	if( key == ary[j] ) return j + 1;
	return 0;
}

void quickSort( int ary[], int size )
{
	int i = 0, j = size - 1;
	if( size <= 1 ) return;
	for( i = 0, j = size - 1; j > i; )
	{
		if( ary[i] >= ary[0] && ary[j] < ary[0] ) swap( &ary[i], &ary[j] );
		if( ary[i] < ary[0] ) i++;
		if( ary[j] >= ary[0] ) j--;
	}
	if( ary[j] > ary[0] ) j--;
	swap( &ary[0], &ary[j] );
	quickSort( &ary[0], j );
	quickSort( &ary[j+1], size - j - 1 );
}

void swap( int *a, int *b )
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
