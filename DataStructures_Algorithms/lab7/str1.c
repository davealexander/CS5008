#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 50

int  main() {	
	int len;
	char str[MAX_CHAR]="hakuna matata!"; 	// this line should copy 
					// "hakuna matata!"
 	                         	// into our char array
       
	//store string to array
	char *ptr[MAX_CHAR];
	len = strlen(str);
	*ptr=(char *)malloc(sizeof(char)*(len+1));
	strcpy(*ptr,str);

	printf("%s\n", str);
 	printf("%s\n", *ptr);

	free(*ptr);                         			
	// Anything else?
 return 0;
}

