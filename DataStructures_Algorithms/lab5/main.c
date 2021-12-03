#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab5.h"
#define size 255
char input[size];

int pop(int x){
	//removes element from array
	input[x]--;
	
}


int main() {
	while(1){
	int i;
	
	//Ask for user input
	printf("Input a string between 0 and 255 characters: \n");
	
	//take user input and store into queue
	fgets(input, sizeof(input), stdin);	
	
	//stops reading \n in code
	input[strcspn(input, "\n")] = 0;
	
	//makes all characters lower case
	for(i=0;i<strlen(input);i++){
		if(('a' <= input[i]) && (input[i] <= 'z')) {	
			input[i] = input[i]-0x20;
		}
	}
	//checks for punctuation or spaces and shifts 
	for(i=0; i<strlen(input); i++){
		if(ispunct(input[i]) || isspace(input[i])){
			pop(i);
					
		}
	}		
	
	is_palindrome(input);

	}		
return 0;
}
