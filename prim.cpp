#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define v 5

    //   2    3
    // (0)--(1)--(2)
    //  |   / \   |
    //  6  8   5  7
    //  | /     \ |
    // (3)-------(4)
    //      9
int graph[v][v] = {
	{0, 2, 0, 6, 0}, // 0
	{2, 0, 3, 8, 5}, // 1
	{0, 3, 0, 0, 7}, // 2
	{6, 8, 0, 0, 9}, // 3
	{0, 5, 7, 9, 0}, // 4
};

int findMin(int cost[v], bool set[v]){
	int minimum = INT_MAX;
	int index;
	
	for(int i = 0 ; i < v ; i++){
		if(minimum > cost[i] && !set[i]){
			minimum = cost[i];
			index = i;
		}
	}
	return index;
}


void printAll(int parent[]){
	for(int i = 1 ; i < v ;i++){
		printf("%d - %d -> %d\n", parent[i], i,  graph[i][parent[i]]);
	}
}

void solve(){
	int parent[v];
	int cost[v];
	bool set[v];
	for(int i = 0 ; i < v ;i++){
		cost[i] = INT_MAX;
		set[i] = false;
	}
	
	int start = 0;
	parent[start] = -1;
	cost[start] = 0;
	for(int i = 0 ; i < v-1 ;i++){
		int min = findMin(cost, set);
		set[i] = true;
		
		for(int j = 0 ; j < v ; j++){
			if(graph[min][j] && !set[j] && graph[min][j] < cost[j]){
				parent[j] = min;
				cost[j] = graph[min][j];
				
			}
		}
	
	}
	printAll(parent);
}


int main(){
	solve();
	
	return 0;
}
