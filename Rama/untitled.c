#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int val;
	struct node *izq, *der;
} Node;

int main () {

	Node *n1 = (Node*)malloc(sizeof(Node));
	n1->val = 1;
	n1->izq = NULL;
	n1->der = NULL;
	Node *n2 = (Node*)malloc(sizeof(Node));
	n2->val = 2;
	n2->izq = NULL;
	n2->der = NULL;
	int x = 2;
	int *p = &x;
	Node **array = (Node**)malloc(sizeof(Node*)*(*p));

	array[0] = n1;
	array[1] = n2;

	printf("%d\n", array[*p - 1]->val);
	return 0;
}