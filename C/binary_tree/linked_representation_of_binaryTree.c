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
    struct Node *n;                                 // creating a Node pointer
    n = (struct Node *)malloc(sizeof(struct Node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL

    return n; // Returning the created Node
}

int main()
{
    /*
    struct Node *p, *p1, *p2;

    // Constructing Root Node
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    // Constructing the second Node
    p1 = (struct Node *)malloc(sizeof(struct Node));
    p->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    // Constructing the third Node
    p2 = (struct Node *)malloc(sizeof(struct Node));
    p->data = 4;
    p2->left = NULL;
    p2->right = NULL;

    p->left = p1;
    p->right = p2;

    */

    // Constructing Root Node Using Functions (Recommanded)
    struct Node *p = createNode(2);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(4);

    // Linking the Root with Left and Right children
    p->left = p1;
    p->right = p2;

       return 0;
}
