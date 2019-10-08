//이중 연결 리스트가 순차적이라 가정할 때, 추가할 원소에 따라 알맞은 자리에 노드 삽입하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _NODE {
    struct _NODE *next, *prev;
    int data;
};

void create_node(struct _NODE *target, int data); //원소를 가지는 이중 연결 리스트 생성
void insert_node_by_value(struct _NODE *target, int key_element); //이중 연결 리스트에 노드 삽입

int main()
{
	struct _NODE *head = malloc(sizeof(struct _NODE)); //헤드 노드
	struct _NODE *curr; //순환 노드
	struct _NODE *temp; //임시 노드
	int i;

	head->next = NULL;

	for(i=100; i>0; i-=10){ //새로운 이중 연결 리스트 생성 //출력: 10 20 30 40 50 60 70 80 90 100
		create_node(head, i);
	}

	insert_node_by_value(head, 5);

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

void insert_node_by_value(struct _NODE *target, int key_element){

	struct _NODE *newNODE = malloc(sizeof(struct _NODE)); //새로운 노드
	struct _NODE *curr; //순환 노드

	if(target == NULL){ //기준 노드가 NULL일시 함수 철회
		return;
	}
	if(newNODE == NULL){ //메모리 할당 실패시 함수 철회
		return;
	}

	curr = target; // 첫 번째 노드가 될 수 있으므로 head에서 시작
	while(curr != NULL){ //노드가 삽입될 알맞은 위치 탐색
		if(curr->next->data > key_element){ //단일 연결 리스트와 조건을 좀 다르게 했다 >> 상대적으로 편한 curr 설정을 위해
			break;
		}
		//조건문을 달성시 curr위치에 새로운 노드가 생성되어야 한다
		curr = curr->next;
	}

	//오른쪽 노드
	newNODE->next = curr->next; //포인터 생성
	curr->next = newNODE; //기존 포인터 갱신

	//왼쪽 노드
	newNODE->prev = curr; //포인터 생성
	newNODE->next->prev = newNODE; //기존 포인터 갱신

	//원소 삽입
	newNODE->data = key_element;
}