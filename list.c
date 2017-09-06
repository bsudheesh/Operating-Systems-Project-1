#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkAdd(int value);

int main() {
	list* head = create_list();

	char firstCharacter[9] = {'S','u','d','h','e','e','s','h','\0'};
	char secondCharacter[10] = {'B','h','a','t','t','a','r','a','i','\0'};

	int value = add_to_list(head, firstCharacter);
	checkAdd(value);
	value = add_to_list(head, secondCharacter);
	checkAdd(value);
	print_list(head);

	char* removeCharacter = remove_from_list(head);
	free(removeCharacter);
	print_list(head);

	flush_list(head);
	print_list(head);

	char thirdCharacter[13] = {'L','i','n','k','e','d',' ','L','i','s','t','s','\0'};
	value = add_to_list(head, thirdCharacter);
	print_list(head);
	free_list(head);
	print_list(head);

	return 0;
}

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
	if(item == NULL) {
		printf("\nchar* item is NULL\n");
		return -1;
	}

	struct node* newNode = (struct node*) malloc(sizeof(struct node));

	newNode -> next = ll -> head;
	

	char* character = malloc (strlen(item));
	if(character == NULL)
		return -1;//Memory allocation failed
	strncpy(character, item, strlen(item));

	newNode -> ch = character;
	ll -> head = newNode;
	return 0;
}

void checkAdd(int value) {
	if(value < 0)
		printf("\nPromblem allocating memory to char*\n");
}
/* Removes the string from the front of the list and
 * returns a pointer to it. The caller is expected to free
 * the string returned when finished with it. */
char* remove_from_list(list* ll) {
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
	printf("\nPrinting lists\n");
	if(ll == NULL) {
		printf("\nList is NULL\n");
		return;
	}
	struct node* iter = ll -> head;

	while(iter != NULL) {
		char *value = iter -> ch;

		printf("%s -> ", value);
		iter = iter -> next;
	}
	printf("NULL\n");
}

/* Flushes (clears) the entire list and re-initializes the
 * list. The passed pointer ll should still point to a
 * valid, empty list when this function returns. Any memory
 * allocated to store items in the list should be freed. */
void flush_list(list* ll) {
	struct node* iter = ll -> head;
	while(iter != NULL) {
		struct node* currentNode = iter;
		free(currentNode);
		iter = iter -> next;
	}
	free(ll);
	ll = create_list();
}

/* De-allocates all data for the list. Ensure all memory
 * allocated for this list is freed, including any
 * allocated strings and the list itself. */
void free_list(list *ll) {
	struct node* iter = ll -> head;
	while(iter != NULL) {
		struct node* currentNode = iter;
		free(currentNode);
		iter = iter -> next; 
	}
	// free(ll -> head);
	free(ll);
	
}
