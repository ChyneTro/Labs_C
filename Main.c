#include"Tree.h"

void main(void)
{
    FILE* f;
    int srch, i;
    handvalue* root = NULL;
    handvalue* s;
    int element;
    fopen_s(&f, "massiv.txt", "r");

    while (!feof(f))
    {
        if (fscanf_s(f, "%d", &element) > 0)
            if (root == NULL)
                root = create_point(element);
            else
                add(root, element);
    }

    print_tree(root);
    
    while (1)
    {
        printf("\n search: ");
        scanf_s("%d", &srch);
        s = search(root, srch);
        if (!s)
            printf("no search\n");
        else
        {
            printf("%d \n", s->key);
            if (s->left)
                printf("Left %d", s->left->key);
            else
                printf("Left --");
            if (s->right)
                printf("  Right %d\n", s->right->key);
            else
                printf("  Right --\n");
        }
    }
}