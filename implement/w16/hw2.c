#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeTree
{
	int data;
	int level;
	struct nodeTree *left;
	struct nodeTree *right;
} node;

int calcLevel( node *head );
node *generalAVL( node *head );
node *newNode( int data );
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

	pResult( head, (char*) "" );
	pResult( generalAVL( head ), (char*) "" );

	return 0;
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

node *newNode( int data )
{
	node *newItem = (node *) calloc( 1, sizeof(node) );
	newItem->data = data;
	return newItem;
}

node *generalAVL( node *head )
{
	node *newItem = (node *) calloc( 1, sizeof(node) );
	int right = 0, left = 0;
	if( head->left != NULL ) left = calcLevel( head->left );
	if( head->right != NULL ) right = calcLevel( head->right );
	newItem->data = left - right;
	if( head->left != NULL ) newItem->left = generalAVL( head->left );
	if( head->right != NULL ) newItem->right = generalAVL( head->right );
	return newItem;
}


int calcLevel( node *head )
{
	int left = 0, right = 0;
	if( head->left != NULL ) left = 1 + calcLevel( head->left );
	if( head->right != NULL ) right = 1 + calcLevel( head->right );
	if( head->left == NULL && head->right == NULL ) return 1;
	return left > right ? left : right;
}
