#include "lab5.h"

/**************************************
 *         PROVIDED FUNCTIONS
 *************************************/

slnode_t* malloc_slnode(data_t data) {

    slnode_t *node = (slnode_t*)malloc(sizeof(slnode_t));

    if (node == NULL) {
        fprintf(stderr, "ERROR: Cannot allocate memory for link list node.");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;

    return node;
}

void sllist_init(sllist_t *list) {

    list->head = NULL;
    list->size = 0;
}

void sllist_addfirst(sllist_t *list, data_t item) {

    slnode_t *new_node = malloc_slnode(item);   // allocate new node

    if (list->head != NULL) {                   // non-empty list:
        new_node->next = list->head;            //   set the new node's next ptr
    }
    list->head = new_node;                      // set the list head
    list->size++;                               // increment the size tracker
}

bool sllist_contains (sllist_t *list, data_t item) {

    slnode_t *n;

    // iterate over the linked list, looking for 'item'
    for (n = list->head; n != NULL; n = n->next) {
        if (n->data == item) {
            return true;
        }
    }

    return false;
}

size_t sllist_size(sllist_t *list) {

    return list->size;
}


/**************************************
 *         TO BE IMPLEMENTED
 *************************************/

bool is_palindrome(char *text) {
	//confirms palindrome function is called
	int i;
	
	// Allocate memory for stack and queue
	dynarray_t* stack = malloc(sizeof(dynarray_t));
	dynarray_t* queue = malloc(sizeof(dynarray_t));

	// Initialize memory for stack and queue
	dynarray_init(stack);
	dynarray_init(queue);
	
	//Pulls in data from input array into stack and queue
	for(i=0; i<*text - 1; i++){
		//see how many times loop runs currently it runs way too many times
		printf("loop(%d) char: %c \n",i,*text);
		dynarray_push(stack, (data_t) *text);
		dynarray_enqueue(queue, (data_t) *text);
		*text++;
		}

	//Compares stack to queue 
	for(i=0;i<= dynarray_size(stack); i++){
		//Establish variables to hold values of pop and dequeue from stack and queue
		data_t pstack = dynarray_pop(stack);
		data_t pdequeue = dynarray_dequeue(queue);

 		//see how many times loop runs and confrims comparison loop runs
		
		if(pstack != pdequeue){
			printf("False! Is not a palindrome \n");
			return false;
		}	
	}
	printf("True! Is palindrome \n");
	return true;
}

size_t sllist_count (sllist_t *list, data_t item) {

    return 0;
}

int sllist_find (sllist_t *list, data_t item) {

    return -1;
}

void sllist_free (sllist_t *list) {

}

void sllist_addlast (sllist_t *list, data_t item) {

}

bool sllist_is_equal (sllist_t *list1, sllist_t *list2) {

    return false;
}

void sllist_insert (sllist_t *list, data_t item, size_t index) {

}

void sllist_remove (sllist_t *list, data_t item) {

}
//received assistance from Evan on isPalindrome functions and starting the function
