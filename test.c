#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *str = "teststs";
	char *pat = "st";
	char *res;
	res = strstr( str, pat );
	printf( "%s\n", res );
	return 0;
}
