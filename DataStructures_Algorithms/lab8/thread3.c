// Compile with:
//
// clang -lpthread thread3.c -o thread3
// or
// gcc -lpthread thread3.c -o thread3
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 40000

// shared variable
int counter = 0;

// thread to be executed - unspecified variable arguments
void *thread (void *vargp) {
  counter = counter +1;
  return NULL;
}

//copy above thread and make new ones appropriately to do the following
//thread2 increment by 5
void *thread2 (void *vargp) {
	counter = counter + 5;
	return NULL;
}

//thread3 subtract 2 from counter
void *thread3 (void*vargp){
	counter = counter - 2;
	return NULL;
}
//thread4 subtract 10 from counter
void *thread4 (void*vargp){
	counter = counter - 10;
	return NULL;
}

int main() {
  // array to keep Pthread IDs of created threads
  pthread_t tid[NTHREADS];
  int i,j;
 for (j=0; j<5; j++){ 
  printf("Iteration: %d\n",j);
  printf("Counter starts at %d\n", counter);
  
  // creates and runs the first 20000 threads
  for (i=0; i < 10000; ++i){
    pthread_create(&(tid[i]), NULL, thread, NULL);
  }
  for (i=10000; i < 20000; ++i){
    pthread_create(&(tid[i]), NULL, thread2, NULL);
  }
  //waits for first 20000 threads to finish
  for (i=0; i < 20000; ++i){
    pthread_join(tid[i], NULL);
  }
  //creates and runs the last 20000 threads
  for (i=20000; i< 30000; ++i) {
    pthread_create(&(tid[i]), NULL, thread3, NULL);
  }
  for (i=30000; i<40000; ++i) {
    pthread_create(&(tid[i]), NULL, thread4, NULL);
  }
  //waits for the last 20000 threads to finish
  for (i=20000; i< 40000; ++i) {
    pthread_join(tid[i], NULL);
  }
 
  printf("Counter ends at %d\n", counter);
  //Clean up
  counter = 0;
  i=0;
}
  return 0;
}
