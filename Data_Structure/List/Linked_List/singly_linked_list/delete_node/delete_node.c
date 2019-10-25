#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct NODE{
	struct NODE *next;
	int Data; 
};

void insert_node(struct NODE *target, int Data);
void delete_node(struct NODE *target); //��带 ������ �Լ�

int main()
{
    struct NODE *head = malloc(sizeof(struct NODE)); //�Ӹ� ���
	struct NODE *curr; //��ȯ ���
	struct NODE *temp; //�Ҵ����� �� �� ����� �ӽ� ���

	head->next = NULL;
	
	insert_node(head, 10);
	insert_node(head, 20);
	insert_node(head, 30);

	delete_node(head);

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

	if(target == NULL){ //���� ��尡 NULL�̸� �Լ����
		return;
	}
	if(newNODE == NULL){ //�޸� �Ҵ� �����ϸ� �Լ����
		return;
	}

	newNODE->next = target->next;
	newNODE->Data = Data;

	target->next = newNODE;

}

void delete_node(struct NODE *target){

	struct NODE *removeNODE = target->next; //���� ����� ���� ��带 �����Ѵ�

	if(target == NULL){ //���� ��尡 NULL�̸� �Լ����
		return;
	}
	if(removeNODE == NULL){ //�޸� �Ҵ� �����ϸ� �Լ����
		return;
	}

	target->next = removeNODE->next; //������ ����� ���� ��带 ���� ���� �����Ѵ�

	free(removeNODE);
}

//����: https://dojang.io/mod/page/view.php?id=647