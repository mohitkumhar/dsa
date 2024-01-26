#include <stdio.h>
#include <stdlib.h>

// Creating Stack
struct stack
{
    int size;
    int top;
    char *arr;
};

// Checks That Stack is Full or Not 
int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    return 0;
}

// Checks That Stack is Empty or Not 
int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}

// Push an Individual Element into Stack
int push(struct stack *sp, char data)
{
    // Checks if Stack is Full or Not
    if (isFull(sp))
    {
        printf("Stack Overflow! Cannot Push Element\n");
        return -1;
    }
    sp->top++;
    sp->arr[sp->top] = data;

    return 0;
}

// Pop The Top Element of Stack
char pop(struct stack *sp)
{
    // Checks if Stack is Empty or Not 
    if (isEmpty(sp))
    {
        printf("Stack Underflow! Cannot POp Element\n");
        return -1;
    }
    char popedElement = sp->arr[sp->top];
    sp->top--;

    return popedElement;
}

// Show The Individual Element of Stack Based on Position Entered By User
int peek(struct stack *sp, int pos)
{
    // Checks if Stack is Empty or Not
    if (isEmpty(sp))
    {
        printf("Stack Underflow! Cannot Peek Elements\n");
        return -1;
    }

    return sp->arr[sp->top - pos + 1];
}

// Checks if Multi Parenthesis is Balanced or Not 
int checkMultiParenthesis(char str[])
{
    // Creating Stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));

    // Defining Stack
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char popedElement;

    // Loop for Seperating Each Letter of Array
    for (int i = 0; str[i] != '\0'; i++)
    {
        // Pushing Start Parenthesis
        if (str[i] == '[' || str[i] == '{' || str[i] == '(')
        {
            push(sp, str[i]);
        }

        // Poping Start Parenthesis
        else
        {
            if (str[i] == ']' || str[i] == '}' || str[i] == ')')
            {
                popedElement = pop(sp);

                // Poping Start Parenthesis Bases of Ending one
                if (str[i] == ']' && popedElement != '[' ||
                    str[i] == '}' && popedElement != '{' ||
                    str[i] == ')' && popedElement != '(')
                {
                    return 0;
                }
            }
        }
    }

    // Checking if Stack is Empty or Not
    if (isEmpty(sp))
    {
        return 1;
    }
    return 0;
}

int main()
{
    // Using Array to Define a Multi Parenthesis Question
    char str[] = "{[(){{[{()}]}}]({[{()[]}]})[()]}";

    int checking = checkMultiParenthesis(str);
    
    // Printing User Friendly Output
    if (checking == 1)
    {
        printf("The Multi Parenthesis is Balanced\n");
    }
    else
    {
        printf("This Multi Parenthesis is Unbalanced\n");
    }

    return 0;
}
