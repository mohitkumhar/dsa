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
    return q->r == q->size - 1;
}

int isEmpty(struct queue *q)
{
    return (q->f == q->r);
}

void enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue OverFlow!! Cannot Enqeueue Element\n");
        return;
    }

    q->r++;
    q->arr[q->r] = data;
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Overflow!! Cannot Dequeue Element\n");
        return 0;
    }
    int popedValue;
    q->f++;
    popedValue = q->arr[q->f];
    return popedValue;
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    // BFS Implementation
    int node;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = 
    {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };
    printf("%d", i);
    visited[i] = 1;

    enqueue(q, i);  // Enqueue i for Exploration
    while(!isEmpty(q))
    {
        int node = dequeue(q);
        for(int j = 0; j< 7; j++)
        {
            if(a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }

    }

    return 0;
}
