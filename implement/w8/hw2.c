#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
	struct tree *right, *left;
	int data;
} node;

node *root;
void insert( node newItem );
void pResult( node *cur, char *str  );
node **searchInsertAdr( int data, node *cur );
int main( void )
{
	node newItem;
	root = ( node * ) malloc( sizeof( node ) );
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
		pResult( root, (char *) "" );
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
		*insertAdr = ( node * ) malloc( sizeof( node ) );
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
// ├　─　┼　┴　┬　┤　┌　┐　╞　═　╪　╡　│　▕
// 　└　┘　╭　╮　╰　╯
void pResult( node *cur, char *str  )
{
	char treeLine[10000];
	printf( "%d\n", cur->data );
	if( cur->right != NULL || cur->left != NULL )
	{
		printf( "%s├─", str );
		strcpy( treeLine, str );
		strcat( treeLine, "│ " );
		if( cur->right != NULL ) pResult( cur->right, treeLine );
		else printf( "NULL\n" );

		printf( "%s└─", str );
		strcpy( treeLine, str );
		strcat( treeLine, "  " );
		if( cur->left != NULL )	pResult( cur->left, treeLine );
		else printf( "NULL\n" );
	}
}
