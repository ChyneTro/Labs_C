#include "Tree.h"

handvalue* create_point(int key)
{
    handvalue* tmp;
    tmp = (handvalue*)malloc(sizeof(handvalue));
    tmp->key = key;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

handvalue* add(handvalue* cr, int key)
{
    if (key < cr->key)
        if (cr->left == NULL)
            return cr->left = create_point(key);
        else
            return add(cr->left, key);

    if (key >= cr->key)
        if (cr->right == NULL)
            return cr->right = create_point(key);
        else
            return add(cr->right, key);

    return NULL;
}

handvalue* search(handvalue* cr, int key)
{
    if ((cr == NULL) || (cr->key == key))
        return cr;
    if (key < cr->key)
        return search(cr->left, key);
    else return search(cr->right, key);
}

void print_tree(handvalue* current_node)
{
    if (current_node->right != NULL)
        print_tree(current_node->right);

    if (current_node->left != NULL)
        print_tree(current_node->left);

   printf("Node %d\n", current_node->key);
}