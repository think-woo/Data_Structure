//�������� ����
#include <stdio.h>
#include <stdlib.h> //malloc(), free();

struct Array{
	int size; //�迭�� ũ��
	int count;//���� �迭�� ���� ����
	int *intArr; //�迭. �ڷ����� ����ڼ���.
};

void insert_by_value(struct Array *myArr, int key_element, int count); //count��ŭ ���Ҹ� ���� �迭�� Ư�� ���Ҹ� ����
void insertion_sort(struct Array *myArr, int count); //count��ŭ ���Ҹ� ���� �迭�� ��������

int main(){

	struct Array *myArr = malloc(sizeof(struct Array));
	int i; //�ݺ���

	//�迭 ���� ����
	myArr->size=10;
	myArr->intArr = malloc(sizeof(int)*10);
	myArr->count = 7;
	for(i=0; i<myArr->count; i++){
		myArr->intArr[i] = myArr->count-i;
	}
	//�迭 ���� �� //���� 7 6 5 4 3 2 1

	insertion_sort(myArr, myArr->count);

	for(i=0; i<myArr->count; i++){
		printf("%d ", myArr->intArr[i]); //���: 1 2 3 4 5 6 7
	}

	free(myArr->intArr);
	free(myArr);

	return 0;
}

void insert_by_value(struct Array *myArr, int key_element, int count){

	int i,j;

	// 1)���� �߰��� ��ġ ã��
	for(i=0; i<count; i++){
		if(myArr->intArr[i] > key_element){
			break;
			//�״�� ���Ұ� ����� ��ġ ����
		}
	}

	// 2)���� ���� �о��
	// �̷л� j=count-1�� �ؾ� ������, �����ͷ� �����ؼ� �ش� ������ �ʰ��ϸ� ������ �Ѿ ���ҵ� �����Ǿ� ����
	for(j=count-2; j>=i; j--){ 
		myArr->intArr[j+1] = myArr->intArr[j];
	}

	// 3)���� ����
	myArr->intArr[i] = key_element;

}


void insertion_sort(struct Array *myArr, int count){

	int i;

	for(i=1; i<count; i++){
		insert_by_value(myArr, myArr->intArr[i], i+1);
	}

}