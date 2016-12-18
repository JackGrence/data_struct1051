// select sort
// insertion sort (link list)
// quick sort *Ranking
// 6 5 2 9 3
// input 3 output 2
// 		 6		  4
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} item;
void swap( int *a, int *b );
item *deleteI( item *head, item *del );
void add( item *add, item *newI );
void insertSort( item *head );
void push( item *head, int data );
int main( void )
{
	item head;
	int ary[10] = { 10, 20, 40, 30, 5, 100, 8, 90, 11, 111 };
	int i;
	head.next = NULL;
	for( i = 0; i < 10; i++ ) push( &head, ary[i] );
	insertSort( &head );
	item *ptr;
	for( ptr = head.next; ptr != NULL; ptr = ptr->next ) printf( "%d\n", ptr->data );
	return 0;
}

void push( item *head, int data )
{
	item *ptr, *newItem;
	newItem = (item *) malloc( sizeof( item ) );
	newItem->data = data;
	if( head->next == NULL )
	{
		head->next = newItem;
	}
	else
	{
		for( ptr = head->next; ptr->next != NULL; ptr = ptr->next );
		ptr->next = newItem;
	}
}
void insertSort( item *head )
{
	item *ptr, *cur, *prePtr, *sortedLast;
	sortedLast = head->next;
	cur = head->next->next;
	while( cur != NULL )
	{
		ptr = head->next;
		prePtr = head;
		while( ptr != cur )
		{
			if( ptr->data >= cur->data )
			{
				sortedLast->next = cur->next;
				cur->next = ptr;
				prePtr->next = cur;
				break;
			}
			ptr = ptr->next;
			prePtr = prePtr->next;
		}
		if( cur->data > sortedLast->data ) sortedLast = cur;
		cur = sortedLast->next;
	}
}
item *deleteI( item *head, item *del )
{
	item *ptr;
	for( ptr = head->next; ptr->next != del; ptr = ptr->next );
	ptr->next = del->next;
	return del;
}
void add( item *add, item *newI )
{
	newI->next = add->next;
	add->next = newI;
}

void swap( int *a, int *b )
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
