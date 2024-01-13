#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct circularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct circularQueue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int enqueue(struct circularQueue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue Overflow! Cannot Push Element\n");
        return -1;
    }
    q->r = (q->r + 1) % q->size;
    q->arr[q->r] = data;
}

int dequeue(struct circularQueue *q)
{
    int popedElement = -1;
    if (isEmpty(q))
    {
        printf("Queue Underflow! Cannot Pop Element\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        popedElement = q->arr[q->f];
    }
    return popedElement;
}


int main()
{
    struct circularQueue q;
    q.size = 5;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    printf("Queue Before\n");
    printf("Queue is Full: %d\n", isFull(&q));
    printf("Queue is Empty: %d\n", isEmpty(&q));

    enqueue(&q, 11);
    enqueue(&q, 22);
    enqueue(&q, 33);
    enqueue(&q, 44);
    enqueue(&q, 55);
    printf("\nQueue After Enqueue\n");
    printf("Queue is Full: %d\n", isFull(&q));
    printf("Queue is Empty: %d\n", isEmpty(&q));

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    printf("\nQueue After Dequeue\n");
    printf("Queue is Full: %d\n", isFull(&q));
    printf("Queue is Empty: %d\n", isEmpty(&q));

    return 0;
}
