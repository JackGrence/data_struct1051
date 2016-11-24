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


node root;

node *add( int item );

int main( void )
{
	node *ptr;
	root.data = 3;
	root.rlink = add(2);
	root.llink = add(6);

	ptr = root.llink;
	ptr->rlink = add(8);
	ptr->llink = add(10);

	ptr = ptr->rlink;
	ptr->llink = add(7);

	ptr = &root;
	printf( "\t\t%d\n", ptr->data );
	printf( "\t%d\t\t%d\n", ptr->llink->data, ptr->rlink->data );
	ptr = ptr->llink;
	printf( "    %d\t    %d\n", ptr->llink->data, ptr->rlink->data );
	ptr = ptr->rlink;
	printf( "\t  %d\n", ptr->llink->data );

	return 0;
}

node *add( int item )
{
	node *tmp = malloc( sizeof( node ) );
	tmp->data = item;
	return tmp;
}


