#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <windows.h>
#include <math.h>


using namespace std;

#define LENGTH 10
#define WIDTH 18
int count = 0;


struct Position{
	int x, y;
	
};

struct Map{
	char value;
	Position pos;
	int cost;
	double heu;
	bool visited;
	struct Map* before;
};

// Kalau Djikstra, di struct compare tinggal hapus heunya, biar nilai heuristicnya 
// gak jadi patokan di priority queue


struct Compare{
	bool operator()(Map *a, Map *b){
		return (a->cost + a->heu) > (b->cost + b->heu);
	}
};
char mapChar[LENGTH][WIDTH] = {
	"#################",
	"#E              #",
	"#               #",
	"#               #",
	"###  ##  ####   #",
	"#               #",
	"#### ###      ###",
	"####   ###    ###",
	"####           S#",
	"#################",
};


struct Map dMap[LENGTH][WIDTH];
struct Position startPos, endPos;


void init(){
	for(int i = 0 ; i < LENGTH ; i++){
		for(int j = 0 ; j < WIDTH ; j++){
			char curr = mapChar[i][j];
			Position currPos;
			currPos.x = j;
			currPos.y = i;
			
			if(curr == 'E') endPos = currPos;
			if(curr == 'S') startPos = currPos;
			
			dMap[i][j].before = NULL;
			dMap[i][j].cost = INT_MAX;
			dMap[i][j].pos = currPos;
			dMap[i][j].value = curr;
			dMap[i][j].heu = sqrt(pow(j - endPos.x, 2) + pow(i - endPos.y , 2));
			dMap[i][j].visited = false;
		}
	}
	dMap[startPos.y][startPos.x].cost = 0;
}

void printMap(){
	for(int i = 0 ; i < LENGTH ;i++){
		for(int j = 0 ; j < WIDTH ; j++){
			printf("%c", dMap[i][j].value);
		}
		printf("\n");
	}
}

int dirX[4] = {1,-1,0,0};
int dirY[4] = {0,0,-1,1};

void djikstra(){
	priority_queue<Map *, vector<Map *>, Compare> listMap;
	listMap.push(&dMap[startPos.y][startPos.x]);
	Map *currMap;
	while(!listMap.empty()){
		currMap = listMap.top();
		listMap.pop();
		
		if(currMap->value == 'E') break;
		currMap->visited = true;
		
		for(int i = 0 ; i < 4 ;i++){
			int newX = currMap->pos.x + dirX[i];
			int newY = currMap->pos.y + dirY[i];
			
			Map* newMap = &dMap[newY][newX];
			
			if(newMap->value == '#' || newMap->visited) continue;
			
			int newCost = currMap->cost;
			if(newCost < newMap->cost){
				newMap->cost = newCost;
				newMap->before = currMap;
				listMap.push(newMap);
			}
						currMap->value = '*';
			system("cls");
			printMap();
			Sleep(50);
					
		}	
	}
	
	while(currMap){
		if(currMap->value != 'S' || currMap->value != 'E'){
			currMap->value = 'O';
			system("cls");
			printMap();
			count++;
			printf("Count = %d", count);
			Sleep(50);
		}
		currMap = currMap->before;
	}
}

int main(){
	init();
//	printMap();
	djikstra();
	
	return 0;
}
