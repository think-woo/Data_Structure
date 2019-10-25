#include <stdio.h>

void delete_by_value(int arr[], int value);

int main(){

	int arr[10] = {1,2,3,6,7,10,11};
	int value;//삭제값
	int i;

	printf("삭제할 값 입력: ");
	scanf("%d", &value);
	delete_by_value(arr, value);

	for(i=0; i<10; i++){
		printf("%d ", arr[i]);
	}

	return 0;
}

void delete_by_value(int arr[], int value){

	int i, j;

	for(i=0; i<7; i++){
		if(arr[i] == value){
			break;
		}// 
	}//1.삭제할 값의 인덱스 찾기

	for(j=i; j<7-1; j++){
		arr[j] = arr[j+1];
	}//2.기존값 옮겨서 공간 축소

	arr[7-1] = 0; //3. 배열크기 감소
}
