#include "list.c"

int main() {
	list* head = create_list();

	char* firstCharacter = "Sudheesh";
	char* secondCharacter = "Bhattarai";

	int value = add_to_list(head, firstCharacter);
	value = add_to_list(head, secondCharacter);
	print_list(head);

	char* removeCharacter = remove_from_list(head);
	free(removeCharacter);
	print_list(head);

	flush_list(head);
	print_list(head);

	char* thirdCharacter = "Linked List";
	value = add_to_list(head, thirdCharacter);
	value = add_to_list(head, secondCharacter);
	value = add_to_list(head, firstCharacter);
	print_list(head);

	free_list(head);
	print_list(head);

	head = create_list();
	value = add_to_list(head, thirdCharacter);
	value = add_to_list(head, secondCharacter);
	value = add_to_list(head, thirdCharacter);
	print_list(head);

	return 0;
}