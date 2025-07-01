#include <stdio.h>


// MIN AND MAX HEAP

int arr[100];
int size = 0;


void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int getParent(int position){
	return position/2;
}

int getLeftChild(int position){
	return position * 2;
}

int getRightChild(int position){
	return position * 2 + 1;
}

void insertMin(int value){
	size++;
	arr[size] = value;
	
	int currentIndex = size;
	
	while(currentIndex > 1 && arr[currentIndex] < arr[getParent(currentIndex)]){
		swap(&arr[currentIndex], &arr[getParent(currentIndex)]);
		currentIndex = getParent(currentIndex);
	}
	
}

void insertMax(int value){
	size++;
	arr[size] = value;
	int currentIndex = size;
	while(currentIndex > 1 && arr[currentIndex] > arr[getParent(currentIndex)]){
		swap(&arr[currentIndex], &arr[getParent(currentIndex)]);
		currentIndex = getParent(currentIndex);
	}
}

void heapifyMin(int pos){
	int least = pos;
	int leftChild = getLeftChild(pos);
	int rightChild = getRightChild(pos);
	
	if(leftChild <= size && arr[leftChild] < arr[least]){
		least = leftChild;
	}
	
	if(rightChild <= size && arr[rightChild] < arr[least]){
		least = rightChild;
	}
	
	if(least != pos){
		swap(&arr[least], &arr[pos]);
		heapifyMin(least);
	}
}

void heapifyMax(int pos){
	int max = pos;
	int leftChild = getLeftChild(pos);
	int rightChild = getRightChild(pos);
	if(arr[leftChild] > arr[max]){
		max = leftChild;
	}
	
	if(arr[rightChild] > arr[max]){
		max = rightChild;
	}
	
	if(max != pos){
		swap(&arr[max], &arr[pos]);
		heapifyMax(max);
	}
	
}

void deleteHeapMax(){
	arr[1] = arr[size];
	size--;
	heapifyMax(1);
}

void deleteHeapMin(){
	arr[1] = arr[size];
	size--;
	heapifyMin(1);
}

void print(){
	for(int i = 1 ; i <= size ; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void printTree(int index, int level){
    if(index > size) return;

    int right = getRightChild(index);
    int left = getLeftChild(index);
    
    printTree(right, level + 1);

    for(int i = 0; i < level; i++) printf("    ");
    printf("%d\n", arr[index]);

    printTree(left, level + 1);
}

void printHeapAsTree(){
    printTree(1, 0);
    printf("\n");
}


int main(){

	insertMax(1);
	insertMax(100);
	insertMax(20);
	insertMax(3000);
	insertMax(32);
	print();
	
//	printf("MIN =======================\n");
//	insertMin(100);
//	insertMin(90);
//	insertMin(80);
//	insertMin(120);
//	
//	printHeapAsTree();
//	
//	deleteHeapMin();
//	printHeapAsTree();
//	
//	printf("MAX ====================\n");
//	
//	insertMax(20);
//	insertMax(100);
//	insertMax(400);
//	insertMax(10);
////	print();
//printHeapAsTree();
//	
//	deleteHeapMax();
//
////	print();
//	printHeapAsTree();

	return 0;
}
