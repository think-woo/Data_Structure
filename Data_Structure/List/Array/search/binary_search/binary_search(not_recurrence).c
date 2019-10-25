#include <stdio.h>

int binary_search(int arr[], int size, int element);

int main(){

	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int iFindValue; //ã������ ��
	int iResult; //���

	printf("ã������ ���Ҹ� �Է��Ͻÿ�: ");
	scanf("%d", &iFindValue);

	iResult = binary_search(arr,sizeof(arr)/sizeof(int), iFindValue);
	if(iResult != -1){
		printf("����%d�� %d�� ° �ε����� �ֽ��ϴ�", iFindValue, iResult);
	}
	else{
		printf("ã�� ���Ұ� �����ϴ�\n");
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