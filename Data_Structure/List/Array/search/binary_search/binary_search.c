#include <stdio.h>

int binary_search(int arr[], int s, int e, int element);

int main(){

	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int iFindValue; //찾으려는 값
	int iResult; //결과

	printf("찾으려는 원소를 입력하시오: ");
	scanf("%d", &iFindValue);

	iResult = binary_search(arr, 0, 9, iFindValue);
	if(iResult != -1){
		printf("원소%d는 %d번 째 인덱스에 있습니다", iFindValue, iResult);
	}
	else{
		printf("찾는 원소가 없습니다\n");
	}

	return 0;
}

int binary_search(int arr[], int s, int e, int element){

	int mid = (s+e)/2;

	if(s == e){
		return (arr[s] == element) ? s : -1;
	}//더 이상 분할이 되지 않는다(재귀의끝)

	if(arr[mid] == element){
		return mid;
	}
	else if(arr[mid] > element){
		return binary_search(arr, s, mid-1, element);
	} //중간값보다 찾는 원소가 작을 때
	else{
		return binary_search(arr, mid+1, e, element);
	} //중간값보다 찾는 원소가 클 때

	

}