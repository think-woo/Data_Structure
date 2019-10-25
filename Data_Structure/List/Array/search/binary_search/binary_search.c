#include <stdio.h>

int binary_search(int arr[], int s, int e, int element);

int main(){

	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int iFindValue; //ã������ ��
	int iResult; //���

	printf("ã������ ���Ҹ� �Է��Ͻÿ�: ");
	scanf("%d", &iFindValue);

	iResult = binary_search(arr, 0, 9, iFindValue);
	if(iResult != -1){
		printf("����%d�� %d�� ° �ε����� �ֽ��ϴ�", iFindValue, iResult);
	}
	else{
		printf("ã�� ���Ұ� �����ϴ�\n");
	}

	return 0;
}

int binary_search(int arr[], int s, int e, int element){

	int mid = (s+e)/2;

	if(s == e){
		return (arr[s] == element) ? s : -1;
	}//�� �̻� ������ ���� �ʴ´�(����ǳ�)

	if(arr[mid] == element){
		return mid;
	}
	else if(arr[mid] > element){
		return binary_search(arr, s, mid-1, element);
	} //�߰������� ã�� ���Ұ� ���� ��
	else{
		return binary_search(arr, mid+1, e, element);
	} //�߰������� ã�� ���Ұ� Ŭ ��

	

}