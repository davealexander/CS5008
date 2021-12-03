//David Centeno
//CS 5008
//Homework #6
//Program that uses quick sort to sort out integers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100

//initializes numbers with size of 100
int numbers[size];

//compare function to compare one integer to another
int compareNum(const void *posa,const void *posb){
	const int *p1 = posa;
	const int *p2 = posb;
	return *p1 - *p2;
}

int main(){	
	int i;
	int n = sizeof(numbers) / sizeof(int);
	int counter = 1;
	srand(time(NULL));
	
	//Assigns random values to numbers array
	for(i=0; i<=size; i++){
		numbers[i] = rand() % 100;
	} 

	//Print random numbers from numbers array
	printf("Source Array: \n");
	for(i=0; i<size; i++){
		//Creates condition to print 20 numbers from array per line. 
		if(counter != 20){
			printf("%02d ",numbers[i]);
			counter++;
		}
		else{
			printf("%02d \n",numbers[i],i);
			counter= 1;
		}
	}

	//creates space between unsorted and sorted numbers
	printf("\n\n");
	
	//Calls quick sort function
	qsort(numbers, n , sizeof(int), compareNum);
	

	//Print ordered numbers from selection sort
	printf("Destination Array: \n");
	for(i=0; i<size; i++){
		//Create condition to print 20 numbers from array per line. 
		if(counter != 20){
			printf("%02d ",numbers[i]);
			counter++;
		}
		else{
			printf("%02d \n",numbers[i]);
			counter=1;
		}
	}
	
return 0;
}
