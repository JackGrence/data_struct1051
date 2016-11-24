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
	latest++;
	minHeap[ latest ] = item;
	index = latest;
	while( index != 1 )
	{
		if( minHeap[index] >= minHeap[ index / 2 ] ) break;
		else swap( &minHeap[index], &minHeap[index/2] );
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
	ary[1] = ary[latest];
	latest--;
	int index = 2;
	int tmp = 1;
	while( index <= latest )//bug
	{
		if( index + 1 > latest ) tmp = index;
		else tmp =  if( ary[index] > ary[index/2] && ary[index+1] > ary[index/2] ) break;
		else
		{
			
		}
		else 
		{
			tmp = ary[index*2] < ary[index*2+1] ? index*2 <= latest ? index*2 : tmp : index*2+1 <= latest ? index*2+1 : tmp;
			swap( &ary[tmp], &ary[index] );
		}
		index = tmp;
	}
	swap( &ary[tmp], &ary[1] );
	return result;
	
}

void pResult(void)
{
	int tmp = 1, count = 0, i;
	for( i = 1; i <= latest; i++ )
	{
		printf( "%d ", minHeap[i] );
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
