#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct NODE{
	struct NODE *next; //���� ����� �ּҸ� ������ ������
	int Data; //�����͸� ������ ���
};

void insert_node(struct NODE *taget, int Data); //��带 �߰��� �Լ�

int main()
{
    struct NODE *head = malloc(sizeof(struct NODE)); //�Ӹ� ���
	struct NODE *curr; //��ȯ ���
	struct NODE *temp; //�Ҵ����� �� �� ����� �ӽ� ���

	head->next = NULL; //�Ӹ� ���� �����͸� �������� ����
	
	insert_node(head, 10);
	insert_node(head, 20);
	insert_node(head, 30);

	curr = head->next;
	while(curr != NULL){
		printf("%d\n", curr->Data);
		curr = curr->next;
	}

	curr = head->next;
	while(curr != NULL){
		temp = curr->next; //curr�� �����ϸ� curr->next�� ������ �� ����
		free(curr);
		curr = temp;
	}

	free(head);

    return 0;
}

void insert_node(struct NODE *target, int Data){

	struct NODE *newNODE = malloc(sizeof(struct NODE));

	newNODE->next = target->next; //���ο� ��忡 ���� ����� ���� ��� ����
	newNODE->Data = Data;

	target->next = newNODE; //���� ��忡 ���ο� ��� ����

}

//����: https://dojang.io/mod/page/view.php?id=646