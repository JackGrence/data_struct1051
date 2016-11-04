#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	struct tree *right, *left;
	int data;
} node;

node *root;
void insert( node newItem );
void pResult( node *cur, int index );
node **searchInsertAdr( int data, node *cur );
int main( void )
{
	node newItem;
	root = malloc( sizeof( node ) );
	root->data = 50;
	
	newItem.right = NULL;
	newItem.left = NULL;

	newItem.data = 10;
	insert( newItem );
	newItem.data = 80;
	insert( newItem );
	
	printf( "insert data:" );
	while( scanf( "%d", &newItem.data ) != EOF )
	{
		insert( newItem );
		pResult( root, 0 );
		printf( "insert data:" );
	}

	printf( "%d\n", root->data );
	printf( "%d %d\n", (root->left)->data, (root->right)->data );
	return 0;
}

void insert( node newItem )
{
	node **insertAdr;
	insertAdr = searchInsertAdr( newItem.data, root );
	if( insertAdr == NULL )
	{
		printf( "can't insert\n" );
	}
	else
	{
		*insertAdr = malloc( sizeof( node ) );
		**insertAdr = newItem;
	}

}

node **searchInsertAdr( int data, node *cur )
{
	if( data > cur->data )
	{
		return cur->right == NULL ? &(cur->right) : searchInsertAdr( data, cur->right );
	}
	else if( data < cur->data )
	{
		return cur->left == NULL ? &(cur->left) : searchInsertAdr( data, cur->left );
	}
	else
	{
		return NULL;
	}
}

void pResult( node *cur, int index )
{
	int i;
	printf( "%d ", cur->data );
	if( cur->right != NULL ) pResult( cur->right, index + 1 );
	printf( "\n" );
	if( cur->left != NULL ) 
	{
		for( i = 0; i < index + 1; i++ )
		{
			printf( "%3s", " " );
		}
		pResult( cur->left, index + 1 );
	}
}
