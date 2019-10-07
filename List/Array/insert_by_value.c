#include <stdio.h>

void inset_by_value(int arr[], int value);

int main(){

	int arr[10] = {1,2,3,6,7,10,11};
	int value;//넣을값
	int i;

	printf("삽입할 값 입력: ");
	scanf("%d", &value);

	inset_by_value(arr, value);

	for(i=0; i<10; i++){
		printf("%d ", arr[i]);
	}

	return 0;
}

void inset_by_value(int arr[], int value){

	int i, j;

	for(i=0; i<7; i++){
		if(arr[i] > value){
			break;
		}// 
	}//1.값을 넣은 인덱스 찾기

	for(j=7-1;j>=i; j--){
		arr[j+1] = arr[j];
	}//2.기존값 옮겨서 공간 확보

	arr[i] = value; //3. 값 삽입
}
