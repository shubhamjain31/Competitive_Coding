#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queueArray[MAX];
int front = -1;
int rear = -1;

//Add an element
void enQueue(int item)
{
    if(rear == MAX-1)
    {
        printf("Queue Overflow !\n\n");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        rear += 1;
        queueArray[rear] = item;
    }
}

//Remove an element
void deQueue()
{
    if(front == -1 && front > rear)
    {
        printf("Queue Underflow");
        return;
    }
    else
    {
        printf("\nDeleted element is: %d", queueArray [front]);
        front += 1;
    }
}

//Size of queue
void size()
{
    int n = 0;
    for(int i=front; i<=rear; i++)
    {
        n += 1;
    }
    printf("\n\nSize of queue is: %d",n);
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
        for(i=front; i<=rear; i++)
        {
            printf("%d ",queueArray[i]);
        }
        printf("\n");
    }
}

//find an element in queue
void search(int val)
{
    int i;
    for(i=front; i<=rear; i++)
    {
        if(queueArray[i] == val)
        {
            printf("\n\nElement found at %d position.", i);
            return;
        }
    }
    printf("\n\nNo element found");
}

//top most element in queue
int peek()
{
    printf("\nPeek of queue is: %d", queueArray[front]);
}

int main()
{
    //deQueue is not possible on empty queue
    //deQueue(); 

    //enQueue 5 elements
    enQueue(12);
    enQueue(2);
    enQueue(26);
    enQueue(31);
    enQueue(44);
    printf("Queue of elements is:\n");
    display();
    
    //6th element can't be added to queue because queue is full
    enQueue(6);
    
    //deQueue removes element entered first i.e. 1
    deQueue();
    printf("\n\nQueue after deleting element is:\n");
    display();
    
    peek();
    search(31);
    size();
    return 0;
}