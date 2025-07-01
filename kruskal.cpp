#include <stdio.h>
#include <stdlib.h>


struct Edge{
    int source, destination, cost;
};

int compare(const void* a, const void* b){
	return ((Edge*)a)->cost - ((Edge*)b)->cost;
}


int findParent(int* listD, int idx){
	if(listD[idx] == idx){
		return idx;
	}else{
		return findParent(listD, listD[idx]);
	}
}


void unionSet(int* listD, int l1, int l2){
	listD[findParent(listD, l1)] = findParent(listD,l2);
}

void solve(Edge *edge, int v, int e){
	qsort(edge, e, sizeof(struct Edge), compare);
	int listD[v];
	for(int i = 0 ; i < v ; i++){
		listD[i] = i;
	}
	Edge result[v-1];
	int idxEdgeProb = 0;
	int idxResult = 0;
	
	while(idxResult < v-1){
		Edge curr = edge[idxEdgeProb];
		idxEdgeProb++;
		
		int p1 = findParent(listD, curr.source);
		int p2 = findParent(listD, curr.destination);
		
		if(p1 != p2){
			result[idxResult] = curr;
			idxResult++;
			unionSet(listD, p1, p2);
		}
		
		
	}
	
	for(int i = 0 ; i < v-1 ; i++){
		Edge curr = result[i];
		printf("%d - %d = %d\n", curr.source, curr.destination, curr.cost);

	}
	
	
}

int main(){
	
	int e = 8;
	int v = 5;
	
	Edge edge[e];
	
	edge[0] = (Edge){0,1,7};
	edge[1] = (Edge){0,2,4};
	edge[2] = (Edge){
		0,4,5
	};
	edge[3] = (Edge){
		1,4,4
	};
	edge[4] = (Edge){
		1,3,2
	};
	edge[5] = (Edge){
		2,3,5
	};
	edge[6] = (Edge){
		2,4,3
	};
	edge[7] = (Edge){
		3,4,3
	};
	solve(edge, v, e);
	
	
}
