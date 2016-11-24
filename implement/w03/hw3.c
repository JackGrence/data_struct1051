#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void )
{	
	int n, x, number[100];
	printf( "n = " );
	scanf( "%d", &n );
	int i;
	printf( "f(x) = " );
	for( i = 0; i < n; i++ )
	{
		scanf( "%d", &number[i] );
	}
	printf( "x = " );
	scanf( "%d", &x );
	int sum = 0;
	for( i = 0; i < n; i++ )
	{
		sum = sum * x + number[i];
	}
	printf( "f(%d) = ", x );
	for( i = 0; i < n - 1; i++ )
	{
		printf( "%dx^%d + ", number[i], n-1-i );
	}
	printf( "%d = %d\n", number[n-1], sum );
	return 0;
}
