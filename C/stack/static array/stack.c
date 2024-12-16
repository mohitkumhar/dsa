#include <stdio.h>
#define SIZE 100

int stack[SIZE], top = -1;

void push(int x) {
    if (top < SIZE - 1) stack[++top] = x;
    else printf("Stack overflow\n");
}

int pop() {
    if (top >= 0) return stack[top--];
    printf("Stack underflow\n");
    return -1;
}

int peek() {
    if (top >= 0) return stack[top];
    printf("Stack is empty\n");
    return -1;
}

void display() {
    if (top >= 0) {
        for (int i = 0; i <= top; i++) printf("%d ", stack[i]);
        printf("\n");
    } else printf("Stack is empty\n");
}

int main() {
    int choice, val;
    while (1) {
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &val);
            push(val);
        } else if (choice == 2) {
            val = pop();
            if (val != -1) printf("Popped: %d\n", val);
        } else if (choice == 3) {
            val = peek();
            if (val != -1) printf("Top: %d\n", val);
        } else if (choice == 4) display();
        else if (choice == 5) break;
    }
    return 0;
}
