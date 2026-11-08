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
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This queue is full!");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueue Element: %d\n",val);
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This queue is empty!");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // enqueue few elements:
    enqueue(&q, 12);
    enqueue(&q, 17);
    enqueue(&q, 1);

    printf("dequeuing element %d\n", dequeue(&q));
    printf("dequeuing element %d\n", dequeue(&q));
    if (isEmpty(&q))
    {
        printf("Queue is empty!\n");
    }
    if (isFull(&q))
    {
        printf("Queue is Full!\n");
    }
    return 0;
}