#include <stdio.h>

int linear_search();

int main(){

	int arr[10] = {9,2,4,5,1,8,10,3,7,6};
	int iFindElement; //���� �Է�
	int iResult; //�Լ� ���

	printf("ã�� ���� �Է�: ");
	scanf("%d", &iFindElement);

	iResult = linear_search(arr, sizeof(arr)/sizeof(int),iFindElement);
	if(iResult != -1){
		printf("%d�� �ε����� %d", iFindElement, iResult);
	}
	else{
		printf("���Ұ� �����ϴ�\n");
	}

	return 0;
}

int linear_search(int arr[],int size, int elemnt){

	int i;

	for(i=0; i<size; i++){
		if(arr[i] == elemnt){
			return i; //���� ����
		}//if
	}//for

	return -1; //���� ����
}