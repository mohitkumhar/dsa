#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}

int push(struct stack *sp, char data)
{
    if (sp->top == sp->size - 1)
    {
        return -1;
    }
    sp->top++;
    sp->arr[sp->top] = data;
}

int pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        return -1;
    }
    char popedElement = sp->arr[sp->top];
    sp->top--;

    return popedElement;
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/' || ch == '%')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if(ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-')
    {
        return 1;
    }
    return 0;
}

char *infix_to_postfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0; // Track infix
    int j = 0; // Track postfix

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char *infix = "a+b-c";

    printf("The Postfix of %s is: %s", infix, infix_to_postfix(infix));

    return 0;
}
