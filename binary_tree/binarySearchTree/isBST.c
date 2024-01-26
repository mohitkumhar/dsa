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

int isBST(struct Node *root)
{
    static struct Node *prev;

    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }

        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }

        prev = root;
        isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(5);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(3);
    /*
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

    printf("%d", isBST(p));
    return 0;
}
