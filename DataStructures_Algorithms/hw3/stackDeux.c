//David Centeno
//CS5008 Data Structures, Algorithms, and Applications
//Summer 2021
//Homework #3
//Program showing the use of a stack via linked list
//USING EXTENSION/TIME TRAVEL DAY. Complete!

#include <stdio.h>
#include <stdlib.h>


//creates a struct for node
typedef struct node {
	int data;
	struct node* next;
}node;

//initialize top to NULL
node* top = NULL;

//function pushes a new node into the list
void push(int d){

	
	//establish memory for node
	struct node* newNode = ( node*)malloc(sizeof(node)); 
	//creates node with data = d
	newNode->data = d; 
	//moves node to next position
	newNode->next = top;
	//top moves to a newNode 
	top = newNode;

}

//function removes node from top of the list
int pop(){
	//initialize temp pointer to null	
	node* temp = NULL;
	
	//If top points to NULL present error
	if( top == NULL){
		printf("Error: There is no data in stack\n");
		return 0;
	}
	//Removes value from linked list
	else{
		//creates pointer to top
		temp = top;
		//prints value of top node
		printf("Pop Value: %d\n",top->data);
		//moves top to the next node
		top = top->next;
		//Sets node to NULL
		temp->next = NULL;
		//Frees memory of temp
		free(temp);
		//returns data of top node
		return top->data;
	}
}

int isEmpty(){

	if( top == NULL) {
		return 1;
	}
	else{
		return 0;
	}
}

int main() {
	//Test functions
	pop(); push(1); push(2); push(3); pop(); push(4); push(5); pop(); pop(); push(6); pop(); pop();
	return 0;
}
