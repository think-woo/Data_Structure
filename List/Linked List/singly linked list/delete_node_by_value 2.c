//원소를 사용하여 해당 원소를 지닌 노드 삭제하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _NODE {
    struct _NODE *next;
    int data;
};

void insert_node(struct _NODE *target, int data); //기존 노드 다음에 원소를 가진 노드 추가
void delete_node_by_value(struct _NODE *target, int key_element); //기존 노드부터 시작해 해당 원소를 지닌 노드 삭제void delete_node_by_value(struct _NODE *target, int key_element);

int main()
{
	struct _NODE *head = malloc(sizeof(struct _NODE)); //헤드 노드
    struct _NODE *curr; //순환 노드
    struct _NODE *temp; //노드 주소를 저장할 임시 노드
	int i;

	head->next = NULL;

	for(i=100; i>0; i-=10){ //실험에 사용할 연결리스트 // 출력: 10 20 30 40 50 60 70 80 90 100
		insert_node(head, i);
	}

	delete_node_by_value(head, 100);

	curr = head->next;
    while(curr != NULL){//순환하면서 원소 출력
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

void delete_node_by_value(struct _NODE *target, int key_element){

	struct _NODE *curr = target->next; //순환 노드
	struct _NODE *prev = NULL;

	if(target == NULL){ //기존 노드 NULL시 함수 철회
		return;
	}

	//삭제할 노드 탐색
    while(curr != NULL){
		if(curr->data == key_element){
			break;
		}
		// 반복문을 빠져나오면 포인터의 주소값은 다음과 같다
		// curr >> 삭제할 노드
		// prev >> 삭제할 노드의 이전 노드

		prev = curr;
		curr = curr->next;
    }

	if(prev == NULL){ //첫 노드의 삭제 여부 판별
		prev = target;
	}

	//삭제 갱신
	prev->next = curr->next;
	free(curr);
	
}