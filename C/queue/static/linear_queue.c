#include <stdio.h>
#define SIZE 100

int queue[SIZE], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == SIZE - 1) printf("Queue overflow\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = x;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue underflow\n");
        return -1;
    } else {
        int temp = queue[front];
        if (front == rear) front = rear = -1;
        else front++;
        return temp;
    }
}

void display() {
    if (front == -1) printf("Queue is empty\n");
    else {
        for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, val;
    while (1) {
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &val);
            enqueue(val);
        } else if (choice == 2) {
            val = dequeue();
            if (val != -1) printf("Dequeued: %d\n", val);
        } else if (choice == 3) display();
        else if (choice == 4) break;
    }
    return 0;
}
