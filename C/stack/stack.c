#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(struct stack *sp, int data)
{
    if (isFull(sp))
    {
        printf("Stack Overflow! Cannot Push %d in Stack\n", data);
        return -1;
    }

    else
    {
        sp->top++;
        sp->arr[sp->top] = data;
    }
}

int pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack Underflow! Cannot Pop Element\n");
        return -1;
    }
    else
    {
        sp->top--;
    }
}

int peek(struct stack *sp, int val)
{
    if(isEmpty(sp))
    {
        printf("Stack Underflow!, Cannot Peek Elements\n");
        return -1;
    }
    // else if(val < 0 || val > sp->top)
    // {
    //     printf("Not a Valid Position in Stack\n");
    //     return -1;
    // }
    return sp->arr[sp->top - val + 1];
}

void stackTop(struct stack *sp)
{
    printf("The Top Element of Stack is: %d\n", sp->arr[sp->top]);
}

void stackBottom(struct stack *sp)
{
    printf("The Bottom Element of Stack is: %d\n", sp->arr[0]);
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));

    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("Stack Is Created Successfully\n");
    printf("\nBefore Pushing\n");
    printf("Stack is Full: %d\n", isFull(sp));
    printf("Stack is Empty: %d\n\n", isEmpty(sp));

    push(sp, 1);
    push(sp, 2);
    push(sp, 3);
    push(sp, 4);
    push(sp, 5);
    push(sp, 6);
    push(sp, 7);
    push(sp, 8);
    push(sp, 9);
    push(sp, 10);
    push(sp, 11); // Stack Overflow

    printf("After Pushing\n");
    printf("Stack is Full: %d\n", isFull(sp));
    printf("Stack is Empty: %d\n\n", isEmpty(sp));

    pop(sp);

    printf("After Poping\n");
    printf("Stack is Full: %d\n", isFull(sp));
    printf("Stack is Empty: %d\n\n", isEmpty(sp));

    for (int i = 1; i < 10; i++)
    {
        printf("The Value at Index %d is: %d\n", i, peek(sp, i));
    }

    stackTop(sp);
    stackBottom(sp);

    return 0;
}