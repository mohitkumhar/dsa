#include <stdio.h>
#define SIZE 100

int queue[SIZE], priority[SIZE], size = 0;

void enqueue(int value, int prio) {
    if (size == SIZE) {
        printf("Queue overflow\n");
        return;
    }
    int i = size - 1;
    while (i >= 0 && priority[i] < prio) {
        queue[i + 1] = queue[i];
        priority[i + 1] = priority[i];
        i--;
    }
    queue[i + 1] = value;
    priority[i + 1] = prio;
    size++;
}

int dequeue() {
    if (size == 0) {
        printf("Queue underflow\n");
        return -1;
    }
    size--;
    return queue[size];
}

void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d (Priority: %d)\n", queue[i], priority[i]);
    }
}

int main() {
    int choice, val, prio;
    while (1) {
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d %d", &val, &prio);
            enqueue(val, prio);
        } else if (choice == 2) {
            val = dequeue();
            if (val != -1) printf("Dequeued: %d\n", val);
        } else if (choice == 3) display();
        else if (choice == 4) break;
    }
    return 0;
}
