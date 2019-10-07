#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct NODE{
	struct NODE *next; //다음 노드의 주소를 저장할 포인터
	int Data; //데이터를 저장할 멤버
};

void insert_node(struct NODE *taget, int Data); //노드를 추가할 함수

int main()
{
    struct NODE *head = malloc(sizeof(struct NODE)); //머리 노드
	struct NODE *curr; //순환 노드
	struct NODE *temp; //할당제거 할 때 사용할 임시 노드

	head->next = NULL; //머리 노드는 데이터를 저장하지 않음
	
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
		temp = curr->next; //curr를 제거하면 curr->next에 접근할 수 없다
		free(curr);
		curr = temp;
	}

	free(head);

    return 0;
}

void insert_node(struct NODE *target, int Data){

	struct NODE *newNODE = malloc(sizeof(struct NODE));

	newNODE->next = target->next; //새로운 노드에 기존 노드의 다음 노드 연결
	newNODE->Data = Data;

	target->next = newNODE; //기존 노드에 새로운 노드 연결

}

//참조: https://dojang.io/mod/page/view.php?id=646