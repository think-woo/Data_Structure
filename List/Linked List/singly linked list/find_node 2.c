//�ش� ���Ҹ� ���� ��带 �˻�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _NODE {
    struct _NODE *next;
    int data;
};

void insert_node(struct _NODE *target, int data); //���� ��� ������ ���Ҹ� ���� ��� �߰�
void search_node(struct _NODE *target, int key_element); //���� ��带 ������ ���Ҹ� ���� ��� Ž��

int main()
{
	struct _NODE *head = malloc(sizeof(struct _NODE)); //��� ���
    struct _NODE *curr; //��ȯ ���
    struct _NODE *temp; //��� �ּҸ� ������ �ӽ� ���

	int i;

	head->next = NULL;

	for(i=10; i<=100; i+=10){ //���迡 ����� ���Ḯ��Ʈ // ���: 100 90 80 70 60 50 40 30 20 10
		insert_node(head, i);
	}

	search_node(head, 20);

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

void search_node(struct _NODE *target, int key_element){

	struct _NODE *curr; //��ȯ ���
	int count=0; //�� ��° ���Ḯ��Ʈ���� �˻��Ǵ��� �˷��ִ� ����
	int i;

	if(target == NULL){ //���� ��� NULL�� �Լ� öȸ
		return;
	}

	curr = target->next; //��� ��忡�� ������ ���Ұ� ����
    while(curr != NULL){
		if(curr->data == key_element){
			printf("ã�� ����:%d ��ġ: %d��°\n", curr->data, count);
			return;
		}
	    curr = curr->next;
		count++;
    } 
}