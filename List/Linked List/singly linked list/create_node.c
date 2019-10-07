#include <stdio.h>
#include <stdlib.h>

struct NODE{
	struct NODE *next;
	int data;
};

int main(){

	struct NODE *head = malloc(sizeof(struct NODE));
	struct NODE *node1 = malloc(sizeof(struct NODE));
	struct NODE *node2 = malloc(sizeof(struct NODE));
	struct NODE *curr;

	head->next = node1;

	node1->next = node2;
	node1->data = 30;

	node2->next = NULL;
	node2->data = 50;

	curr = head->next;

	while(curr != NULL){
		printf("%d\n", curr->data);
		curr = curr->next;
	}

	free(node2);
	free(node1);
	free(head);

	return 0;
}