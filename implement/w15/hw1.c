#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *names[100] = {
	"Jacob",
	"Mason",
	"William",
	"Jayden",
	"Noah",
	"Michael",
	"Ethan",
	"Alexander",
	"Aiden",
	"Daniel",
	"Anthony",
	"Matthew",
	"Elijah",
	"Joshua",
	"Liam",
	"Andrew",
	"James",
	"David",
	"Benjamin",
	"Logan",
	"Christopher",
	"Joseph",
	"Jackson",
	"Gabriel",
	"Ryan",
	"Samuel",
	"John",
	"Nathan",
	"Lucas",
	"Christian",
	"Jonathan",
	"Caleb",
	"Dylan",
	"Landon",
	"Isaac",
	"Gavin",
	"Brayden",
	"Tyler",
	"Luke",
	"Evan",
	"Carter",
	"Nicholas",
	"Isaiah",
	"Owen",
	"Jack",
	"Jordan",
	"Brandon",
	"Wyatt",
	"Julian",
	"Aaron",
	"Sophia",
	"Isabella",
	"Emma",
	"Olivia",
	"Ava",
	"Emily",
	"Abigail",
	"Madison",
	"Mia",
	"Chloe",
	"Elizabeth",
	"Ella",
	"Addison",
	"Natalie",
	"Lily",
	"Grace",
	"Samantha",
	"Avery",
	"Sofia",
	"Aubrey",
	"Brooklyn",
	"Lillian",
	"Victoria",
	"Evelyn",
	"Hannah",
	"Alexis",
	"Charlotte",
	"Zoey",
	"Leah",
	"Amelia",
	"Zoe",
	"Hailey",
	"Layla",
	"Gabriella",
	"Nevaeh",
	"Kaylee",
	"Alyssa",
	"Anna",
	"Sarah",
	"Allison",
	"Savannah",
	"Ashley",
	"Audrey",
	"Taylor",
	"Brianna",
	"Aaliyah",
	"Riley",
	"Camila",
	"Khloe",
	"Claire"
};
double linear( int b, int n );
double quadratic( int b, int n );
int getNum( char *s );
int main( void )
{
	int i;
	int b[] = { 101, 151, 199, 499, 1001 };
	/*for( i = 0; i < 100; i++ )
	{
		if( getNum( "Olivia" ) % 1001 == getNum(names[i]) % 1001 )
		{
			printf( "%s\n", names[i] );
		}
		if( getNum( names[i] ) % 1001 == (getNum("Khloe") + 1) % 1001 ) printf( "%s\n", names[i] );
	}
	*/
	printf( "XXX\t\t" );

	for( i = 0; i < 5; i++ ) printf( "%d\t\t", b[i] );
	printf( "\n" );

	printf( "linear\t\t" );
	for( i = 0; i < 5; i++ )
	{
		printf( "%lf\t", linear( b[i], 100 ) );
	}

	printf( "\n" );

	printf( "quadratic\t" );
	for( i = 0; i < 5; i++ )
	{
		printf( "%lf\t", quadratic( b[i], 100 ) );
	}
	
	/*linear( b[2], 100 );
	printf( "------------\n" );
	quadratic( b[4], 100 );
	*/
	return 0;
}

double linear( int b, int n )
{
	int *table = (int *) calloc( b, sizeof(int ) );
	int i, j;
	int searchTime = 0;
	for( j = 0; j < n; j++ )
	{
		searchTime++;
		i = 1;
		for( i = 1; *(table + ( getNum(names[j]) + i ) % b ) != 0; i++ )
		{
			searchTime++;
		}
		*( table + ( getNum(names[j]) + i ) % b ) = i;
	}
	/*
	for( i = 0; i < b; i++ )
	{
		printf( "%d, ", *(table+i) );
	}
	printf( "\n" );
	*/
	free(table);
	return (double) searchTime / n;
}

double quadratic( int b, int n )
{
	int *table = (int *) calloc( b, sizeof(int ) );
	int i, j;
	int searchTime = 0;
	char nameAry[100];
	for( j = 0; j < n; j++ )
	{
		//strcpy( nameAry, "" );
		searchTime++;
		//printf( "----------\n" );
		for( i = 0; *(table + ( getNum(names[j]) + i * i ) % b ) != 0; i++ )
		{
			//strcat( nameAry, ", " );
			//strcat( nameAry, names[j] );
			searchTime++;
		}
		//printf( "%d\n-----------\n", i );
		//if( i >= 4 ) printf( "%s\n------\n", nameAry );
		*( table + ( getNum(names[j]) + i * i ) % b ) = i+1;
	}
	/*
	for( i = 0; i < b; i++ )
	{
		printf( "%d, ", *(table+i) );
	}
	printf( "\n" );
	*/
	free(table);
	return (double) searchTime / (double)n;
}

int getNum( char *s )
{
	int i, sum = 0;
	for( i = 0; *(s+i) != '\0'; i++ )
	{
		sum += *(s+i);
	}
	return sum;
}
