#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void transverseLinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Data: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    int i = 0;
    while (i != index - 1)
    {
        head = head->next;
        i++;
    }

    ptr->data = data;
    ptr->next = head->next;
    head->next = ptr;

    return ptr;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    while(head->next != NULL)
    {
        head = head->next;
    }
    ptr->data = data;
    ptr->next=NULL;
    head->next=ptr;

    return ptr;
}

struct Node *insertBeforeNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = prevNode;

    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;

    return ptr;
}

int main()
{
    // Dynamic Memory Allocation
    struct Node *head, *second, *third, *fourth, *fifth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Inserting data in LinkedList
    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = fourth;

    fourth->data = 44;
    fourth->next = NULL;

    // Using Functions

    printf("\nBefore Applying Operations\n");

    transverseLinkedList(head);

    // head = insertAtFirst(head, 121);

    // insertAtIndex(head, 121, 3);

    // insertAtEnd(head, 121);

    // insertBeforeNode(head, second, 121);

    printf("\nAfter Applying Operations\n");

    transverseLinkedList(head);

    return 0;
}