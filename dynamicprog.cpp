#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100


// memozation fibonacci
//int memo[MAX];
//
//
//int fib(int n){
//	if(n <= 1){
//		return n;
//	}
//	if(memo[n] != -1){
//		return memo[n];
//	}
//	
//	memo[n] = fib(n-1) + fib(n-2);
//	return memo[n];
//}
//
//int main(){
//	int n = 10;
//	for(int i = 0 ; i < MAX ; i++){
//		memo[i] = -1;
//	}
//	printf("Fibonnaci of %d is %d", n, fibo(n));
//}




// Tabulation fibonacci


//
//int fib(int n){
//	int dp[n+1];
//	dp[0] = 0;
//	dp[1] = 1;
//	for(int i  = 0 ; i <=n ;i++){
//		dp[i] = dp[i-1] + dp[i-2];
//	}
//	return dp[n];
//}

//int main(){
//	int n = 10;
//	printf("Fibonacci of %d is %d\n", n , fib(n));
//	return 0;
//}



// Memozation Knapsack

//int memo[MAX];
//
//int coinChangeMemo(int coins[], int m, int amount){
//	if(amount == 0) return 0;
//	if(amount < 0)  return INT_MAX;
//	if(memo[amount] != -1) return memo[amount];
//	
//	int minCoins = INT_MAX;
//	for(int i = 0 ; i< m ;i++){
//		int res = coinChange(coins, m, amount - coins[i]);
//		if(res != INT_MAX && res + 1 < minCoins){
//			minCoins = res + 1;
//		}
//	}
//	memo[amount] = minCoins;
//	return minCoins;
//}
//
//int coinChangeTabu(int coins[], int m, int amount){
//	int dp[amount+1];
//	dp[0] = 0;
//	for(int i = 1 ; i<= amount ;i++){
//		dp[i] = INT_MAX;
//		for(int j = 0 ; j < m ; j++){
//			if(coins[j] <= 1 && dp[i - coins[j]] != INT_MAX){
//				dp[i] = 
//			}
//		}
//	}
//}
//
//int main(){
//	int coins[] = {1,2,5};
//	int m = sizeof(coins)/sizeof(coins[0]);
//	int amount = 11;
//	for(int i = 0 ; i < MAX ;i++){
//		memo[i] = -1;
//	}
//	int result = coinChangeMemo(coins, m, amount);
//	printf("Minimum coins needed : %d", result);
//}






// Knapasack (Memo and Tabu)
// Knapsack itu problem dimana diberikan berat dan harga, kita harus menemukan 
// harga yang maximal dengan total berat yang tidak melebihi batas yang dimiliki
// Cotnohnya saat kita mau maling rumah, harus memilih barang dengan barang yang
// harganya mahal, dan pertibmangkan tas dan beratnya untuk kabur


int memo[MAX][MAX];

int knapsackMemo(int weight[], int value[], int n, int capacity){
	if(n == 0  || capacity == 0) return 0;
	if(memo[n][capacity] != -1) return memo[n][capacity];
	
	if(weight[n-1] > capacity){
		memo[n][capacity] = knapsackMemo(weight, value, n, capacity);
	}else{
		int include = value[n-1] + knapsackMemo(weight, value, n-1, capacity - weight[n-1]);
		int exclude = knapsackMemo(weight, value, n-1, capacity);
		if(include > exclude){
			memo[n][capacity] = include;
		}else{
			memo[n][capacity] = exclude;
		}
	}
	return memo[n][capacity];
}

int knapsackTabu(int weight[], int value[], int n, int capacity){
	int dp[n+1][capacity];
	
	for(int i = 0 ; i <= n ;i++){
		for(int j = 0 ; j <= capacity ;j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}else if(weight[i-1] <= j){
				int include = values[i-1] + dp[i-1][j-weight[i-1]];
				int exclude = dp[i-1][j];
				if(include > exclude){
					dp[i][j] = include;
				}else{
					dp[i][j] = exclude;
				}
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
}

int main(){
	int weight[] = {10,20,30};
	int value[] = {60,100,120};
	int capacity = 50;
	
	int n = sizeof(value)/sizeof(value[0]);
	for(int i  = 0 ; i < MAX ;i++){
		for(int j = 0 ; j < MAX ;j++){
			memo[i][j] = -1;		
		}
	}
	int result = knapsackMemo(weight, value, n, capacity);
	printf("Maximum value : %d\n", result);
	
}
