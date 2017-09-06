
struct node {
  struct node *next;
  char *ch;
};

typedef struct {
  struct node *head;
} list;

list* create_list();
int add_to_list(list* ll, char* item);
char* remove_from_list(list* ll);
void print_list(list *ll);
void flush_list(list *ll);
void free_list(list *ll);