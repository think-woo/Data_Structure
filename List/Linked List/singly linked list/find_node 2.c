//해당 원소를 가진 노드를 검색
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _NODE {
    struct _NODE *next;
    int data;
};

void insert_node(struct _NODE *target, int data); //기존 노드 다음에 원소를 가진 노드 추가
void search_node(struct _NODE *target, int key_element); //기존 노드를 시작해 원소를 가진 노드 탐색

int main()
{
	struct _NODE *head = malloc(sizeof(struct _NODE)); //헤드 노드
    struct _NODE *curr; //순환 노드
    struct _NODE *temp; //노드 주소를 저장할 임시 노드

	int i;

	head->next = NULL;

	for(i=10; i<=100; i+=10){ //실험에 사용할 연결리스트 // 출력: 100 90 80 70 60 50 40 30 20 10
		insert_node(head, i);
	}

	search_node(head, 20);

    curr = head->next;
    while(curr != NULL){ //순환하면서 메모리 할당 해제
	    temp = curr->next;
	    free(curr);
	    curr = temp;
    }
	
    free(head);


    return 0;
}

void insert_node(struct _NODE *target, int data){

	struct _NODE *newNODE = malloc(sizeof(struct _NODE)); //새로운 노드 생성

	if(target == NULL){ //기존 노드 NULL시 함수 철회
		return;
	}
	if(newNODE == NULL){ //새로운 노드 할당 실패시 함수 철회
		return;
	}

	newNODE->next = target->next; //새로운 노드에 기존 노드가 가졌던 다음 노드의 주소 설정
	newNODE->data = data; //새로운 노드에 원소 삽입

	target->next = newNODE; //기존 노드의 다음 노드에는 새로운 노드 설정

}

void search_node(struct _NODE *target, int key_element){

	struct _NODE *curr; //순환 노드
	int count=0; //몇 번째 연결리스트에서 검색되는지 알려주는 변수
	int i;

	if(target == NULL){ //기존 노드 NULL시 함수 철회
		return;
	}

	curr = target->next; //헤드 노드에는 어차피 원소가 없다
    while(curr != NULL){
		if(curr->data == key_element){
			printf("찾는 원소:%d 위치: %d번째\n", curr->data, count);
			return;
		}
	    curr = curr->next;
		count++;
    } 
}