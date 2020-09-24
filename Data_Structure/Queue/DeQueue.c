#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queueArray[MAX];
int front = -1;
int rear = -1;

//Insert item into Dequeue at front
void addFront(int *queueArray, int element, int *f, int *r)
{
    int k, c;
    if(*f == 0 && *r == MAX-1)
    {
        printf("Queue Overflow !\n\n");
        return;
    }
    if(*f == -1)
    {
        front = rear = 0;
        queueArray[*f] = element;
        return;
    }
    if(*r != MAX-1)
    {
        c = size(queueArray);
        k = *r + 1;
        for(int i=1; i<=c; i++)
        {
            queueArray[k] = queueArray[k-1];
            k--;
        }
        queueArray [k] = element;
        *f = k;
        *r = *r + 1;
    }
    else
    {
        *f = *f + 1;
        queueArray[*f] = element;
    }
}

//Delete item from Dequeue at front
void delFront(int *queueArray, int *f, int *r)
{
    int x;
    if(*f == -1)
    {
        printf("Queue is Empty !!");
    }
    x = queueArray[*f];
    queueArray[*f] = 0;
    if(*f == *r)
    {
        *f = *r = -1;
    }
    else
    {
        *f = *f + 1;
    }
    printf("\nElement deleted at front is %d", x);
}

//Insert item into Dequeue at rear
void addRear(int *queueArray, int element, int *f, int *r)
{
    if(*r == MAX-1)
    {
        printf("Dequeue is full !!");
        return;
    }
    if(*f == -1)
    {
        front = rear = 0;
        queueArray[*r] = element;
    }
    else
    {
        *r = *r + 1;
        queueArray[*r] = element;
    }
}

void delRear(int *queueArray, int *f, int *r)
{
    int x;
    if(*f == -1)
    {
        printf("Queue is Empty !!");
    }
    x = queueArray[*r];
    queueArray[*r] = 0;
    if(*f == *r)
    {
        *f = *r = -1;
    }
    else
    {
        *r = *r - 1;
    }
    printf("\nElement deleted at front is %d", x);
}

//Size of Dequeue
int size(int *queueArray)
{
    int i, n = 0;
    for(i = 0; i<=MAX-1; i++)
    {
        if(queueArray[i] != 0)
        {
            n += 1;
        }
    }
    return n;
}

//Display the Dequeue
void display(int *queueArray)
{
    int i;
    if(front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        for(i=0; i<=MAX-1; i++)
        {
            if(queueArray[i] != 0)
            {
                printf("%d ",queueArray[i]);
            }
        }
        printf("\n");
    }
}

int main()
{
    addFront(queueArray, 12, &front, &rear);
    addFront(queueArray, 31, &front, &rear);
    addFront(queueArray, 9, &front, &rear);
    addFront(queueArray, 34, &front, &rear);
    printf("Dequeue insertion of elements at front is:\n");
    display(queueArray);
    
    addRear(queueArray, 4, &front, &rear);
    printf("\nDequeue insertion of elements at rear is:\n");
    display(queueArray);
    
    delFront(queueArray, &front, &rear);
    printf("\nDequeue after deleting element at front is:\n");
    display(queueArray);
    
    delRear(queueArray, &front, &rear);
    printf("\n\nDequeue after deleting element at rear is:\n");
    display(queueArray);
    
    return 0;
}