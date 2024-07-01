// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;
// };

// struct Node *createNode(int data)
// {
//     struct Node *n = (struct Node *)malloc(sizeof(struct Node));

//     n->data = data;
//     n->left = NULL;
//     n->right = NULL;

//     return n;
// }

// void inOrderTraversal(struct Node *root)
// {
//     if (root != NULL)
//     {
//         inOrderTraversal(root->left);
//         printf("%d ", root->data);
//         inOrderTraversal(root->right);
//     }
// }

// struct Node *inOrderPredecessor(struct Node *root)
// {
//     root = root->left;
//     while (root->right != NULL)
//     {
//         root = root->right;
//     }
//     return root;
// }

// struct Node *delectionNodeInBST(struct Node *root, int value)
// {
//     struct Node *iPre;
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     if (root->left == NULL && root->right == NULL)
//     {
//         free(root);
//         return NULL;
//     }

//     // Search for a Node to be deleted
//     if (value < root->data)
//     {
//         root->left = delectionNodeInBST(root->left, value);
//     }
//     else if (value > root->data)
//     {
//         root->right = delectionNodeInBST(root->right, value);
//     }

//     // Delection of Node when node is found
//     else
//     {
//         iPre = inOrderPredecessor(root);
//         root->data = iPre->data;
//         root->left = delectionNodeInBST(root->left, iPre->data);
//     }
//     return root;
// }

// int main()
// {
//     struct Node *p = createNode(6);
//     struct Node *p1 = createNode(4);
//     struct Node *p2 = createNode(7);
//     struct Node *p3 = createNode(2);
//     struct Node *p4 = createNode(5);

//     /*
//             6
//            / \
//           4   7
//          / \
//         2   5
//     */
//     p->left = p1;
//     p->right = p2;

//     p1->left = p3;
//     p1->right = p4;

//     inOrderTraversal(p);
//     printf("\n");

//     delectionNodeInBST(p, 2);
//     inOrderTraversal(p);

//     return 0;
// }


