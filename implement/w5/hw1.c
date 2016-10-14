#include <stdio.h>
#include <stdlib.h>
/*
easy queue
*/
char *front, *rear;
char queue[10];
void addq( char add );
char deletq( void );
void pqueue( void );

int main( void )
{
	int i;
	for( i = 0; i < 10; i++ )
	{
		queue[i] = 0;
	}
	int mode;
	char item, buf;
	front = queue;
	rear = queue;
	printf( "(1)add queue\n(2)delete queue\n>>" );
	while( scanf( "%d", &mode ) != EOF )
	{
		if( mode == 1 )
		{
			if( rear == queue + 10 )
			{
				printf( "queue full\n" );
			}
			else
			{
				printf( "item:" );
				scanf( "%c", &item );
				while( item == '\n' ) scanf( "%c", &item );
				addq( item );

			}
		}
		else if( mode == 2 )
		{
			if( front == rear )
			{
				printf( "queue not hava data" );
			}
			else deletq();
		}
		pqueue();
		printf( "(1)add queue\n(2)delete queue\n>>" );


	}


	return 0;
}

void pqueue( void )
{
	char *start = front;
	while( start != rear + 1 )
	{
		printf( "%c ", *start );
		start++;
	}
	printf( "\n\n" );
}

void addq( char add )
{
	rear++;
	*rear = add;
}

char deletq( void )
{
	char queue1;
	front++;
	queue1 = *front;
	*front = 0;
	return queue1;
}

