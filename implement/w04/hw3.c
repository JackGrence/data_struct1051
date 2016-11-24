#include <stdio.h>
#include <stdlib.h>

void Toh( int n, char *src, char *dest, char *tmp )
{
	if( n == 1 )
	{
		printf( "%s to %s\n", src, dest );
	}
	else
	{
		Toh( n - 1, src, tmp, dest );
		//src to dest
		printf( "%s to %s\n", src, dest );
		Toh( n - 1, tmp, dest, src );
	
	}
}

int main( void )
{
	char a[] = "A", b[] = "B", c[] = "C";
	int t;
	scanf( "%d", &t );
	Toh( t, a, c, b );
	return 0;
}
