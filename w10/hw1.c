#include <stdio.h>
#include <stdlib.h>

void pSort( void );
int pop( int ary[] );
void swap( int *a, int *b );
void pResult(void);
void insert( int item );
int minHeap[10];
int latest = 0;
int main( void )
{
	int defaultTree[] = {10, 20, 30, 40, 50, 55, 45, 35, 25, 15};
	int i;
	for( i = 0; i < 8; i++ ) insert( defaultTree[i] );
	pResult();
	int a;
	printf( "(1)insert (2)pop (3)sort >> " );
	while( scanf( "%d", &a ) != EOF )
	{
		if( a == 1 )
		{
			scanf( "%d", &a );
			insert(a);
		}
		else if( a == 2 )
		{
			pop(minHeap);
		}
		else
		{
			printf( "_____sort_____\n");
			pSort();
		}
		printf( "_____tree_____\n");
		pResult();
		printf( "(1)insert (2)pop (3)sort >> " );
	}
	return 0;
}

void pSort( void )
{
	int i, lat = latest;
	for( i = 1; i <= lat; i++ )
	{
		printf( "%d ", pop(minHeap) );
	}
	printf( "\n" );
}

void insert( int item )
{
	int index;
	if( latest >= 9 )
	{
		printf( "array is full\n" );
		return;
	}
	latest++;
	minHeap[ latest ] = item;
	index = latest;
	while( index != 1 )
	{
		if( minHeap[index] >= minHeap[ index / 2 ] ) break;
		swap( &minHeap[index], &minHeap[index/2] );
		index /= 2;
	}
}

void swap( int *a, int *b )
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int pop( int ary[] )
{
	int result;
	if( latest < 1 )
	{
		printf( "no any items\n" );
		return 0;
	}
	result = ary[1];
	int tmp;
	tmp = ary[latest];
	latest--;
	int child = 2;
	int parent = 1;
	while( child <= latest )//bug
	{
		if( child < latest && ary[child] > ary[ child + 1 ] ) child++;
		if( ary[child] > tmp ) break;
		ary[parent] = ary[child];
		parent = child;
		child *= 2;
	}
	ary[parent] = tmp;
	return result;
}

void pResult(void)
{
	int tmp = 1, count = 0, i;
	for( i = 1; i <= latest; i++ )
	{
		printf( "%2d  ", minHeap[i] );
		count++;
		if( tmp == count )
		{
			printf( "\n" );
			count = 0;
			tmp *= 2;
		}
	}
	printf( "\n" );
}
