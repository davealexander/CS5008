//David Centeno
//CS5008
//Calculations Homework 2
//Program will provide the input of two values, sum, difference, product, and quotient

#include <stdio.h>
#include <stdio.h>

int main() {
	int i;
	//test x and y values
	double  x[4] = {10,40,1,15};
	double  y[4] = {5,8,4,30};
	
	
	//loop that prints through testing values
	for(i=0; i<=3; i++){
		//calculations
		double sum = x[i] + y[i];
        	double dif = x[i] - y[i];
        	double product = x[i] * y[i];
       		double quotient = x[i] / y[i];
		//print statements of calculations
		printf("Two Values: %lf,and  %lf\n", x[i],y[i]);
		printf("Sum: %lf\n", sum);
        	printf("Difference: %lf\n", dif);
        	printf("Product: %lf\n", product);
        	printf("Quotient: %lf\n", quotient);
	}
	return 0;
}
