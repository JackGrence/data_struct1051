#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
	char data;
	struct link *next;
} node;

int main( void )
{
	node item1, item2, item3;
	item1.data = 'a';
	item1.next = &item2;
	item2.data = 'b';
	item2.next = &item3;
	item3.data = 'c';
	item3.next = NULL;
	node *start;
	for( start = &item1; start != NULL; start = start->next )
	{
		if( start->next == NULL ) printf( "%c ", start->data );
		
		//printf( "%p\n", start );
	}
	printf( "\n" );
	return 0;
}
