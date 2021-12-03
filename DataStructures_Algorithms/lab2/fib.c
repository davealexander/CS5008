//David Centeno
//CS5008
//Fibonacci Lab (Lab2)

#include <stdio.h>
#include <stdlib.h>

long long Fib( long long n) {
	//base case
	if(n == 0){
		return(0);
	}
	if(n == 1){
		return(1);
	}
	//recursive Fibonacci calculation
	else {
		return(Fib(n-1)+Fib(n-2));
	}	
}

int main(){
	long long fibArr[46];	
	int i;	
	int j;

	//loop assigns fib results to array
	for (i=0; i<46; i++){
		fibArr[i] = Fib(i);
        }
	//loop prints out every 5th array value
	for(j=0; j<46; j+=5){
         printf("Fibonacci Number(%2d) = %2lu \n",j,fibArr[j]);
        }
	
	return 0;
}
