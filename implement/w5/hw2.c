#include <stdio.h>
#include <stdlib.h>
#define QUESIZE 10
#define QUENO 2

typedef struct 
{
	int data[ QUESIZE ];
	int *front, *rear;
	int size; 
} que;

que queue[2];
void addq( int add, que *queue );
int deletq( que *queue );
void pqueue( void );
int quefirstvalue( int q );

int main( void )
{
	int i, j;
	for( j = 0; j < QUENO; j++ )
	{
		for( i = 0; i < QUESIZE; i++ )
		{
			queue[j].data[i] = 0;
		}
		queue[j].front = queue[j].data;
		queue[j].rear = queue[j].data;
		queue[j].size = 0;
	}

	int n;
	printf( "checkout:" );
	while( scanf( "%d", &n ) != EOF )
	{
		if( n > 0 )
		{
			if( queue[0].size >= QUESIZE && queue[1].size >= QUESIZE )
			{
				printf( "those queues are already full\n" );
			}
			else if( queue[0].size <= queue[1].size )
			{
				addq( n, &queue[0] );
			}
			else
			{
				addq( n, &queue[1] ); 
			}
		}
		else if( n < 0 )
		{
			n = 0 - n;
			if( quefirstvalue( 0 ) == n )
			{
				deletq( &queue[0] );
			}
			else if( quefirstvalue( 1 ) == n )
			{
				deletq( &queue[1] );
			}
			else
			{
				printf( "nobody\n" );
			}
		}

		pqueue();
		printf( "checkout:" );	
	}

	return 0;
}

int quefirstvalue( int q )
{
	int offset = queue[q].front - queue[q].data;
	offset++;
	offset %= QUESIZE;
	return queue[q].data[ offset ];
}

void pqueue( void )
{
	int *start;
	int offset;
	int i, j;
	for( j = 0; j < QUENO; j++ )
	{
		start = queue[j].front;
		offset = start - queue[j].data;
		for( i = 0; i < queue[j].size; i++ )
		{
			offset++;
			offset %= QUESIZE;
			printf( "%d ", queue[j].data[offset] );
		}
		printf("\n");
	}

	printf( "\n" );
}

void addq( int add, que *queue )
{
	int offset;
	offset = queue->rear - queue->data;
	offset++;
	offset %= QUESIZE;
	(queue->size)++;
	queue->rear = queue->data + offset;
	*(queue->rear) = add;
}

int deletq( que *queue )
{
	int queue1;
	int offset;
	(queue->size)--;
	offset = queue->front - queue->data;
	offset++;
	offset %= QUESIZE;
	queue->front = queue->data + offset;
	queue1 = *(queue->front);
	*(queue->front) = 0;
	return queue1;
}

