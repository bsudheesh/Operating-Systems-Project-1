#include "list.c"

int main() {
	list* head = create_list();

	char* firstCharacter = "Sudheesh";
	char* secondCharacter = "Bhattarai";
	char* testing = NULL;
	char* thirdCharacter = "Linked List";

	/* Testing code for add_to_list */

	//adding the elements in the list
	printf("\n######################## Code and testing for add_to_list ########################\n");
	int value = add_to_list(head, firstCharacter);
	value = add_to_list(head, secondCharacter);
	printf("\n\t\t-----> Printing after adding <-----\n");
	print_list(head);
	//testing to see if the function complains when NULL is passed as character and list
	printf("\n\t\t-----> Testing if add_to_list complains when trying to add NULL <-----\n");
	value = add_to_list(head, testing);
	value = add_to_list(NULL, testing);


	/* Testing code for remove_from_list */

	//removing the first element from the list
	printf("\n######################## Code and testing for remove_from_list ########################\n");
	char* removeCharacter = remove_from_list(head);
	free(removeCharacter);
	printf("\n\t\t-----> Printing after removing first element <-----\n");
	print_list(head);
	//deleting the element from the list again, the list should be empty.
	removeCharacter = remove_from_list(head);
	free(removeCharacter);
	printf("\n\t\t-----> Printing after removing second element<-----\n");
	print_list(head);
	//tesing to see if the function complains when flushing from empty list
	printf("\n\t\t-----> Testing if removeCharacter complains when trying to remove from empty list <-----\n");
	removeCharacter = remove_from_list(head);
	free(removeCharacter);


	/* Testing code for flush_list */

	//adding elements in the list again
	printf("\n######################## Code and testing for flush_list ########################\n");
	value = add_to_list(head, firstCharacter);
	value = add_to_list(head, secondCharacter);
	printf("\n\t\t-----> Printing after adding element before flushing <-----\n");
	print_list(head);
	flush_list(head);
	printf("\n\t\t-----> Printing after flushing <-----\n");
	print_list(head);
	//tesing to see if the function complains when flushing from empty list
	printf("\n\t\t-----> Testing if flush_list complains when trying to flush empty list <-----\n");
	flush_list(head);

	/* Testing code for free_list */
	
	//adding element to list again
	printf("\n######################## Code and testing for free_list ########################\n");
	value = add_to_list(head, thirdCharacter);
	value = add_to_list(head, secondCharacter);
	value = add_to_list(head, firstCharacter);
	printf("\n\t\t-----> Printing after adding element before freeing <-----\n");
	print_list(head);
	free_list(head);
	printf("\n\t\t-----> Printing after freeing <-----\n");
	print_list(head);

	//initialising the head again
	printf("\n######################## Final printing the list ########################\n");
	head = create_list();
	value = add_to_list(head, thirdCharacter);
	value = add_to_list(head, secondCharacter);
	value = add_to_list(head, thirdCharacter);
	printf("\n\t\t-----> Printing after reinitialising head and adding <-----\n");
	print_list(head);
	printf("\n############################### DONE!!!! ###############################\n");
	return 0;
}