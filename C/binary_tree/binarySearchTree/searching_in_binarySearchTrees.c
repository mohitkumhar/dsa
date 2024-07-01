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

struct Node *searchInBST(struct Node *root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }

    else if(root->data == key)
    {
        return root;
    }
    
    else if(root->data > key)
    {
        searchInBST(root->left, key);
    }
    
    else
    {
        searchInBST(root->right, key);
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
        1
       / \
      2   3
     / \
    4   5 

*/

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;


    printf("%d", searchInBST(p, 3)->data);

    return 0;
}
