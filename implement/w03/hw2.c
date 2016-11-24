#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void )
{
	char *p, *p2;
	char a[100], b[100], c[100], temp[100];
	printf( "str a = " );
	scanf( "%s", a );
	printf( "str b = " );
	scanf( "%s", b );
	printf( "str c = " );
	scanf( "%s", c );
	p = strstr( a, b );
	int len = strlen( b );
	p2 = p + len;
	strcpy( temp, p2 );
	strcpy( p, c );
	strcat( p, temp );
	printf( "%s\n", a );
	
	return 0;
}
