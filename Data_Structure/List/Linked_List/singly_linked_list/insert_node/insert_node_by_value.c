//���Ḯ��Ʈ�� ��������Ʈ�� ������ ��, �ش� ���Ҹ� ������ �°� �����ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _NODE {
    struct _NODE *next;
    int data;
};

void insert_node(struct _NODE *target, int data); //���� ��� ������ ���Ҹ� ���� ��� �߰�
void insert_node_by_value(struct _NODE *target, int key_element); //���� ������ ������ ���Ҹ� ������ ���� �����ϱ�

int main()
{
	struct _NODE *head = malloc(sizeof(struct _NODE)); //��� ���
    struct _NODE *curr; //��ȯ ���
    struct _NODE *temp; //��� �ּҸ� ������ �ӽ� ���

	int i;

	head->next = NULL;

	for(i=100; i>0; i-=10){ //���迡 ����� ���Ḯ��Ʈ // ���: 10 20 30 40 50 60 70 80 90 100
		insert_node(head, i);
	}

	insert_node_by_value(head, 1);

	curr = head->next;
    while(curr != NULL){//��ȯ�ϸ鼭 ���� ���
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

void insert_node(struct _NODE *target, int data){

	struct _NODE *newNODE = malloc(sizeof(struct _NODE)); //���ο� ��� ����

	if(target == NULL){ //���� ��� NULL�� �Լ� öȸ
		return;
	}
	if(newNODE == NULL){ //���ο� ��� �Ҵ� ���н� �Լ� öȸ
		return;
	}

	newNODE->next = target->next; //���ο� ��忡 ���� ��尡 ������ ���� ����� �ּ� ����
	newNODE->data = data; //���ο� ��忡 ���� ����

	target->next = newNODE; //���� ����� ���� ��忡�� ���ο� ��� ����

}

void insert_node_by_value(struct _NODE *target, int key_element){

	struct _NODE *curr; //��ȯ ���
	struct _NODE *prev; //���� ���
	struct _NODE *newNODE = malloc(sizeof(struct _NODE)); //���ο� ���

	if(target == NULL){ //���� ��� NULL�� �Լ� öȸ
		return;
	}
	if(newNODE == NULL){ //���ο� ��� �Ҵ� ���н� �Լ� öȸ
		return;
	}

	//���Ҹ� ������ ������ ��ġ �˻�
	curr = target->next;
	prev = NULL;
	while(curr != NULL){
		if(curr->data > key_element){
			break;
		}
		//�ݺ����� �������� ���, �������� �ּҰ�
		// curr >> ������ ���Һ��� ū ���
		// prev >> ������ ���Һ��� ���� ���

		prev = curr;
		curr = curr->next;
    }

	if(prev == NULL){ //ù ��° ��� �տ� �߰��ϴ� ��츦 �Ǻ�
		prev = target;
	}

	//���ο� ��� �����ϱ�
	newNODE->next = curr; //���ο� ���� ���� ��� ����
	newNODE->data = key_element; //���ο� ��忡 ���� ����

	prev->next = newNODE; //�� ���� ���ο� ��� ����

}