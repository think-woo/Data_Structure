#include <stdio.h>
#include <stdlib.h> //qsort()

int compare(const void *a, const void *b);

int main(){

	int arr[10] = {4,2,1,9,7,5,10,8,3,6};
	int i;

	// ������ �迭, ��� ����, ��� ũ��, �� �Լ��� �־���
	qsort(arr, sizeof(arr)/sizeof(int), sizeof(int), compare);

	for(i=0; i<sizeof(arr)/sizeof(int); i++){
		printf("%d ", arr[i]);
	}

	return 0;
}

int compare(const void *a, const void *b){ //��������

	int num1 = *(int*)a; // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int*)b;

	if(num1 > num2){
		return 1;
	}

	if(num1 < num2){
		return -1;
	}

	return 0; //num1 == num2
}

//���ó���: https://dojang.io/mod/page/view.php?id=638