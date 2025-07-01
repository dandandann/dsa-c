#include <string.h>
#include <stdio.h>

// K napsack 0.1

int knapSack(int capacity, int* weight, int* value, int n){
	int arr[n+5][capacity+5];
	
	for(int i = 0 ; i <= n ; i ++){
		
		for(int j = 0 ; j <= capacity ; j++){
			
			if(i==0 || j == 0){
				arr[i][j] = 0;
			}
			else if(weight[i-1] <= j){
				arr[i][j] = (value[i-1] + arr[i-1][j-weight[i-1]] > arr[i-1][j]) ?
							 value[i-1] + arr[i-1][j-weight[i-1]] : arr[i-1][j];
			}
			else{
				arr[i][j] = arr[i-1][j];
			}
			
		}
	}
	return arr[n][capacity];
};



int main(){
	int weight[3] = {2,3,5};
	int value[3] = {10,15,20};
	int result = knapSack(5, weight, value, 3);
	printf("Result = %d", result);
}

