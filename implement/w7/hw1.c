// llink data rlink
// circular double linked
// 1. insert
// 2. delete or error
// 3. construct a tree
/*
 * lchild data rchild
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct doublelink
{
	int data;
	struct doublelink *rlink, *llink;
} node;

void pque( void );
void insert( int data );
void delete( int data );
node dummy;

int main( void )
{
	dummy.rlink = &dummy;
	dummy.llink = &dummy;
	insert(1);
	insert(2);
	pque();
	insert(5);
	insert(3);
	pque();
	int item, mode;

	
	printf( "(1)insert(2)delete:" );
	while( scanf( "%d", &mode ) != EOF )
	{
		printf( "item:" );
		scanf( "%d", &item );
		if( mode == 1 )
		{
			insert( item );
		}
		else if( mode == 2 ) delete( item );
		pque();
		printf( "(1)insert(2)delete:" );
	
	}

	return 0;
}



void pque( void )
{
	node *prt;
	prt = dummy.rlink;
	printf( "----data----\n" );
	if( prt == &dummy ) printf( "nothing\n" );
	for( prt = dummy.rlink; prt->rlink != dummy.rlink; prt = prt->rlink )
	{
		printf( "%d ", prt->data );
	}
	printf( "\n------------\n" );
}

void delete( int data )
{
	node *search;
	char judge;
	if( dummy.rlink == &dummy )
	{
		printf( "nothing can delete\n" );
	}
	else
	{
		judge = 1;
		for( search = dummy.rlink; search->rlink != dummy.rlink; search = search->rlink )
		{
			if( data == search->data )
			{
				(search->llink)->rlink = search->rlink;
				(search->rlink)->llink = search->llink;
				free( search );
				judge = 0;
				break;
			}
		}
		if( judge ) printf( "not find item\n" );
	}
}

void insert( int data )
{
	node *tmp = malloc( sizeof( node ) );
	node *search;
	tmp->data = data;
	//printf( "%d\n", data );	
	if( dummy.rlink == &dummy )
	{
		tmp->rlink = &dummy;
		tmp->llink = &dummy;
		dummy.rlink = tmp;
		dummy.llink = tmp;
	}
	else
	{
		for( search = dummy.rlink; search->rlink != dummy.rlink; search = search->rlink )
		{
			if( data < search->data )
			{
				tmp->rlink = search;
				tmp->llink = search->llink;
				(search->llink)->rlink = tmp;
				search->llink = tmp;
				break;
			}
			else if( search->rlink == &dummy )
			{
				//printf( "search-rlink = dummy\n" );
				tmp->rlink = search->rlink;
				tmp->llink = search;
				search->rlink = tmp;
				break;
			}
		}
	}
	

}
