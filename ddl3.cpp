#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char name[101];
	int age;
	Node *next, *prev;	
}*tail, *head;

struct Node* createNode(char *name, int age){
	struct Node* newNode = (Node *)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	newNode->age = age;
	newNode->next = newNode->prev = NULL;
	return newNode;
}

struct Node* pushHead(char *name, int age){
	struct Node* newNode = createNode(name, age);
	if(!head){
		head = tail = newNode;
		return newNode;
	}
	
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}

struct Node* pushTail(char *name, int age){
	struct Node* newNode = createNode(name, age);
	if(!head){
		head = tail = newNode;
		return newNode;
	}
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
}

struct Node* pushMid(char *name, int age){
	struct Node* newNode = createNode(name, age);
	if(!head){
		head = tail = newNode;
		return newNode;
	}
	
	if(newNode->age < head->age){
		pushHead(name, age);
	}else if(newNode->age > tail->age){
		pushTail(name, age);
	}else{
		struct Node* temp = head;
		while(temp->next->age < newNode->age){
			temp = temp->next;
		}
		temp->next->prev = newNode;
		newNode->next = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
	}
}

void popHead(){
	if(!head){
		printf("Nothing to pop\n");
		return;
	}
	
	struct Node* temp = head;
	if(head == tail){
		head = tail = NULL;
	}else{
		head = head->next;
		head->prev = NULL;
	}
	free(temp);
}

void popTail(){
	if(!head){
		printf("Nothing to pop\n");
		return;
	}
	
	struct Node* temp = tail;
	if(head == tail){
		head = tail = NULL;
	}else{
		tail = tail->prev;
		tail->next = NULL;
	}
	free(temp);
}

void popAll(){
	struct Node* curr = head;
	while(curr){
		popHead();
		curr = curr->next;
	}

}

struct Node* searchNode(int age){
	struct Node* curr = head;
	while(curr){
		if(curr->age == age){
			return curr;
		}
		curr = curr->next;
	}
	return NULL;
}

struct Node* popByValue(int age){
	struct Node* searched = searchNode(age);
	if(searched->age < head->age){
		popHead();
	}else if(searched->age > tail->age){
		popTail();
	}else{
		searched->next->prev = searched->prev;
		searched->prev->next = searched->next;
		free(searched);
	}
}

void printAll(){
	struct Node* curr = head;
	if(!curr){
		printf("Empty");
		return;
	}
	while(curr){
		printf("Name : %s, Age: %d -> ", curr->name, curr->age);
		curr = curr->next;
	}
	printf("\n");
}

int main(){
	pushHead("Jordan", 23);
	pushTail("Toni", 40);
	pushHead("Ivan", 17);
	pushHead("Ian", 14);
	pushTail("Yuan", 50);
	pushMid("Guan", 30);
	
//	popHead();
//	popTail();
//	popAll();
	popByValue(30);
	printAll();
}

