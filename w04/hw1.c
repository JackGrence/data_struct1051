#include <stdio.h>
#include <stdlib.h>
#define stack_size 10000

char mark[ 14 ][ 17 ];
const char map[14][17] = 
{
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
{1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1}, 
{1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1}, 
{1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1}, 
{1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1}, 
{1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1}, 
{1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1}, 
{1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1}, 
{1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
{1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1}, 
{1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1}, 
{1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1}, 
{1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1}, 
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

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
char find = 0;
void push( block a );
block pop( void );

void presult( void )
{
	int i, j;
	char res[14][17];
	for( i = 0; i < 14; i++ )
	{
		for( j = 0; j < 17; j++ )
		{
			res[i][j] = 1;	
		}
	}
	for( i = top; i >= 0; i-- )
	{
		res[stack[i].row][stack[i].col] = 0;
	}

	for( i = 0; i < 14; i++ )
	{
		for( j = 0; j < 17; j++ ) 
		{
			if( res[i][j] == 0 )
			{
				printf( "# " );
			}
			else printf( "%d ", res[i][j] );
		}
		printf( "\n" );
	}


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

int main( void )
{
	
	center.row = 1;
	center.col = 1;
	int i, j;
	for( i = 0, j = 0; i < 8; i++ )
	{
		if( j == 4 ) j++;
		nesw[ i ].row = j / 3 - center.row;
		nesw[ i ].col = j % 3 - center.col;
		//printf( "%d = %d %d\n", i, nesw[ i ].row, nesw[ i ].col );
		j++;
	}

	for( i = 0; i < 14; i++ )
	{
		for( j = 0; j < 17; j++ )
		{
			mark[i][j] = map[i][j];
		}
	}
	
	player.dir = 8;
	player.row = 1;
	player.col = 1;
	push( player );
	player.dir = 0;
	
	int next_row;
	int next_col;
	while( !( player.row == 1 && player.col == 1 && player.dir > 7 ) )
	{
		while( player.dir <= 7 )
		{
			next_row = player.row + nesw[ player.dir ].row;
			next_col = player.col + nesw[ player.dir ].col; 
			//printf( "%d\n", map[ next_row ][ next_col ] );
			//printf( "while next_row = %d+%d next_col = %d\n", player.row, nesw[ player.dir ].row, next_col );
			player.dir++;
			if( !map[ next_row ][ next_col ] && !mark[ next_row ][ next_col ] )
			{
				mark[ player.row ][ player.col ] = 1;
				push( player );//push current position and go next
				//printf( "push top=%d\n", top );
				player.dir = 0;
				player.row = next_row;
				player.col = next_col;
				//printf( "dir = %d prow = %d pcol = %d\nnrow=%d ncol=%d\n", player.dir, player.row, player.col, next_row, next_col );
				if( next_row == 12 && next_col == 15 )
				{
					player.row = next_row;
					player.col = next_col;
					push( player );
					find = 1;
					break;
				}

			}
			//pstack();
		}
		//pstack();
		if( find ) break;
		else player = pop();
	
	}
	if( !find )
	{
		printf( "not find\n" );
	}
	else
	{
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










