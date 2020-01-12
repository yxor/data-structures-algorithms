#ifndef B_TREE
#define B_TREE

// just for readability
typedef int bool;
enum{
    false, true
};

// to be ""abstract""
typedef int Item;
typedef struct node{
    int value;
    struct node* left;
    struct node* right;
} node;

struct tree{
    struct node* root;
};

typedef struct tree* Tree;


// PRIVATE FUNCTIONS
node* node_create(Item value);
void node_destroy(node* node);

// PUBLIC FUNCTIONS
Tree tree_create();
void tree_insert(Tree t, Item value);
void tree_delete(Tree t, Item value);
void tree_print(Tree t);
bool tree_contains(Tree t, Item value);
bool tree_isEmpty(Tree t);
Item tree_max(Tree t);
Item tree_min(Tree t);


#endif