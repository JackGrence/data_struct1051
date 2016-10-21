#include <stdio.h>
#include <stdlib.h>
#define stack_size 10000
#define MAPSIZE 8

char mark[ MAPSIZE + 4 ][ MAPSIZE + 4 ];
char map[ MAPSIZE + 4 ][ MAPSIZE + 4 ];  

typedef struct
{
	int row;
	int col;
} pos;

typedef struct
{
	int dir;
	int row;
	int col;
} block;

pos nesw[ 8 ], center;
block stack[ stack_size ], player;
int top = -1;
int find = 0;
void push( block a );
block pop( void );
void presult( void );
void pstack( void );

const char knight_col[ 8 ] = { -1, 1, -2, 2, -2, 2, -1, 1 };
const char knight_row[ 8 ] = { -2, -2, -1, -1, 1, 1, 2, 2 };
void p_ary( char m[MAPSIZE+4][MAPSIZE+4] );
char mapchk( int row, int col );
int main( void )
{
	//-----------------------------------------------------------------init
	center.row = 0;
	center.col = 0;

	int i, j;
	for( i = 0; i < 8; i++ )
	{
		nesw[i].row = knight_row[i] - center.row;
		nesw[i].col = knight_col[i] - center.col;
	}

	for( i = 0; i < MAPSIZE + 4; i++ )
	{
		for( j = 0; j < MAPSIZE + 4; j++ )
		{
			if( i >= 2 && j >= 2 && i <= MAPSIZE+1 && j <= MAPSIZE+1 )
			{
				map[i][j] = 0;
			}
			else
			{
				map[i][j] = 1;
			}
		}
	}
	p_ary( map );
	player.dir = 0;
	player.row = 2;
	player.col = 2;
	//---------------------------------------------------------------END INIT
	int next_row;
	int next_col;
	
	while( 1 )
	{
		while( player.dir <= 7 )
		{
			next_row = player.row + nesw[ player.dir ].row;
			next_col = player.col + nesw[ player.dir ].col; 
			player.dir++; 
			if( !map[ next_row ][ next_col ] && !mark[ next_row ][ next_col ] )
			{
				mark[ player.row ][ player.col ] = 1;
				push( player );//push current position and go next
				player.dir = 0;
				player.row = next_row;
				player.col = next_col;
			}
			//pstack();
		}
		//pstack();
		if( mapchk( player.row, player.col ) )
		{
			push( player );
			find++;
			printf("find: %d\ndir: %d\n", find, stack[0].dir );
			break;			
			
		}
		else 
		{
			mark[ player.row ][ player.col ] = 0;
			if( top > -1 ) player = pop();
			else break;
		}
	
	}
	if( !find )
	{
		printf( "not find\n" );
	}
	else
	{
		//pstack();
		presult();
	}

	return 0;
}

void push( block a )
{
	stack[ ++top ] = a;
}

block pop( void )
{	
	//printf( "pop player.dir=%d prow=%d pcol=%d top=%d\n", stack[top-1].dir, stack[top+1].row, stack[top].col, top );
	return stack[ top-- ];
}

void pstack( void )
{
	int i = top;
	for( ; i >= 0; i-- )
	{
		player = stack[i];
		printf( "%d, %d\n", player.row, player.col );
	}

}
void presult( void )
{
	int i, j, k;
	char m[MAPSIZE][MAPSIZE];
	for( i = 0; i < MAPSIZE; i++ )
	{
		for( j = 0; j < MAPSIZE; j++ )
		{
			m[i][j] = 0;
		}
	}
	for( k = 0; k <= top; k++ )
	{
		m[ stack[k].row - 2 ][ stack[k].col - 2 ] = k+1;
		for( i = 0; i < MAPSIZE; i++ )
		{
			for( j = 0; j < MAPSIZE; j++ )
			{
				printf( "%2d ", m[i][j] );
			}
			printf( "\n" );
		}
		printf("pause");
		fgetc( stdin );
	}

}


void p_ary( char m[MAPSIZE+4][MAPSIZE+4] )
{
	int i, j;
	for( i = 0; i < MAPSIZE+4; i++ )
	{
		for( j = 0; j < MAPSIZE+4; j++ )
		{
			printf( "%d ", m[i][j] | mark[i][j] );
		}
		printf( "\n" );
	}
	for( i = 0; i < 8; i++)
	{
	//	printf( "%d, %d\n", nesw[i].col, nesw[i].row ); 
	}
}

char mapchk( int row, int col )
{
	int i, j;
	mark[row][col] = 1;
	char chk = 1;
	for( i = 0; i < MAPSIZE + 4; i++ )
	{
		for( j = 0; j < MAPSIZE + 4; j++ )
		{
			if( map[i][j] == 0 && mark[i][j] == 0 )
			{
				chk = 0;
				break;
			}
		}
	}
	mark[row][col] = 0;
	return chk;
}


