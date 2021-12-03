//David Centeno
//Comparing Algorithmic Codes

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#define MAX 100000

int array[MAX];
int array2[MAX];
int array3[MAX];
int array4[MAX];
int array5[MAX];

//insertion sort Algorithm
void insertionSort(int array[], int size){
	int i;	

	//insertion sort algorithm
	for(i = 1; i < size; i++){
		int key = array[i];
		
		int j = i-1;
		
		while(key < array[j] && j >=0){
			array[j + 1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}

//Shell sort Algorithm
void shellSort(int intArray[], int interval){
	int inner, outer;
	int valueToInsert;
	int elements = MAX;
	int i = 0;
	
	while(interval > 0) {

		//printf("Beginning interval = %d\n",interval);
		for(outer = interval; outer < elements; outer++) {
			valueToInsert = intArray[outer];
			inner = outer;
			while(inner > interval -1 && intArray[inner-interval] >= valueToInsert){
				intArray[inner] = intArray[inner - interval];
				inner -= interval;
			}
			intArray[inner] = valueToInsert;
		}
		interval--;
		//printf("End interval = %d\n",interval);
	}
}

//Shell sort Algorithm that takes array as second parameter
void shellSort2(int intArray[],int interval[]){
        int inner, outer;
        int valueToInsert;
        int elements = MAX;
        int i = log(MAX);	

        while(interval[i] > 0) {

                //printf("Beginning interval = %d\n",interval[i]);
                for(outer = interval[i]; outer < elements; outer++) {
                        valueToInsert = intArray[outer];
                        inner = outer;
                        while(inner > interval[i] -1 && intArray[inner-interval[i]] >= valueToInsert){
                                intArray[inner] = intArray[inner - interval[i]];
                                inner -= interval[i];
                        }
                        intArray[inner] = valueToInsert;
                }
		i--;
                //printf("End interval = %d\n",interval[i]);
        } 
}

//Shell sort Algorithm that takes array as second parameter
void shellSort3(int intArray[], int interval[]){
        int inner, outer;
        int valueToInsert;
        int elements = MAX;
        int i = MAX;

        while(interval[i] > 0) {

                //printf("Beginning interval = %d\n",interval[i]);
                for(outer = interval[i]; outer < elements; outer++) {
                        valueToInsert = intArray[outer];
                        inner = outer;
                        while(inner > interval[i] -1 && intArray[inner-interval[i]] >= valueToInsert){
                                intArray[inner] = intArray[inner - interval[i]];
                                inner -= interval[i];
                        }
                        intArray[inner] = valueToInsert;
                }
                i--;
                //printf("End interval = %d\n",interval[i]);
        }
}

int main() {
	int i;
	int count = MAX;
	int algArray[MAX];
	int algArray2[MAX];
	int algArray3[MAX];
	
	//Initiate Random Numbers
	for(i=0; i<count; i++){
                array[i] = (rand() % 1024000)+1;
                array2[i] = (rand() % 1024000)+1;
                array3[i] = (rand() % 1024000)+1;
                array4[i] = (rand() % 1024000)+1;
                array5[i] = (rand() % 1024000)+1;
        };	

	int size = sizeof(array) / sizeof(array[0]);
	

	//INTERVALS FOR ALGORITHMS

	//interval 1 1.72 * n^1/3
        int interval1 = floor(1.72*cbrt(size));	
	
	//intveral 2 2^i-1 | 1<= i <= |logn|
        for(i=0; i<=log(MAX); i++){
                algArray[i]= pow(2,i)-1;
        }
	//intveral 3 2^i | 0<= i <= |logn|
        for(i=0; i<=log(size); i++){
                algArray2[i]= pow(2,i);
        }
	
	//interval 4 3^i -1 / 2 | 1<= i <= t (Where t is the smallest integer such that 3^(t+2) - 1 / 2 >= N)
        int t = (log(2*MAX+1) / log(3))-2;
        for(i=0; i<=t; i++){
                algArray3[i]= pow(3,i) - 1 / 2;
        }


	//SORTING ALGORITHMS
	
	printf("Sort 100000 Numbers\n");
	
	//insertion sort
	clock_t begin = clock();
	insertionSort(array,size);
	clock_t end = clock();
	double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
	printf("Insertion Sort Time Spent: %f\n", time_spent);
		

	//shell sort
	clock_t begin2 = clock();
	shellSort(array2, interval1);
	clock_t end2 = clock();
	double time_spent2 = (double)(end2-begin2) / CLOCKS_PER_SEC;
	printf("Shell Sort (interval 1) Time Spent: %f\n",time_spent2);

	//shell sort2
	clock_t begin3 = clock();
	shellSort2(array3, algArray);
	clock_t end3 = clock();
        double time_spent3 = (double) (end3-begin3) / CLOCKS_PER_SEC;
        printf("Shell Sort (interval 2) Time Spent: %f\n",time_spent3);

	//shell sort3
	clock_t begin4 = clock();
	shellSort2(array4,algArray2);
	clock_t end4 = clock();
        double time_spent4 = (double) (end4-begin4) / CLOCKS_PER_SEC;
        printf("Shell Sort (interval 3) Time Spent: %f\n",time_spent4);

	//shell sort4 (NOT WORKING DUE TO INTERVAL
	clock_t begin5 = clock();
	shellSort3(array5, algArray3);
	clock_t end5 = clock();
        double time_spent5 = (double) (end5-begin5) / CLOCKS_PER_SEC;
        printf("Shell Sort (interval 4) Time Spent: %f\n",time_spent5);

	
return 0;
}

