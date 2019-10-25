#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct NODE{
	struct NODE *next;
	int Data; 
};

void insert_node(struct NODE *target, int Data);
struct NODE* find_node(struct NODE *target, int value); //��� ���� Data�� ã�� �Լ�
// ���� ���� ����Ʈ�� Ư�� ��带 ã������ ù ��° ������ ������ ������ ���ʴ�� �˻��ؾ� �Ѵ�.

int main()
{
    struct NODE *head = malloc(sizeof(struct NODE)); //�Ӹ� ���
	struct NODE *curr; //��ȯ ���
	struct NODE *temp; //�Ҵ����� �� �� ����� �ӽ� ���
	struct NODE *found; //ã�� ���� ������ ���

	head->next = NULL;
	
	insert_node(head, 10);
	insert_node(head, 20);
	insert_node(head, 30);

	found = find_node(head, 20);
	printf("%d\n", found->Data);

	curr = head->next;
	while(curr != NULL){
		printf("%d\n", curr->Data);
		curr = curr->next;
	}

	curr = head->next;
	while(curr != NULL){
		temp = curr->next;
		free(curr);
		curr = temp;
	}

	free(head);

    return 0;
}

void insert_node(struct NODE *target, int Data){

	struct NODE *newNODE = malloc(sizeof(struct NODE));

	if(target == NULL){
		return;
	}
	if(newNODE == NULL){
		return;
	}

	newNODE->next = target->next;
	newNODE->Data = Data;

	target->next = newNODE;

}

struct NODE* find_node(struct NODE *target, int value){

	struct NODE *curr = target->next;

	if(target == NULL){
		return NULL;
	}
	if(curr == NULL){
		return NULL;
	}

	while(curr != NULL){ //���� ������ ������ ��ȯ�ϸ鼭 ��� Ž��
		if(curr->Data == value){
			return curr;
		}
		curr = curr->next;
	}

	return NULL;
}