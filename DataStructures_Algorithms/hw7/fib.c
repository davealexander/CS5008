#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// max number of inputs
#define MAX_FIB 200

// result of call to fib function
unsigned long long result;

//loop variable
int i;
//loop variable for initMemo
int j;

// ========================== MEMO DEFINITIONS ==========================

unsigned long long memo[MAX_FIB];     // array to hold computed data values
bool valid[MAX_FIB];                  // array to hold validity of data

// make all entries in the memoization table invalid
void initMemo() {
  // ***** ADD YOUR INITIALIZATION CODE HERE *****
  //Loop for setting values to 0 and setting valid to false
  for(j =0; j<sizeof(valid); j++){
	memo[j] = 0;
	valid[j] = false; 
}
  return;
}

// ========================== TIME DEFINITIONS ==========================
// timer functions found in time.h
// time_t is time type
time_t startTime;
time_t stopTime;

// get current time in seconds from some magic date with
// t = time(NULL);
// or
// time(&t);
// where t is of type time_t
//
// get difference in secs between times (t1-t2) with
// d = difftime(t1, t2);
// where d is of type double

// ========================== NAIVE FIB  ==========================

unsigned long long fib(int n) {
if (n < 1) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fib(n-2) + fib(n-1);
	}
}


// ========================== MEMOIZED FIB  ==========================

unsigned long long mfib(int n) {

  // ***** ADD YOUR MFIB CODE HERE *****

//conditional statement that starts mfib recursion if valid[n] == false
if(valid[n] == false){	
	if(n < 1) {
		memo[n]=0;
		}
	else if (n == 1) {
		memo[n]=1;
	} 
	else{
		memo[n] = mfib(n-1) + mfib(n-2);
	}
	valid[n] = true;				
	}
return memo[n]; //returns result of mfib recursion that is stored in array
}

// ========================== MAIN PROGRAM  ==========================
int main() {

  for (i = 0; i < 55; i+=5) {

    // get start time
    time(&startTime);
    // call fib
    result = fib(i);
    // get stop time
    time(&stopTime);
  
    printf("fib of %d = %llu\n", i, result);
    printf("time taken (sec) = %lf\n\n", difftime(stopTime, startTime));
  }

  printf("\n\n\n");

  for (i = 0; i < 90; i+=5) {

    // get start time
    time(&startTime);
    // call mfib
    initMemo();
    result = mfib(i);
    // get stop time
    time(&stopTime);
  
    printf("mfib of %d = %llu\n", i, result);
    printf("time taken (sec) = %lf\n\n", difftime(stopTime, startTime));
  }

  return 0;
}





