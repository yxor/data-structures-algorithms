#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Binary search tree
 */

// PRIVATE FUNCTIONS

node* node_create(Item value)
{
    node* n = (node*) malloc(sizeof(node));
    if(n == NULL)
    {
        fprintf(stderr, "Failed allocating node.");
        exit(EXIT_FAILURE);
    }
    n->left = NULL;
    n->right = NULL;
    n->value = value;

    return n;
}

void node_destroy(node* node)
{
    free(node);
}

void node_print(node* node)
{
    if (node == NULL)
        return;
    node_print(node->left);
    printf("%2d ", node->value);
    node_print(node->right);
}
// PUBLIC FUNCTIONS

Tree tree_create()
{
    Tree t = (Tree) malloc(sizeof(struct tree));
    if(t == NULL)
    {
        fprintf(stderr, "Failed allocating tree.");
        exit(EXIT_FAILURE);
    }

    t->root = NULL;
    return t;
}


void tree_insert(Tree t, Item value)
{
    node* temp;
    // tree has no nodes, make this node the root.
    if(t->root == NULL)
    {
        t->root = node_create(value);
        return;
    }

    temp = t->root;
    while(true)
    {
        // base case, if we find the value were adding is already in the tree
        if(temp->value == value)
        {
            return;
        }
        // traversing ...
        if(temp->left && value < temp->value)
        {
            temp = temp->left;
            continue;
        }
        if(temp->right && value > temp->value)
        {
            temp = temp->right;
            continue;
        }
        // if we reach here it means its insertion time ;)
        if(!temp->left && value < temp->value)
        {
            temp->left = node_create(value);
            break;
        }
        // just put it on the left then
        temp->right = node_create(value);
        break;
    }
}
void tree_delete(Tree t, Item value)
{
    node* temp;
    // tree has no nodes, make this node the root.
    if(t->root == NULL)
    {
        fprintf(stderr, "Attempting to delete a node of an empty tree");
        exit(EXIT_FAILURE);
    }
    temp = t->root;

    while(true)
    {
        if(temp->value == value)
        {
            
            return;
        }


        // traversing ...
        if(temp->left && value < temp->value)
        {
            temp = temp->left;
            continue;
        }
        if(temp->right && value > temp->value)
        {
            temp = temp->right;
            continue;
        }
        // if we reach here it means its insertion time ;)
        if(!temp->left && value < temp->value)
        {
            temp->left = node_create(value);
            break;
        }
        // just put it on the left then
        temp->right = node_create(value);
        break;
    }
}

void tree_print(Tree t)
{
    printf("printing tree: root adress %d\n", (int)t->root);
    node_print(t->root);
}

bool tree_isEmpty(Tree t)
{
    return t->root == NULL; 
}


bool tree_contains(Tree t, Item value);

Item tree_max(Tree t)
{
    if(tree_isEmpty(t))
    {
        fprintf(stderr, "Attempting to find the max of an Empty Tree");
        exit(EXIT_FAILURE);
    }
    node* cur = t->root;
    while(cur->right)
    {
        cur = cur->right;
    }
    return cur->value;
}
Item tree_min(Tree t)
{
    if(tree_isEmpty(t))
    {
        fprintf(stderr, "Attempting to find the min of an Empty Tree");
        exit(EXIT_FAILURE);
    }
    node* cur = t->root;
    while(cur->left)
    {
        cur = cur->left;
    }
    return cur->value;
}
