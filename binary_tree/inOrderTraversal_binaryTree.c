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

void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main()
{
    struct Node *p = createNode(2);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(4);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(6);

    /*
    The Tree Will Look Like This
            
            2
           / \
          3   4
         / \
        5   6

     */

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    inOrderTraversal(p);    // 5 3 6 2 4

    return 0;
}
