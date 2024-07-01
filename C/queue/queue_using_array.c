#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1 && q->f == -1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
    
}

int enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overflow! Cannot Enqueue Elements");
        return -1;
    }
    q->r++;
    q->arr[q->r] = val;
}

int dequeue(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue Underflow! Cannot Dequeue Element From it\n");
        return -1;
    }
    int popedValue;
    q->f++;
    popedValue = q->arr[q->f];
    return popedValue;
}

int main()
{
    struct queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    printf("Before Enqueue Element\n");
    printf("Queue is Full: %d\n", isFull(&q));
    printf("Queue is Empty: %d\n", isEmpty(&q));

    
    enqueue(&q, 11);
    enqueue(&q, 22);
    enqueue(&q, 33);
    enqueue(&q, 44);
    enqueue(&q, 55);
    enqueue(&q, 66);
    enqueue(&q, 77);
    enqueue(&q, 88);
    enqueue(&q, 99);
    enqueue(&q, 110);

    printf("\n\nAfter Enqueue Element\n");
    printf("Queue is Full: %d\n", isFull(&q));
    printf("Queue is Empty: %d\n", isEmpty(&q));

    printf("Poped Element is: %d\n", dequeue(&q));
    printf("Poped Element is: %d\n", dequeue(&q));
    printf("Poped Element is: %d\n", dequeue(&q));
    printf("Poped Element is: %d\n", dequeue(&q));
    printf("Poped Element is: %d\n", dequeue(&q));
    printf("Poped Element is: %d\n", dequeue(&q));
    printf("Poped Element is: %d\n", dequeue(&q));
    printf("Poped Element is: %d\n", dequeue(&q));
    printf("Poped Element is: %d\n", dequeue(&q));
    printf("Poped Element is: %d\n", dequeue(&q));
    printf("Poped Element is: %d\n", dequeue(&q));
    printf("Poped Element is: %d\n", dequeue(&q));


    return 0;
}