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

void insertionInBST(struct Node *root, int key)
{
    struct Node *prev = NULL;

    while (root !=NULL)
    {
        prev = root;

        if(key == root->data)
        {
            printf("Cannot INsert Data, Already Exists!\n");
            return;
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
    struct Node *new = createNode(key);
    if(key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

int main()
{
    struct Node *p = createNode(6);
    struct Node *p1 = createNode(4);
    struct Node *p2 = createNode(7);
    struct Node *p3 = createNode(2);
    struct Node *p4 = createNode(5);
    /*
            6
           / \
          4   7 
         / \
        2   5 
    */

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p2->right = p4;

    insertionInBST(p, 13);

    printf("%d", p->right->right->data);

    return 0;
}
