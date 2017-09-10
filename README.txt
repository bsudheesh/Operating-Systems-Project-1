Building and running the program:
1) Unzip the project.
2) Write the command "make sudheeshbhattarai"
3) There will be a file called "list_test2" created. Open to execute the program.


Brief description of assignment
1) There are three files namely list_test.c, list.c and list.h
2) All the function declarations are in list.h and the declarations are in list_test.c
3) The testing and the driver program is in list_test.c
4) Inside list.c there are 8 functions, out of which 2 are helper functions: delete_list and check_list_null. delete_list frees the nodes that are in the list and check_list_null is used to check is the list is null or empty.
5) The testing in list_test.c is done in 5 ways.
	1) Lists are added and printed. They are tested if they work when NULL is passed.
	2) Removing from list. They are tested to see if they work when list is empty.
	3) Flushing from list. They are tested to see if they work when list is empty.
	4) Freeing from list. They are tested to see if they work when list is empty.
	5) Reinitialising the head again and adding few nodes. 


Challenges:
1) Knowing the syntax of C
2) Knowing about malloc and free.
3) Knowing how pointers behave. Freeing a pointer doesn't mean its pointing to NULL. It had to explicitly set to NULL.

Resources:
1) Knowing only pointers allocated via malloc can be freed
https://stackoverflow.com/questions/13148119/what-does-pointer-being-freed-was-not-allocated-mean-exactly

2) Knowing if there is a way to know a pointer was freed
https://stackoverflow.com/questions/8300853/how-to-check-if-a-pointer-is-freed-already-in-c