#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[50], b[50];
	scanf( "%s", a );
	scanf( "%s", b );

	char *c = strstr( a, b );
	*c = '\0';
	printf( "%s", a );
	return 0;
}
