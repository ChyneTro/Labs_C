#pragma once
#include <stdio.h>        
#include <malloc.h>

typedef struct bin_tree
{
    int key;
    struct bin_tree* left;
    struct bin_tree* right;
} handvalue;

handvalue* create_point(int key);

handvalue* add(handvalue* cr, int key);

handvalue* search(handvalue* cr, int key);

void print_tree(handvalue* current_node);

