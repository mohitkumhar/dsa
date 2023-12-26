#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void tranversal(struct Node *top)
{
    while(top != NULL)
    {
        printf("Data is: %d\n", top->data);
        top = top->next;
    }
}

int isFull(struct Node *top)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if(ptr == NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct Node *top)
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int data)
{
    if(isFull(top))
    {
        return -1;
    }
    else{
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = top;
        top = ptr;

        return ptr;
    }
}

struct Node *pop(struct Node **top)
{
    struct Node *ptr = *top;
    *top = (*top)->next;
    int popedElement = ptr->data;
    free(ptr);

    return popedElement;
}

struct Node *peek(struct Node *top, int pos)
{
    for(int i = 0; (i < pos - 1 && top != NULL); i++)
    {
        top = top->next;
    }
    if(top != NULL)
    {
        return top->data;
    }
    else
    {
        return -1;
    }
}

struct Node *stackTop(struct Node *top)
{
    if(isEmpty(top))
    {
        printf("Stack Underflow! No Elements Found");
    }
    else
    {
        return top->data;
    }
}

struct Node *stackBottom(struct Node *top)
{
    while(top->next != NULL)
    {
        top = top->next;
    }
    if(isEmpty(top))
    {
        printf("Stack Underflow! No Element is Found");
    }
    else
    {
        return top->data;
    }
}

int main()
{
    struct Node *top = NULL;

    printf("Stack Before Pushing Element\n");
    printf("The Stack is Full: %d\n", isFull(top));
    printf("The Stack is Empty: %d\n", isEmpty(top));
    tranversal(top);

    top = push(top, 11);
    top = push(top, 22);
    top = push(top, 33);
    top = push(top, 44);
    top = push(top, 55);
    top = push(top, 66);
    top = push(top, 77);
    top = push(top, 88);
    top = push(top, 99);
    printf("\nStack After Pushing Elements\n");
    printf("The Stack is Full: %d\n", isFull(top));
    printf("The Stack is Empty: %d\n", isEmpty(top));
    tranversal(top);

    printf("\nStack After Poping Elements\n");
    int popedElement = pop(&top);
    printf("Poped Element is: %d\n", popedElement);
    printf("The Stack is Full: %d\n", isFull(top));
    printf("The Stack is Empty: %d\n", isEmpty(top));
    tranversal(top);

    int i = 2;
    printf("\nThe Value at Position %d is: %d\n", i, peek(top, i));

    printf("\nThe Top Element of Stack is: %d\n", stackTop(top));
    printf("\nThe Bottom Element of Stack is: %d\n", stackBottom(top));





    return 0;
}
