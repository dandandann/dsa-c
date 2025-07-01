#include<stdio.h>
#define MAX 100

int arr[MAX];

int fibo(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(arr[n] != -1) return arr[n];
	
	return arr[n] = fibo(n-1) + fibo(n-2);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0 ; i < MAX ; i++){
		arr[i] = -1;
	}
	printf("%d", fibo(n));
	return 0;
}
