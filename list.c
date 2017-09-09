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

/* Adds item to start of the list. Allocates a
 * new buffer and copies the string from item (use malloc,
 * strlen, and strncpy; or try strdup).
 * Returns 0 if successful, non-zero otherwise. */
int add_to_list(list* ll, char* item) {
	//If it is the first element to add in array

	if(item == NULL || ll == NULL) {
		printf("\n*** The list or item is NULL ***\n");
		return -1;
	}

	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	if(newNode == NULL) {
		printf("\nError creating new node!\n");
		return -1;
	}

	newNode -> next = ll -> head;

	char* character = malloc (strlen(item) + 1);
	if(character == NULL) {
		printf("\n*** Error creating buffer for the string ***\n");
		return -1;//Memory allocation failed
	}
	strncpy(character, item, strlen(item));

	newNode -> ch = character;
	ll -> head = newNode;
	return 0;
}

/* Removes the string from the front of the list and
 * returns a pointer to it. The caller is expected to free
 * the string returned when finished with it. */
char* remove_from_list(list* ll) {
	if(ll == NULL) {
		printf("\n*** List is NULL ***\n");
		return NULL;
	}
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode = ll -> head;
	char* deleteChar = newNode -> ch;
	ll -> head = newNode -> next;
	free(newNode);
	return deleteChar;
}

/* Prints every string in the list, with a new line
 * character at the end of each string */
void print_list(list *ll) {
	if(ll == NULL || ll -> head == NULL) {
		printf("\n*** List is NULL or empty ***\n");
		return;
	}
	struct node* iter = ll -> head;
	printf("\n");
	while(iter != NULL) {
		printf("%s\n", iter -> ch);
		iter = iter -> next;
	}
	printf("\n");
}

/* Flushes (clears) the entire list and re-initializes the
 * list. The passed pointer ll should still point to a
 * valid, empty list when this function returns. Any memory
 * allocated to store items in the list should be freed. */
void flush_list(list* ll) {
	if(ll == NULL) {
		printf("\n*** List is NULL ***\n");
		return;
	}
	struct node* iter = ll -> head;
	while(iter != NULL) {
		struct node* currentNode = iter;
		free(currentNode);
		currentNode = NULL;
		iter = iter -> next;
	}
	ll -> head = NULL;

}

/* De-allocates all data for the list. Ensure all memory
 * allocated for this list is freed, including any
 * allocated strings and the list itself. */
void free_list(list *ll) {
	if(ll == NULL) {
		printf("\n*** List is NULL ***\n");
		return;
	}
	struct node* iter = ll -> head;

	while(iter != NULL) {
		struct node* currentNode = iter;
		free(currentNode);
		currentNode = NULL;
		iter = iter -> next; 
	}
	free(ll);
	ll -> head = NULL;
}