#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queueStack[MAX];
int top = -1;

//function to remove an element from stack
int pop()
{
    return queueStack[top--];
}

//function to insert an element into stack
void push(int item)
{
    if(top == MAX-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        queueStack[top] = item;
    }
}

//function to insert element in the queue using recursive stack call
void enQueue(int item)
{
    push(item);
}

//function to dequeue element from a queue using recursive stack call
int deQueue()
{
    int data, res;
    if(top == -1)
    {
        printf("\nQueue is empty !!");
    }
    else if(top == 0)
    {
        return pop();
    }
    data = pop();
    res = deQueue();
    push(data);
    return res;
}

void peek()
{
    printf("Front element of queue is %d", queueStack[top]);
}

void display()
{
    for(int i= 0; i<=top; i++)
        {
            printf("%d ", queueStack[i]);
        }
        printf("\n\n");
}

int main()
{
    
    enQueue(26);
    enQueue(35);
    enQueue(56);
    enQueue(62);
    
    printf("Queue of elements is:\n");
    display();
    
    peek();
    deQueue();
    
    printf("\n\nQueue of elements is:\n");
    display();
    return 0;
}