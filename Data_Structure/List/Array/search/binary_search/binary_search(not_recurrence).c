#include <stdio.h>

int binary_search(int arr[], int size, int element);

int main(){

	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int iFindValue; //찾으려는 값
	int iResult; //결과

	printf("찾으려는 원소를 입력하시오: ");
	scanf("%d", &iFindValue);

	iResult = binary_search(arr,sizeof(arr)/sizeof(int), iFindValue);
	if(iResult != -1){
		printf("원소%d는 %d번 째 인덱스에 있습니다", iFindValue, iResult);
	}
	else{
		printf("찾는 원소가 없습니다\n");
	}

	return 0;
}

int binary_search(int arr[], int size, int element){

	int s = 0;
	int e = size-1;
	int mid;

	while(s<=e){

		mid = (s+e)/2;

		if(arr[mid]>element){
			e= mid-1;
		}
		else if(arr[mid]<element){
			s = mid+1;
		}
		else{
			return mid;
		}
	}

	return -1;

}