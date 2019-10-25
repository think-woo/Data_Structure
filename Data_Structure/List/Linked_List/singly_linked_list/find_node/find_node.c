#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct NODE{
	struct NODE *next;
	int Data; 
};

void insert_node(struct NODE *target, int Data);
struct NODE* find_node(struct NODE *target, int value); //노드 안의 Data를 찾는 함수
// 단일 연결 리스트는 특정 노드를 찾으려면 첫 번째 노드부터 마지막 노드까지 차례대로 검색해야 한다.

int main()
{
    struct NODE *head = malloc(sizeof(struct NODE)); //머리 노드
	struct NODE *curr; //순환 노드
	struct NODE *temp; //할당제거 할 때 사용할 임시 노드
	struct NODE *found; //찾은 값을 가지는 노드

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

	while(curr != NULL){ //기존 노드부터 시작해 순환하면서 노드 탐색
		if(curr->Data == value){
			return curr;
		}
		curr = curr->next;
	}

	return NULL;
}