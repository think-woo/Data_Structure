//�պ�����
#include <stdio.h>
#include <stdlib.h> //malloc(), free();

void merge_sort(struct Array *myArr, int start, int end); //ó���� ���� �Ű������� ����ϴ� ����
void merge(struct Array *myArr, int left_start, int left_end, int right_start, int right_end); //���ҵ� �� ����Ʈ�� �����ϰ� �պ�

struct Array{
	int size; //�迭�� ũ��
	int count;//���� �迭�� ���� ����
	int *intArr; //�迭. �ڷ����� ����ڼ���.
};


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
	

	merge_sort(myArr,0, myArr->count-1);

	for(i=0; i<myArr->count; i++){
		printf("%d ", myArr->intArr[i]); //���: 1 2 3 4 5 6 7
	}

	free(myArr->intArr);
	free(myArr);

	return 0;
}

void merge_sort(struct Array *myArr, int start, int end){

	int mid = (start + end)/2;

	//�� �̻� ���ҵ��� �ʴ� ���
	if(start == end){
		return;
	}
	merge_sort(myArr, start, mid);
	merge_sort(myArr, mid+1, end);
	merge(myArr, start, mid, mid+1, end);

}

void merge(struct Array *myArr, int left_start, int left_end, int right_start, int right_end){

	int lptr = left_start, rptr = right_start, temp_start = 0;
	int size = (left_end - left_start + 1) + (right_end - right_start + 1); //�κ� �迭�� ũ��
	int *temp = malloc(sizeof(int) * size); //�κ� �迭 ����
	int i,j; //�ݺ���

	//�� �迭 �߿��� ���� ���� ���Ҹ� �ӽ� �迭�� ���ʴ�� ����
	while(lptr <= left_end && rptr <= right_end){
		if(myArr->intArr[lptr] < myArr->intArr[rptr]){
			temp[temp_start++] = myArr->intArr[lptr++];
		}
		else{
			temp[temp_start++] = myArr->intArr[rptr++];
		}
	}

	//�� �� �迭�� ������ ���� ������, ������ �迭�� ���Ҹ� �ӽù迭�� ���ʴ�� ����
	if(lptr > left_end){
		for(i=rptr; i<= right_end; i++){
			temp[temp_start++] = myArr->intArr[i];
		}
	}
	if(rptr > right_end){
		for(i=lptr; i<= left_end; i++){
			temp[temp_start++] = myArr->intArr[i];
		}
	}

	//�ӽù迭�� ���Ҹ� ���迭�� ����
	for(i=left_start, j=0; i<right_end, j<size; i++, j++){
		myArr->intArr[i] = temp[j];
	}

	free(temp);
}
