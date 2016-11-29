#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void pSort( void );
void pRest( int indx, char str[] );
int pop( int ary[] );
void swap( int *a, int *b );
void insert( int item );
int minHeap[10];
int latest = 0;
int main( void )
{
	int defaultTree[] = {10, 20, 30, 40, 50, 55, 45, 35, 25, 15};
	int i;
	for( i = 0; i < 8; i++ ) insert( defaultTree[i] );
	pRest( 1, (char *) "" );
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
		pRest( 1, (char *) "" );
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

// ├　─　┼　┴　┬　┤　┌　┐　╞　═　╪　╡　│　▕
// 　└　┘　╭　╮　╰　╯

void pRest( int indx, char str[] )
{
	char s[100];
	if( latest == 0 ) return;
	printf( "%d\n", minHeap[indx] );
	if( indx*2 > latest ) return;
	if( indx*2+1 > latest ) printf( "%s└─", str );
	else printf( "%s├─", str );
	strcpy( s, str );
	strcat( s, "│ " );
	pRest( indx * 2, s );
	if( indx*2+1 > latest ) return;
	printf( "%s└─", str );
	strcpy( s, str );
	strcat( s, "  " );
	pRest( indx * 2 + 1, s );
}
