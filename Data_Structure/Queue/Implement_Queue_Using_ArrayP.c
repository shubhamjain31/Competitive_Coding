#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *q)
{
    if(q -> rear == q -> size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if(q -> rear == q -> front)
    {
        return 1;
    }
    return 0;
}

void enQueue(struct queue *q, int val)
{
    if(isFull(q))
    {
        printf("This Queue is full");
    }
    else
    {
        q -> rear++;
        q -> arr[q -> rear] = val;
    }
    return q;
}

void deQueue(struct queue *q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("This Queue is empty");
    }
    else
    {
        q -> front+=1;
        a = q -> arr[q -> front];     
    }
    printf("\n\nDeleted element is %d",a);
    return q;
}

void peek(struct queue *q)
{
    printf("Front element of queue is %d", q -> arr[q -> front+1]);
}

void display(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("\nNo element in queue");
    }
    for(int i= q -> front; i< q->rear; i++)
        {
            printf("%d ",q -> arr[i+1]);
        }
        printf("\n\n");
}

int main()
{
    struct queue q;
    q.size = 5;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *)malloc(q.size*sizeof(int));
    
    enQueue(&q, 26);
    enQueue(&q, 35);
    enQueue(&q, 56);
    enQueue(&q, 62);
    
    printf("Queue of elements is:\n");
    display(&q);
    
    peek(&q);
    deQueue(&q);
    
    printf("\n\nQueue of elements is:\n");
    display(&q);
    return 0;
}