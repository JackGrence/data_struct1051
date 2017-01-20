#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP( a, b ) ()

typedef struct nodeTree
{
	int data;
	int level;
	struct nodeTree *left;
	struct nodeTree *right;
} node;

int main( void )
{
	return 0;
}

node *newNode( int data )
{
	node *newItem = (node *) calloc( 1, sizeof(node) );
	newItem->data = data;
	return newItem;
}

void minUnion( node *a, node *b )
{
	if( a->data > b->data ) 
}

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
