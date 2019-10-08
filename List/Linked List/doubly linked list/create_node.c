//이중 연결 리스트를 생성하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _NODE {
    struct _NODE *next, *prev;
    int data;
};

void create_node(struct _NODE *target, int data); //원소를 가지는 이중 연결 리스트 생성

int main()
{
	struct _NODE *head = malloc(sizeof(struct _NODE)); //헤드 노드
	struct _NODE *curr; //순환 노드
	struct _NODE *temp; //임시 노드
	int i;

	head->next = NULL;

	for(i=100; i>0; i-=10){ //새로운 이중 연결 리스트 생성 //출력:
		create_node(head, i);
	}

	curr = head->next;
	while(curr != NULL){ //순환하면서 원소 출력
		printf("%d ", curr->data);
		curr = curr->next;
	}

	curr = head->next;
	while(curr != NULL){ //순환하면서 메모리 할당 해제
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	
    free(head);

    return 0;
}

void create_node(struct _NODE *target, int data){

	struct _NODE *newNODE = malloc(sizeof(struct _NODE)); //새로운 노드

	if(target == NULL){ //기준 노드가 NULL일시 함수 철회
		return;
	}
	if(newNODE == NULL){ //메모리 할당 실패시 함수 철회
		return;
	}
	
	//새로운 노드 갱신
	newNODE->prev = target; //새로운 노드의 왼쪽 노드
	newNODE->next = target->next; //새로운 노드의 오른쪽 노드
	newNODE->data = data; //원소 설정

	target->next = newNODE; //기준 노드의 새로운 오르쪽 노드를 설정

}