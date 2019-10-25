#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct NODE{
	struct NODE *next;
	int Data; 
};

void insert_node(struct NODE *target, int Data);
void delete_node(struct NODE *target); //노드를 삭제할 함수

int main()
{
    struct NODE *head = malloc(sizeof(struct NODE)); //머리 노드
	struct NODE *curr; //순환 노드
	struct NODE *temp; //할당제거 할 때 사용할 임시 노드

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

	if(target == NULL){ //기존 노드가 NULL이면 함수취소
		return;
	}
	if(newNODE == NULL){ //메모리 할당 실패하면 함수취소
		return;
	}

	newNODE->next = target->next;
	newNODE->Data = Data;

	target->next = newNODE;

}

void delete_node(struct NODE *target){

	struct NODE *removeNODE = target->next; //기준 노드의 다음 노드를 삭제한다

	if(target == NULL){ //기존 노드가 NULL이면 함수취소
		return;
	}
	if(removeNODE == NULL){ //메모리 할당 실패하면 함수취소
		return;
	}

	target->next = removeNODE->next; //삭제할 노드의 다음 노드를 기준 노드와 연결한다

	free(removeNODE);
}

//참조: https://dojang.io/mod/page/view.php?id=647