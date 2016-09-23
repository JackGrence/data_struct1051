#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrstr( char *str1, char *str2 )
{
	int i = 0;
	int j = 0;
	char *result;
	while( str1[i] != '\0' )
	{
		if( str2[j] == '\0' )
		{
			
			break;
		}
		if( str1[i] == str2[j] )
		{
			if( j == 0 )
			{
				result = &str1[i];
			}
			j++;
		}
		else
		{
			j = 0;
			if( str1[i] == str2[0] )
			{
				j = 1;
			}
		}
		i++;
	}
	if( j == 0 ) return 0;
	else return result;
}

int main( int argc, char *argv[] )
{
	char text[100];
	char pat[100];
	char *jud;
	printf( "text:" );
	scanf( "%s", text );
	printf( "pat:" );
	scanf( "%s", pat );
	jud = mystrstr( text, pat );
	if( jud == 0 )
	{
		printf( "NO\n" );
	}
	else 
	{
		printf( "YES\n" );
	}
	return 0;
}
