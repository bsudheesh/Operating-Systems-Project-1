
struct list {
	struct list* next;
	char** ch;
};

struct list* create_list( );
int add_to_list(struct list** ll, char* item);
char* remove_from_list(struct list** ll);
void print_list(struct list *ll);
void flush_list(struct list* ll);
void free_list(struct list *ll);