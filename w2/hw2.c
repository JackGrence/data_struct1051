#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] )
{
	char text[100];
	char pat[100];
	char *jud;
	printf( "text:" );
	scanf( "%s", text );
	printf( "pat:" );
	scanf( "%s", pat );
	jud = strstr( text, pat );
	*jud = '\0';
	printf( "result:%s\n", text );
	return 0;
}
