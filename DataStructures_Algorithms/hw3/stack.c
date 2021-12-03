//David Centeno
//5008 Data Structures, Algorithims, and Apps
//Summer 2021
//Homework #3
//Stack program
//USING EXTENSION/TIME TRAVEL DAY. COMPLETE! 

#include <stdio.h>
#include <stdlib.h>

//initalizes stack and top
int stack[100];
int top = -1; 

//push function that places the int of v into the stack
int push(int v) {
	if(top >=99){
		printf("Error: Stack exceeded value\n");
		return(0);
	}
	else{
		top = top + 1;
		stack[top]=v;
		return(0);
	}
}

//pop function that removes a value from the stack
int pop(){
	if(top<0){
		printf("Error: There is no data in stack\n");
		return(0);
	}
	else{	
		printf("pop value: %d\n",stack[top]);
		top = top-1;
		return(stack[top]);
	}
}

//is empty function
int isEmpty() {
	if(top<0){
		return(0);
	}
	else{
		return(1);
	}
}	

int main(){
//testing of functions
	pop(); push(1); push(2); push(3); pop();
	push(4); push(5); pop(); pop(); push(6); pop(); pop(); 
	return(0);		
}	
