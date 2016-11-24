#include <stdio.h>
#include <stdlib.h>

int recu( int a )
{
	if( a == 1 )
	{
		return 1;
	}
	else
	{
		return a * recu( a - 1 );
	}
}

int main( void )
{
	int n;
	scanf( "%d", &n );
	printf( "%d\n", recu( n ) );
	return 0;
}
