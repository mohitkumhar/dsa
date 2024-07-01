#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isFull()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Node *f)
{
    if (f == NULL)
    {
        return 1;
    }
    return 0;
}

void tranversalLinkList(struct Node *f)
{
    printf("Elements of Linked List Are: \n");
    while (f != NULL)
    {
        printf("Data is: %d\n", f->data);
        f = f->next;
    }
}

int enqueue(struct Node **f, struct Node **r, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Queue OverFlow! Cannot Push Element\n");
        return -1;
    }
    else
    {
        ptr->data = data;
        ptr->next = NULL;
        if (*f == NULL)
        {
            *f = *r = ptr;
        }
        else
        {
            (*r)->next = ptr;
            *r = ptr;
        }
    }
}

int dequeue(struct Node **f)
{
    if (isEmpty(*f))
    {
        return -1;
    }
    struct Node *ptr = *f;
    *f = (*f)->next;
    int popedElement = ptr->data;
    free(ptr);

    return popedElement;
}

int main()
{
    struct Node *f = NULL;
    struct Node *r = NULL;

    printf("Initially Queue\n");
    printf("Queue is Full: %d\n", isFull());
    printf("Queue is Empty: %d\n", isEmpty(f));
    tranversalLinkList(f);


    printf("\nQueue After Enqueue Elements\n");
    enqueue(&f, &r, 11);
    enqueue(&f, &r, 22);
    enqueue(&f, &r, 33);
    printf("Queue is Full: %d\n", isFull());
    printf("Queue is Empty: %d\n", isEmpty(f));
    tranversalLinkList(f);


    printf("\nQueue After Dequeue Elements\n");
    dequeue(&f);
    dequeue(&f);
    printf("Queue is Full: %d\n", isFull());
    printf("Queue is Empty: %d\n", isEmpty(f));
    tranversalLinkList(f);

    return 0;
}
