#include <stdio.h>
#include <stdlib.h>

int f( int a )
{
	if( a < 1 )
	{
		return 0;
	}
	else if( a <= 2 )
	{
		return 1;
	}
	else
	{
		return f( a - 1 ) + f( a - 2 );
	}
}

int main( void )
{
	int n;
	scanf( "%d", &n );
	printf( "%d\n", f( n ) );
	return 0;
}
