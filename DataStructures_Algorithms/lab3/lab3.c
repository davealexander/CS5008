/*David Centeno
CS 5008 Data Structures, Algorithms, and Apps
Summer 2021
Lab is to show a program that can take a users input, transform string to all upper case, provide only unique characters 
and its hex value of character, and exit program by typing quit
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;
int j;
char input[256];

int main (){

  while(1){
	
	//print statement asking for user input
	printf("Input a string (Quit for done):");
	
	//takes in users input and stores to input array
	fgets(input, sizeof(input), stdin);

	
	//for loop that makes all lowercase uppercase
	for(i=0; i<strlen(input); i++) {
		if(('a' <= input[i]) && (input[i] <= 'z')) {	
			input[i] = input[i]-0x20;
		}
	}
	
	//conditional statement that breaks out of program
	if(strcmp(input,"QUIT\n") == 0){
		break;
	}	

	//prints out original string in all caps
	printf("Uppercase Input: %s",input);

	//idea for unique character loop
	for(i=0; i<strlen(input); i++) {
		int encountered = 0;
		
		//another for loop that will compare the input[i] to input[j]
		for(j=0; j<(i); j++){
			if(input[i] == input[j]){
				encountered = 1;
				break;
			}
		}
		if(encountered == 0){
			if( input[i] == '\n'){
				printf("\\n -- 0x%x\n", input[i]);
			}
			else{
			printf(" %c -- 0x%x\n", input[i], input[i]);
			}
		}
	}
		
 }
return 0; 
}
//Received assistance from Evan(TA) on working out logic of comparison string and fixing quit conditional 
