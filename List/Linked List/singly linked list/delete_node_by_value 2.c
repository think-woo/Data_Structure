//���Ҹ� ����Ͽ� �ش� ���Ҹ� ���� ��� �����ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _NODE {
    struct _NODE *next;
    int data;
};

void insert_node(struct _NODE *target, int data); //���� ��� ������ ���Ҹ� ���� ��� �߰�
void delete_node_by_value(struct _NODE *target, int key_element); //���� ������ ������ �ش� ���Ҹ� ���� ��� ����void delete_node_by_value(struct _NODE *target, int key_element);

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

	delete_node_by_value(head, 100);

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

void delete_node_by_value(struct _NODE *target, int key_element){

	struct _NODE *curr = target->next; //��ȯ ���
	struct _NODE *prev = NULL;

	if(target == NULL){ //���� ��� NULL�� �Լ� öȸ
		return;
	}

	//������ ��� Ž��
    while(curr != NULL){
		if(curr->data == key_element){
			break;
		}
		// �ݺ����� ���������� �������� �ּҰ��� ������ ����
		// curr >> ������ ���
		// prev >> ������ ����� ���� ���

		prev = curr;
		curr = curr->next;
    }

	if(prev == NULL){ //ù ����� ���� ���� �Ǻ�
		prev = target;
	}

	//���� ����
	prev->next = curr->next;
	free(curr);
	
}