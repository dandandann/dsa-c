#include <stdio.h>
#include  <stdlib.h>

int coinChange(int *arr, int *coins, int banyakCoin, int n ){
	arr[0] = 0;
	for(int i = 1 ; i <= n ; i++){
		arr[i] = INT_MAX;
	}
	
	for(int i = 0 ; i < banyakCoin ; i++){
		
		for(int j = coins[i] ; j <= n ; j++){
			// Cek kombinasi koin
			int val = arr[j - coins[i]];
			
			if(val != INT_MAX && val + 1 < arr[j]){
				arr[j] = val + 1;
			}
			
		}
		
		
	}
	
	if(arr[n] == INT_MAX ) return -1;
	
	return arr[n];
	
	
}


int main(){
	int coins[] = {1,2,5};
	int price = 6;
	int arr[100];
	
	int result = coinChange(arr, coins, 3, price); 
	
	printf("Minimum coins needed : %d\n", result);
	return 0;
}
