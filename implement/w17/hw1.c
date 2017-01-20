#include <stdio.h>
#include <stdlib.h>
#define ARYSIZE 50

int count( int map[ARYSIZE][ARYSIZE], int i, int j );
void scan( int map[ARYSIZE][ARYSIZE] );
void presult( int map[ARYSIZE][ARYSIZE] );
void p( int m[] )
{
	printf( "infunction:%p\n", m );
}
int main( void )
{
	int map[ARYSIZE][ARYSIZE];
	int i, j;
	for( i = 0; i < ARYSIZE; i++ )
		for( j = 0; j < ARYSIZE; j++ )
			map[i][j] = 0;
	map[1][2] = 1;
	map[2][3] = 1;
	map[3][1] = 1;
	map[3][2] = 1;
	map[3][3] = 1;
	map[20][30] = 1;
	map[19][30] = 1;
	map[20][31] = 1;
	map[20][29] = 1;
	map[21][31] = 1;
	map[1][2] = 1;
	map[2][2] = 1;
	map[3][2] = 1;
	int m[10];
	printf( "main:%p\n", m );
	p(m);
	while( 1 )
	{
		scan(map);
		presult(map);
		fgetc(stdin);
	}
	return 0;
}

void presult( int map[ARYSIZE][ARYSIZE] )
{
	int i, j;
	for( i = 0; i < ARYSIZE; i++ )
	{
		for( j = 0; j < ARYSIZE; j++ )
		{
			if( map[i][j] ) printf( "* " );
			else printf( "  " );
		}
		printf( "\n" );
	}
}


void scan( int map[ARYSIZE][ARYSIZE] )
{
	int i, j;
	int cp[ARYSIZE][ARYSIZE];
	for( i = 0; i < ARYSIZE; i++ )
		for( j = 0; j < ARYSIZE; j++ )
			cp[i][j] = map[i][j];
	for( i = 1; i < ARYSIZE - 1; i++ )
	{
		for( j = 1; j < ARYSIZE - 1; j++ )
		{
			if( cp[i][j] )
			{
				if(	count(cp,i,j) != 2 && count(cp,i,j) != 3 ) map[i][j] = 0;
				else map[i][j] = 1;
			}
			else
			{
				if( count(cp,i,j) != 3 ) map[i][j] = 0;
				else map[i][j] = 1;
			}
		}
	}
}

int count( int map[ARYSIZE][ARYSIZE], int i, int j )
{
	int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int sum = 0;
	int index;
	for( index = 0; index < 8; index++)
	{
		if( map[ i+row[index] ][ j+col[index] ] ) sum++;
	}
	return sum;
}
