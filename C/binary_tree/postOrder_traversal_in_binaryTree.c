#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Creating Node Using Function
struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

// Transversing Using Recusive Function
void postOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    // Create Node Using Function
    struct Node *p = createNode(2);
    struct Node *p1 = createNode(4);
    struct Node *p2 = createNode(5);
    struct Node *p3 = createNode(6);
    struct Node *p4 = createNode(7);
    /*
        Binary Tree Will Look like This  { 6 7 4 5 2 }
                2
               / \
              4   5
             / \
            6   7
    */

    // Locating SubTree Location
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    // Traverse Binary Tree
    postOrderTraversal(p);

    return 0;
}
