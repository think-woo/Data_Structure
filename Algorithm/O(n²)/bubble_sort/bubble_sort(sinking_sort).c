#include <stdio.h>

void bubble_sort(int arr[], int count);

int main(){
    
	int arr[10] = {4,9,2,6,7,1,10,8,3,5};
	int i;
	
	bubble_sort(arr, sizeof(arr)/sizeof(int));

	for(i=0; i<sizeof(arr)/sizeof(int); i++){
		printf("%d ", arr[i]);
	}

    return 0;
}

void bubble_sort(int arr[], int count){

	int i, j;
	int temp; //임시변수

	for(i=0; i<count; i++){
		for(j=0; j<(count-1)-i; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
}