#include <stdio.h>


void mergesort(int arr[], int left, int mid, int right){
	// buat 2 temp arr dengan size yang udah di split
	int sizeLeft = mid-left + 1;
	int sizeRight = right - mid;
	
	int arrLeft[sizeLeft];
	int arrRight[sizeRight];
	
  // Copy data ke subarray kiri dan kanan
    for (int i = 0; i < sizeLeft; i++) {
        arrLeft[i] = arr[left + i];
    }
    for (int i = 0; i < sizeRight; i++) {
        arrRight[i] = arr[mid + i + 1];
    }

    // Merge dua subarray kembali ke array utama
    int currLeft = 0, currRight = 0, currNum = left;
    while (currLeft < sizeLeft && currRight < sizeRight) {
        if (arrLeft[currLeft] <= arrRight[currRight]) {
            arr[currNum] = arrLeft[currLeft];
            currLeft++;
        } else {
            arr[currNum] = arrRight[currRight];
            currRight++;
        }
        currNum++;
    }

    // Copy sisa elemen dari arrLeft jika ada
    while (currLeft < sizeLeft) {
        arr[currNum] = arrLeft[currLeft];
        currLeft++;
        currNum++;
    }

    // Copy sisa elemen dari arrRight jika ada
    while (currRight < sizeRight) {
        arr[currNum] = arrRight[currRight];
        currRight++;
        currNum++;
    }
}

void merge(int arr[], int left, int right){
	if (left >= right) return;
	int mid = (left+right)/2;
	
	// 2 rekursi untuk membagi arr dari paling kiri - mid
	// dan satu lagi dari mid + 1 sampai paling kanan
	merge(arr,left, mid);
	merge(arr, mid + 1, right);
	
	mergesort(arr, left, mid, right);
}

void print(int arr[], int size){
	for(int i = 0 ; i < size ; i++){
		printf("%d ", arr[i]);
	}
	
	printf("\n");
}

void binarySearch(int arr[], int search, int size){
	int left = 0;
	int right = size-1;
	
	while(left <= right){
		int mid = (left+right)/2;
		
		if(arr[mid] == search){
			printf("Found %d at index %d!", search, mid);
			return;
			
			//  3  5
		}else if(arr[mid] < search){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
}

int main(){
	int arr[] = {401,32,199,501,222,10,2,3,919};
	int size = sizeof(arr)/sizeof(arr[0]); // utk mengetahui size arr kita
	// dalam arr, byte yg didapat adalah 4 * 9 = 36
	// maka 36/4 = 9
	merge(arr, 0, size-1); // sesuai parameter, left n right
	print(arr, size);
	binarySearch(arr, 501, size);
}
