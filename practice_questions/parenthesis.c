#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int push(struct stack *sp, char data)
{
    if (sp->top == sp->size - 1)
    {
        printf("Stack Overflow! Cannot Push Element\n");
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
    if (sp->top == -1)
    {
        printf("Stack Underflow! Cannot Pop Element\n");
    }
    else
    {
        int popedElement = sp->arr[sp->top];
        sp->top--;
        return popedElement;
    }
}

int peek(struct stack *sp, int pos)
{
    if (sp->top == -1)
    {
        return 'E';
    }
    return sp->arr[sp->top - pos + 1];
}

int checkParenthesis(struct stack *sp, char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("The %dth Element of String is: %c\n", i, str[i]);
        if (str[i] == '(')
        {
            char pushedElement = push(sp, str[i]);
            printf("The %c is Pushed into Stack\n", pushedElement);
        }
        else if (str[i] == ')')
        {
            if (sp->top == -1)
            {
                return 0;
            }
            pop(sp);
        }
    }

    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    struct stack *sp;
    sp = (struct stack *)malloc(sizeof(struct stack));

    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char str[] = "(((a + b * c) - (d / e) + (f * (g + h) / (i - (j * (k / l) + m))) - (n + o)) * ((p / q) + ((r - s) * t) / ((u + (v / w)) - (x * y) / z)) / (aa - (bb * (cc + (dd / ee - ff) * gg)) + (hh - ii / (jj + (kk * ll) - (mm / nn + oo)) * pp)))";

    if (checkParenthesis(sp, str) == 1)
    {
        printf("This Parenthesis is in Correct Form");
    }
    else
    {
        printf("This Parenthesis is in InCorrect Form");
    }

    return 0;
}
