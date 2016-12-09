#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define HSIZE 10

typedef struct
{
	int dot1, dot2, cost;
} node;
int T[7][7]=
{
	{0,28,0,0,0,10,0},
	{28,0,16,0,0,0,14},
	{0,16,0,12,0,0,0},
	{0,0,12,0,22,0,18},
	{0,0,0,22,0,25,24},
	{10,0,0,0,25,0,0},
	{0,14,0,18,24,0,0}
};
int visited[7] = {0};
int kruskal[7][7] = {{0},{0}};
void pSort( void );
void pRest( int indx, char str[] );
node pop( node ary[] );
void swap( node *a, node *b );
void insert( node item );
node minHeap[HSIZE];
int latest = 0;
char cycle = 0;
void dfs( int v, int last );
int main( void )
{
	node item;
	int i, j;
	for( i = 0; i < 7; i++ ) //input heap
	{
		for( j = 0; j < 7; j++ )
		{
			if( i == j ) break;
			if( T[i][j] )
			{
				item.dot1 = i;
				item.dot2 = j;
				item.cost = T[i][j];
				insert(item);
			printf( "dot1:%d dot2:%d cost:%d\n", item.dot1, item.dot2, item.cost );
			}
		}
	}
	pRest(1,(char*)"");

	while( latest != 0 )
	{
		item = pop( minHeap );
		kruskal[item.dot1][item.dot2] = item.cost;
		kruskal[item.dot2][item.dot1] = item.cost;
		for( i = 0; i < 7; i++ ) visited[i] = 0;
		cycle = 0;
		dfs( item.dot1, -1 ); 
		if( item.cost == 25 )
		{
			printf( "dot1:%d dot2:%d cost:%d\n", item.dot1, item.dot2, item.cost );
			for( i = 0; i < 7; i++ )
			{
				for( j = 0; j < 7; j++ )
				{
					if( i == j ) break;
					if( kruskal[i][j] )	printf( "%d-----%d-----%d\n", i, kruskal[i][j], j );
				}
			}	
		}
		if( cycle )
		{
			kruskal[item.dot1][item.dot2] = 0;
			kruskal[item.dot2][item.dot1] = 0;
		}
		if( item.cost == 25 )
		{
			printf( "cycle:%d\n", cycle );
		}
		for( i = 0; i < 7; i++ ) visited[i] = 0;
		printf( "cost:%d\n", item.cost );
	}
	for( i = 0; i < 7; i++ )
	{
		for( j = 0; j < 7; j++ )
		{
			printf( "%d, ", kruskal[i][j] );
		}
		printf( "\n" );
	}
	for( i = 0; i < 7; i++ )
	{
		for( j = 0; j < 7; j++ )
		{
			if( i == j ) break;
			if( kruskal[i][j] )	printf( "%d-----%d-----%d\n", i, kruskal[i][j], j );
		}
	}
	return 0;
}

void dfs( int v, int last )
{
	//printf( "%d ", v );
	visited[v] = 1;
	int i;
	for( i = 0; i < 7; i++ )
	{
		if( kruskal[v][i] && visited[i] && i != last )
		{
			cycle = 1;
		}
		if( kruskal[v][i] && visited[i] == 0 )
		{
			dfs(i, v );
		}
	}
}

void pSort( void )
{
	int i, lat = latest;
	for( i = 1; i <= lat; i++ )
	{
		printf( "%d ", pop(minHeap).cost );
	}
	printf( "\n" );
}

void insert( node item )
{
	int index;
	if( latest >= HSIZE - 1 )
	{
		printf( "array is full\n" );
		return;
	}
	latest++;
	minHeap[ latest ] = item;
	index = latest;
	while( index != 1 )
	{
		if( minHeap[index].cost >= minHeap[ index / 2 ].cost ) break;
		swap( &minHeap[index], &minHeap[index/2] );
		index /= 2;
	}
}

void swap( node *a, node *b )
{
	node tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

node pop( node ary[] )
{
	node result;
	if( latest < 1 )
	{
		printf( "no any items\n" );
		return result;
	}
	result = ary[1];
	node tmp;
	tmp = ary[latest];
	latest--;
	int child = 2;
	int parent = 1;
	while( child <= latest )//bug
	{
		if( child < latest && ary[child].cost > ary[ child + 1 ].cost ) child++;
		if( ary[child].cost > tmp.cost ) break;
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
	printf( "%d\n", minHeap[indx].cost );
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
