#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *newNode(int item)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr != NULL)
    {
        ptr -> data = item;
        ptr -> next = NULL;
        return ptr;
    }
    else
    {
        printf("Stack Overflow !\n");
    }
}

int deQueue()
{
    if(front == NULL)
    {
        printf("Queue Underflow !\n");
    }
    struct node *temp = front;
    printf("\n\nDeleted item is: %d\n",temp -> data);
    front = front -> next;
    if(front == NULL)
    {
        rear = NULL;
    }
    int item = temp -> data;
    free(temp);
    return item;
}

void enQueue(int item)
{
    struct node* ptr = newNode(item);
    printf("%d ", item);
    if(front == NULL)
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear -> next = ptr;
        rear = ptr;
    }
}

void linkedListTraversal()
{
    struct node *temp = front;
    while(temp != NULL)
    {
        printf("%d ",temp -> data);
        temp = temp -> next;
    } 
}

void peek()
{
    if(front != NULL)
    {
        printf("\n\nFront element is %d",front -> data);
    }
    else
    {
        return;
    }
}

int isEmpty()
{
    return front == NULL && rear == NULL;
}

int main()
{
    printf("Queue is:\n");
    enQueue(51);
    enQueue(6);
    enQueue(14);
    enQueue(22);
    enQueue(63);
    
    peek();
    
    printf("\n\nQueue before removing element is:\n");
    linkedListTraversal();
    
    deQueue();
    
    if(isEmpty())
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nQueue is not empty");
    }
    
    printf("\n\nQueue after removing element is:\n");
    linkedListTraversal();
    return 0;
}