//David Centeno
//CS 5008
//Homework #4


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100


int numbers[size];

//swap function that will switch number around
void swap(int array[], int first, int second){
	
	int temp;
	temp = array[first];
	array[first] = array[second];
	array[second] = temp; 
}

//Selection sort function
void slSort(int array[],int length){
	
	int i,j;
	int minNum;
	
	//selection sort loop
	for(i=0; i<=length-1; i++){
		minNum = i;
		//comparison logic that assigns the lesser number to minNum
		for(j=i + 1; j<=length; j++){
			if(array[j] < array[minNum])
				minNum=j;
		}		
		//swaps the memory of the numbers
		swap(array,i,minNum);
	}
}
int main(){	
	int i;
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

	printf("\n\n");
	
	//Calls selection sort
	slSort(numbers,size);
	
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

//Credits:
//To get better random numbers used srand from the example provided on https://mathbits.com/MathBits/CompSci/LibraryFunc/rand.htm
