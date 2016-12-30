#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeTree
{
	int data;
	struct nodeTree *left;
	struct nodeTree *right;
} node;
node *newNode( int data );
node *generalShortest( node *head );
int shortest( node *head );
void pResult( node *cur, char *str  );
int main( void )
{
	node *head = newNode( 10 );
	node *cur = head;
	head->left = newNode( 20 );
	head->right = newNode( 2 );
	
	cur = head->left;
	cur->left = newNode(1);
	cur->right = newNode(2);

	cur = cur->left;
	cur->left = newNode(2);
	cur->right = newNode(4);

	cur = cur->left;
	cur->left = newNode(3);

	cur = head->right;
	cur->left = newNode(50);
	cur->right = newNode(40);

	cur = cur->left;
	cur->left = newNode(100);
	printf( "%d\n", shortest( head ) );
	pResult( head, (char*) "" );
	pResult( generalShortest( head ), (char*) "" );
	return 0;
}

int shortest( node *head )
{
	if( head != NULL ) return 1 + shortest(head->right);
	else return 0;
}

node *generalShortest( node *head )
{
	node *root = (node *) calloc( 1, sizeof(node) );
	root->data = shortest( head );
	if( head->left != NULL ) root->left = generalShortest( head->left );
	if( head->right != NULL ) root->right = generalShortest( head->right );
	return root;
}

node *newNode( int data )
{
	node *newItem = (node *) calloc( 1, sizeof(node) );
	newItem->data = data;
	return newItem;
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
