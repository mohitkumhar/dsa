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



int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(2);
    struct Node *p4 = createNode(4);
    /*
            5
           / \
          3   6
         / \
        2   4
    */
   p->left = p1;
   p->right = p2;

   p1->left = p3;
   p2->right = p4;
    
    return 0;
}
