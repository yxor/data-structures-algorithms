#ifndef LINKED_LIST
#define LINKED_LIST

// doing this because C90 has no booleans
typedef int bool;
enum {
    false, true
};
// the items type

typedef int Item;
// possible return values
enum {
    SUCCESS,
    FAILED,
    KEY_NOT_FOUND
};

// node will contain an element (integer)
typedef struct node{
    Item data;
    struct node* next;
    struct node* previous;   
} Node;

typedef struct{
    Node* head;
    Node* tail;
    int length;
} List;

//// node related functions ////
Node* node_create(Item value);
Item node_get_value(Node* node);
void node_print(Node* node);



//// list related functions ////
// constructor
List* list_create();
// destructor
void list_free(List* list);

// access
Item list_get_first(List* list);
Item list_get_last(List* list);
Item list_get_index(List* list, Item index);

// insertion
int list_insert_first(List* list, Item item);
int list_insert_last(List* list, Item item);
int list_insert_at(List* list, Item item, Item key, bool add_after);

// deletion
int list_remove_first(List* list);
int list_remove_last(List* list);
int list_remove_key(List* list, Item key);

// other stuff
bool isEmpty(List* list);
void list_print(List* list);

#endif