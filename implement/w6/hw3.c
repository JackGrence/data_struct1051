#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
	char data;
	struct link *next;
} node;
node *start, *head;
void push( char data, node **ptr )
{
	node *tmp = malloc( sizeof( node ) );
	tmp->data = data;
	tmp->next = *ptr;
	*ptr = tmp;
}

void presult(void)
{
	for( start = head; start != NULL; start = start->next )
	{
		 printf( "%c ", start->data );
		
		//printf( "%p\n", start );
	}
	printf( "\n" );
}

int main( void )
{
	node item1, item2, item3;
	item1.data = 'a';
	item1.next = &item2;
	item2.data = 'b';
	item2.next = &item3;
	item3.data = 'c';
	item3.next = NULL;
	char item;
	head = &item1;

	while( scanf( "%c", &item ) != EOF )
	{
		while( item == '\n' ) scanf( "%c", &item );
		push( item, &head );
		presult();
	}
	return 0;
}
