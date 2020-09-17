#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* top = NULL;

int isEmpty(struct node* top)
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct node* top)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node* push(struct node* top, int x)
{
    if(isFull(x))
    {
        printf("Stack Overflow!");    
    }
    else
    {
        struct node* n = (struct node*)malloc(sizeof(struct node));
        n -> data = x;
        n -> next = top;
        top = n;
        return top;
    }
}

int pop(struct node* tp)
{
    if(isEmpty(tp))
    {
        printf("Stack UnderFlow!");
    }
    else
    {
        struct node* n = tp;
        top = tp -> next;
        int x = n -> data;
        free(n);
        return x;
    }
}

void linkedListTraversal (struct node* ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

int main()
{
    //struct node* top = NULL;
    top = push(top, 62);
    top = push(top, 27);
    top = push(top, 77);
    top = push(top, 25);
    linkedListTraversal(top);
    
    int element = pop(top);
    printf("\nPopped element is %d", element);
    
    printf("\n");
    linkedListTraversal(top);
    return 0;
}