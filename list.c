#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Allocates and initializes a new list */
list* create_list() {
	list* temp = (list*) malloc(sizeof(list));
	temp -> head = NULL;
	return temp;
}


/* A helper function that checks to see if the list pointer is NULL or list is empty.
 * Returns 0 if ll 0r ll -> head is not null, -1 if otherwise. */
int check_list_null(list* ll)  {
	if(ll == NULL || ll -> head == NULL) {
		printf("\n*** List is NULL or empty***\n");
		return -1;
	}
	return 0;
}

/* Adds item to start of the list. Allocates a
 * new buffer and copies the string from item (use malloc,
 * strlen, and strncpy; or try strdup).
 * Returns 0 if successful, non-zero otherwise. */
int add_to_list(list* ll, char* item) {
	//If list is null or the string is null, return -1
	if(item == NULL || ll == NULL) {
		printf("\n*** The list or item is NULL ***\n");
		return -1;
	}
	//if the memory allocation fails for creating node
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	if(newNode == NULL) {
		printf("\nError creating new node!\n");
		return -1;
	}

	newNode -> next = ll -> head; //change the next of new node created to the head

	char* character = malloc (strlen(item) + 1);
	//if memory allocation fails for creating a buffer for the string
	if(character == NULL) {
		printf("\n*** Error creating buffer for the string ***\n");
		return -1;
	}
	strncpy(character, item, strlen(item) + 1); //copy from item.

	newNode -> ch = character;
	ll -> head = newNode; //change the head to the new element
	return 0; //return if successful
}

/* Removes the string from the front of the list and
 * returns a pointer to it. The caller is expected to free
 * the string returned when finished with it. */
char* remove_from_list(list* ll) {
	if(check_list_null(ll) < 0) 
		return NULL;

	struct node* newNode = ll -> head;
	ll -> head = newNode -> next; //change the head to point to it's next node element.
	newNode -> next = NULL;
	char* deleteChar = newNode -> ch;
	free(newNode); //free the node
	return deleteChar; //return the character that was deleted
}


/* Prints every string in the list, with a new line
 * character at the end of each string */
void print_list(list *ll) {
	if(check_list_null(ll) < 0) 
		return;

	for(struct node* iter = ll -> head; iter != NULL; iter = iter -> next) {
		printf("%s\n", iter -> ch);
	}
}

/* A helper function which is used to free all nodes in the list.
 * This is used by flush_list(ll) and free_list(ll) */
void delete_list(list* ll) {
	if(check_list_null(ll) < 0) 
		return;

	struct node* iter = ll -> head;
	while(iter != NULL) {
		struct node* nextNode = iter -> next; //store the next node
		char* freedValue = iter -> ch;

		free(freedValue); //free the character
		free(iter); //free the node

		iter = nextNode; //change the current node to next
		ll -> head = iter; //changing the head at every step
	}
}

/* Flushes (clears) the entire list and re-initializes the
 * list. The passed pointer ll should still point to a
 * valid, empty list when this function returns. Any memory
 * allocated to store items in the list should be freed. */
void flush_list(list* ll) {
	delete_list(ll); //use the helper function
}

/* De-allocates all data for the list. Ensure all memory
 * allocated for this list is freed, including any
 * allocated strings and the list itself. */
void free_list(list *ll) {
	delete_list(ll); //use the helper function
	free(ll); //ensuring the list itself is freed
}