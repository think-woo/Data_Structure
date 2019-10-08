//���� ���� ����Ʈ�� �������̶� ������ ��, �߰��� ���ҿ� ���� �˸��� �ڸ��� ��� �����ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _NODE {
    struct _NODE *next, *prev;
    int data;
};

void create_node(struct _NODE *target, int data); //���Ҹ� ������ ���� ���� ����Ʈ ����
void insert_node_by_value(struct _NODE *target, int key_element); //���� ���� ����Ʈ�� ��� ����

int main()
{
	struct _NODE *head = malloc(sizeof(struct _NODE)); //��� ���
	struct _NODE *curr; //��ȯ ���
	struct _NODE *temp; //�ӽ� ���
	int i;

	head->next = NULL;

	for(i=100; i>0; i-=10){ //���ο� ���� ���� ����Ʈ ���� //���: 10 20 30 40 50 60 70 80 90 100
		create_node(head, i);
	}

	insert_node_by_value(head, 5);

	curr = head->next;
	while(curr != NULL){ //��ȯ�ϸ鼭 ���� ���
		printf("%d ", curr->data);
		curr = curr->next;
	}

	curr = head->next;
	while(curr != NULL){ //��ȯ�ϸ鼭 �޸� �Ҵ� ����
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	
    free(head);

    return 0;
}

void create_node(struct _NODE *target, int data){

	struct _NODE *newNODE = malloc(sizeof(struct _NODE)); //���ο� ���

	if(target == NULL){ //���� ��尡 NULL�Ͻ� �Լ� öȸ
		return;
	}
	if(newNODE == NULL){ //�޸� �Ҵ� ���н� �Լ� öȸ
		return;
	}
	
	//���ο� ��� ����
	newNODE->prev = target; //���ο� ����� ���� ���
	newNODE->next = target->next; //���ο� ����� ������ ���
	newNODE->data = data; //���� ����

	target->next = newNODE; //���� ����� ���ο� ������ ��带 ����

}

void insert_node_by_value(struct _NODE *target, int key_element){

	struct _NODE *newNODE = malloc(sizeof(struct _NODE)); //���ο� ���
	struct _NODE *curr; //��ȯ ���

	if(target == NULL){ //���� ��尡 NULL�Ͻ� �Լ� öȸ
		return;
	}
	if(newNODE == NULL){ //�޸� �Ҵ� ���н� �Լ� öȸ
		return;
	}

	curr = target; // ù ��° ��尡 �� �� �����Ƿ� head���� ����
	while(curr != NULL){ //��尡 ���Ե� �˸��� ��ġ Ž��
		if(curr->next->data > key_element){ //���� ���� ����Ʈ�� ������ �� �ٸ��� �ߴ� >> ��������� ���� curr ������ ����
			break;
		}
		//���ǹ��� �޼��� curr��ġ�� ���ο� ��尡 �����Ǿ�� �Ѵ�
		curr = curr->next;
	}

	//������ ���
	newNODE->next = curr->next; //������ ����
	curr->next = newNODE; //���� ������ ����

	//���� ���
	newNODE->prev = curr; //������ ����
	newNODE->next->prev = newNODE; //���� ������ ����

	//���� ����
	newNODE->data = key_element;
}