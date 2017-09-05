#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkAdd(int value);

int main() {
	struct list* head = create_list();
	char firstCharacter[9] = {'S','u','d','h','e','e','s','h','\0'};
	char secondCharacter[10] = {'B','h','a','t','t','a','r','a','i','\0'};

	int value = add_to_list(&head, firstCharacter);
	checkAdd(value);
	value = add_to_list(&head, secondCharacter);
	checkAdd(value);
	print_list(head);

	char* removeCharacter = remove_from_list(&head);
	free(removeCharacter);
	print_list(head);

	printf("\nHELLO WORLD\n\n");
	return 0;
}

/* Allocates and initializes a new list */
struct list* create_list() {
	struct list* temp = (struct list*) malloc(sizeof(struct list));
	temp = NULL;
	return temp;
}

/* Adds item to start of the list. Allocates a
 * new buffer and copies the string from item (use malloc,
 * strlen, and strncpy; or try strdup).
 * Returns 0 if successful, non-zero otherwise. */
int add_to_list(struct list** ll, char* item) {
	//If it is the first element to add in array
	struct list* temp = (struct list*) malloc(sizeof(struct list));
	if(*ll == NULL) {	
		temp -> next = NULL;
	}
	else {
		temp -> next = *ll;
	}

	char* character = malloc (strlen(item));
	if(character == NULL)
		return -1;//Memory allocation failed
	strncpy(character, item, strlen(item));

	temp -> ch = character;
	*(ll) = temp;
	return 0;
}

void checkAdd(int value) {
	if(value < 0)
		printf("\nPromblem allocating memory to char*\n");
}
/* Removes the string from the front of the list and
 * returns a pointer to it. The caller is expected to free
 * the string returned when finished with it. */
char* remove_from_list(struct list** ll) {
	struct list* currentNode = *ll;
	char* ch = currentNode -> ch;
	*ll = currentNode -> next;
	free(currentNode);
	return ch;
}

/* Prints every string in the list, with a new line
 * character at the end of each string */
void print_list(struct list *ll) {
	printf("\nPrinting lists\n");
	for(struct list* iter = ll; iter != NULL; iter = iter -> next) {
		if(iter -> next == NULL)
			printf("%s ", iter -> ch);
		else
			printf("%s -> ", iter -> ch);
	}
	printf("\n");
}

/* Flushes (clears) the entire list and re-initializes the
 * list. The passed pointer ll should still point to a
 * valid, empty list when this function returns. Any memory
 * allocated to store items in the list should be freed. */
void flush_list(struct list* ll) {

}

/* De-allocates all data for the list. Ensure all memory
 * allocated for this list is freed, including any
 * allocated strings and the list itself. */
void free_list(struct list *ll) {

}
