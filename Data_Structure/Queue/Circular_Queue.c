#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queueArray[5];
int front = -1;
int rear = -1;

//Check if the queue is full
int isFull()
{
    if((front == rear + 1) || (front == 0 && rear == MAX-1))
    {
        return 1;
    }
    return 0;
}

//Check if the queue is empty
int isEmpty()
{
    if(front == -1)
    {
        return 1;
    }
    return 0;
}

//Adding an element
void enQueue(int element)
{
    if(isFull())
    {
        printf("Stack is full !!\n\n");
        return;
    }
    else
    {
        if(front == -1)
        {
            front = 0;  
        }
        rear = (rear+1)%MAX;
        queueArray[rear] = element;
    }
}

//Removing an element
void deQueue()
{
    int x;
    if(isEmpty())
    {
        printf("Stack is empty !!\n\n");
        return;
    }
    else
    {
        x = queueArray[front];
        if(front == rear)
        {
            front = rear = -1;  
        }
        else
        {
            front = (front+1)%MAX;
        }
        printf("\nDeleted element is: %d", queueArray[front]);
    }
}

//Size of queue
int size()
{
    int i, n = 0;
    for(i = 0; i<=MAX-1; i++)
    {
        if(queueArray[i] != 0)
        {
            n += 1;
        }
    }
    printf("\nSize of queue is %d",n);
    return n;
}

//Display the queue
void display()
{
    int i;
    if(front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        for(i=front; i!=rear; i=(i+1)%MAX)
        {
            printf("%d ",queueArray[i]);
        }
        printf("%d ", queueArray[i]);
        printf("\n");
    }
}

int main()
{
    enQueue(45);
    enQueue(12);
    enQueue(33);
    enQueue(41);
    enQueue(54);
    //enQueue(23);
    printf("Queue of elements is:\n");
    display();
    
    deQueue();
    printf("\n\nDequeue after deleting element at rear is:\n");
    display();
    
    size();
    return 0;
}