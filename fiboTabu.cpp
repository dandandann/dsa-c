#include <stdio.h>
#define MAX 100
int fibo(int n){
	int dp[MAX];
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2 ; i < MAX ; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", fibo(n));
}
