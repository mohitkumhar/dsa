#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

struct Node *searchIterate(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if(key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

int main()
{
    struct Node *p = createNode(6);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(7);
    struct Node *p3 = createNode(2);
    struct Node *p4 = createNode(5);
    /*
                6
               / \
              3   7
             / \
            2   5
    */

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    struct Node *result = searchIterate(p, 7);

    if(result !=NULL)
    {
        printf("Element is Found: %d", result->data);
    }
    else{
        printf("Not Found");
    }

    return 0;
}
