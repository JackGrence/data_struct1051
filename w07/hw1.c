#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element
{
	int coeff;
	int pow;
	struct element *link;
} node;

void addq( node *newitem, node **top );
node *newnode( int coeff, int pow );
void pstack( node *head );
void freestack( node *head );
node *addnode( node *head );
node *mul( node *n1, node *n2, node *resulttop, int resultlen );

int main( void )
{
	char bignum[10000];
	int numlen, resultlen;
	int i, j; // loop index
	node *numtop[2], *resulttop, tmp;

	resultlen = 0;
	for( j = 0; j < 2; j++ )
	{
		printf( "number%d: ", j + 1 );
		scanf( "%s", bignum );
		numlen = strlen( bignum );
		resultlen += numlen;
		for( i = 0; i < numlen; i++ )// store bignumber
		{
			tmp.coeff = bignum[i] - 48;
			tmp.pow = numlen - 1 - i;
			if( tmp.coeff != 0 ) addq( &tmp, &numtop[j] ); // ignore zero value
		}
		//pstack( numtop[j] );
	}

	resulttop = ( node * ) malloc( sizeof( node ) * resultlen );
	pstack( mul( numtop[0], numtop[1], resulttop, resultlen ) );

	return 0;
}

node *mul( node *n1, node *n2, node *resulttop, int resultlen )
{
	node tmp;
	node *n2backup = n2;
	for( ; n1 != NULL; n1 = n1->link )
	{
		for( n2 = n2backup; n2 != NULL; n2 = n2->link )
		{
			tmp.coeff = n1->coeff * n2->coeff;
			tmp.pow = n1->pow + n2->pow;
			addq( &tmp, &((resulttop + tmp.pow)->link) );  // resulttop->link is stack top
		}
	}

	int i;
	node *newitem, *resulthead, carry;
	resulthead = NULL;
	carry.coeff = 0;
	for( i = 0; i < resultlen; i++ )
	{
		// newitem not the final result
		// use carry to solve it
		// resulthead point to final result
		carry.pow = i;
		addq( &carry, &(resulttop + i)->link );// add carry in resulttop
		newitem = addnode( (resulttop + i)->link );
		carry.coeff = newitem->coeff / 10;
		newitem->coeff %= 10;
		newitem->pow = i;
		if( newitem->coeff > 0 ) addq( newitem, &resulthead );
		freestack( (resulttop + i)->link );// free result stack top
	}
	return resulthead;
}

node *addnode( node *head )
{
	node *tmp = ( node * ) malloc( sizeof( node ) );
	tmp->coeff = 0;
	tmp->pow = head->pow;
	for( ; head != NULL; head = head->link )
	{
		tmp->coeff += head->coeff;
	}
	return tmp;
}

void freestack( node *head )
{
	node *cur, *next;
	for( cur = head; cur != NULL; cur = next )
	{
		next = cur->link;
		free( cur );
	}
}

void pstack( node *head )
{
	int pow = head->pow, i;
	for( ; head != NULL; head = head->link )
	{
		for( ; abs( pow - head->pow ) > 1; pow > head->pow ? pow-- : pow++ ) //print 0
		{
			printf( "0" );
		}
		pow = head->pow;
		printf( "%d", head->coeff );
		if( head->link == NULL )
		{
			for( i = 0; i < head->pow; i++ )
			{
				printf( "0" );
			}
		}
		//printf( "%dx^%d ", head->coeff, head->pow );
	}
	printf( "\n" );
}

void addq( node *newitem, node **top )
{
	node *tmp = ( node * ) malloc( sizeof( node ) );
	*tmp = *newitem;
	tmp->link = *top;
	*top = tmp;
}
