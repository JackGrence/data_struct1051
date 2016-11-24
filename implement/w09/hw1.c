#include <stdio.h>
#include <stdlib.h>
int findRoot ( int forest[], int index );
void printForest( int forest[], int len );

int main( void )
{
	int forest[12];
	int i;
	for( i = 0; i < 12; i++ )
	{
		forest[i] = -1;
	}
	int a, b;
	printf( "(a b):" );
	while( scanf( "%d %d", &a, &b ) != EOF )
	{
		a = findRoot( forest, a );
		b = findRoot( forest, b );
		forest[a] += forest[b];
		forest[b] = a;
		printForest( forest, 12 );
		printf( "(a b):" );
	}
	return 0;
}

int findRoot ( int forest[], int index )
{
	if( forest[index] < 0 ) return index;
	else return findRoot( forest, forest[index] );
}

void printForest( int forest[], int len )
{
	int i, j, tmp;
	for( i = 0; i < len; i++ )// find root
	{
		if( forest[i] < 0 )
		{
			printf( "{ %d", i );
			for( j = 0; j < len; j++ )// find leaf
			{
				if( forest[j] >= 0 && findRoot( forest, j ) == i )
				{
					tmp = j;
					printf( ", %d", tmp );
					tmp = forest[tmp];
				}
			}
			printf( " }\n" );
		}
	}
	printf( "\n" );
}
