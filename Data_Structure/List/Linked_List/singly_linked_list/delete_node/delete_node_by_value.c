#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct NODE {
    struct NODE *next;
    int data;
};

void addFirst(struct NODE *target, int data);
void removeNode(struct NODE *node, int data);

int main()
{
    int numArr[10] = { 0, };
    int removeNum;
	int i;

	struct NODE *head = malloc(sizeof(struct NODE));
	struct NODE *curr;

    scanf("%d %d %d %d %d %d %d %d %d %d",
        &numArr[0], &numArr[1], &numArr[2], &numArr[3], &numArr[4],
        &numArr[5], &numArr[6], &numArr[7], &numArr[8], &numArr[9]
    );

    scanf("%d", &removeNum);
 
    head->next = NULL;

    for (i = 0; i < 10; i++)
    {
        addFirst(head, numArr[i]);
    }

    removeNode(head, removeNum);

    curr = head->next;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    curr = head->next;
    while (curr != NULL)
    {
        struct NODE *next = curr->next;
        free(curr);
        curr = next;
    }

    free(head);

    return 0;
}

void addFirst(struct NODE *target, int data)
{
    struct NODE *newNode = malloc(sizeof(struct NODE));
    newNode->next = target->next;
    newNode->data = data;
    target->next = newNode;
}

void removeNode(struct NODE *node, int data){

	struct NODE *curr = node;
	struct NODE *prev = NULL;
	while (curr != NULL)
	{
		if (curr->data == data) // 삭제할 노드를 발견하면
		{
			// 직전 노드의 다음 노드에 현재 노드의 다음 노드를 넣어줌
			prev->next = curr->next;
			free(curr); // 현재 노드 해제
			return;
		}

		prev = curr;        // 현재 노드를 직전 노드 포인터에 저장
		curr = curr->next;  // 다음 노드로 이동
	}
}