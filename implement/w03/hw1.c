#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void )
{
	char *p;
	char a[100], b[100];
	printf( "str a = " );
	scanf( "%s", a );
	printf( "str b = " );
	scanf( "%s", b );
	p = strstr( a, b );
	int len = strlen( b );
	char *p2 = p + len;
	strcpy( p, p2 );
	printf( "%s\n", a );
	return 0;
}
