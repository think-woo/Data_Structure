#include <stdio.h>

int linear_search();

int main(){

	int arr[10] = {9,2,4,5,1,8,10,3,7,6};
	int iFindElement; //원소 입력
	int iResult; //함수 결과

	printf("찾는 원소 입력: ");
	scanf("%d", &iFindElement);

	iResult = linear_search(arr, sizeof(arr)/sizeof(int),iFindElement);
	if(iResult != -1){
		printf("%d의 인덱스는 %d", iFindElement, iResult);
	}
	else{
		printf("원소가 없습니다\n");
	}

	return 0;
}

int linear_search(int arr[],int size, int elemnt){

	int i;

	for(i=0; i<size; i++){
		if(arr[i] == elemnt){
			return i; //원소 존재
		}//if
	}//for

	return -1; //원소 없음
}