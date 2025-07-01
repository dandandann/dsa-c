#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char nama[20];
    int jumlahMahasiswa;
    int visited;
    struct Node *atas, *bawah, *kanan, *kiri;
} *root;

// Function to create a new node
struct Node* createNode(char nama[], int jumlahMahasiswa) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->nama, nama);
    newNode->jumlahMahasiswa = jumlahMahasiswa;
    newNode->visited = 0;
    newNode->atas = newNode->bawah = newNode->kanan = newNode->kiri = NULL;
    return newNode;
}

// Functions to add nodes in each direction
void pushBawah(struct Node *curr, char nama[], int jumlahMahasiswa) {
    if (curr->bawah) {
        printf("Ada kampus di bawah %s\n", curr->nama);
    } else {
        struct Node* newNode = createNode(nama, jumlahMahasiswa);
        newNode->atas = curr;
        curr->bawah = newNode;
    }
}

void pushAtas(struct Node *curr, char nama[], int jumlahMahasiswa) {
    if (curr->atas) {
        printf("Ada kampus di atas %s\n", curr->nama);
    } else {
        struct Node* newNode = createNode(nama, jumlahMahasiswa);
        newNode->bawah = curr;
        curr->atas = newNode;
    }
}

void pushKiri(struct Node *curr, char nama[], int jumlahMahasiswa) {
    if (curr->kiri) {
        printf("Ada kampus di kiri %s\n", curr->nama);
    } else {
        struct Node* newNode = createNode(nama, jumlahMahasiswa);
        newNode->kanan = curr;
        curr->kiri = newNode;
    }
}

void pushKanan(struct Node *curr, char nama[], int jumlahMahasiswa) {
    if (curr->kanan) {
        printf("Ada kampus di kanan %s\n", curr->nama);
    } else {
        struct Node* newNode = createNode(nama, jumlahMahasiswa);
        newNode->kiri = curr;
        curr->kanan = newNode;
    }
}

// Function to view the campus map
void viewAll(struct Node *curr, int level, int maxLevel) {
   if(level == 0) printf("City: ");
	else if(curr == NULL)
	{
		printf("-\n");
		return;
	}
	printf("%s (%d )\n", curr->nama, curr->jumlahMahasiswa);
	if(curr->visited == 1 || level > maxLevel)
		return;
		
	curr->visited = 1;
	
	for(int i = 0; i <= level; i++) printf("   ");
	printf("North / Atas: ");
	viewAll(curr->atas, level+1, maxLevel);
	for(int i = 0; i <= level; i++) printf("   ");
	printf("East / Kanan: ");
	viewAll(curr->kanan, level+1, maxLevel);
	for(int i = 0; i <= level; i++) printf("   ");
	printf("South / Bawah : ");
	viewAll(curr->bawah, level+1, maxLevel);
	for(int i = 0; i <= level; i++) printf("   ");
	printf("West / Kiri: ");
	viewAll(curr->kiri, level+1, maxLevel);
}

// Function to reset visited status
void resetVisited(struct Node *curr) {
    if (!curr || !curr->visited) return;
    curr->visited = 0;
    resetVisited(curr->atas);
    resetVisited(curr->bawah);
    resetVisited(curr->kiri);
    resetVisited(curr->kanan);
}

int main() {
    root = createNode("Binus Anggrek", 1000);
    pushBawah(root, "Binus Syahdan", 500);

    pushAtas(root, "Kantin Payung", 10);
    pushKanan(root, "Family Mart", 20);

	pushKiri(root->bawah, "Binus Kijang", 200);
	viewAll(root, 0 ,1);
    return 0;
}

