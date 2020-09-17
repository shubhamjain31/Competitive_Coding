#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

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

int pop(struct node** top)
{
    if(isEmpty(*top))
    {
        printf("Stack UnderFlow!");
    }
    else
    {
        struct node* n = *top;
        *top = (*top) -> next;
        int x = n -> data;
        free(n);
        return x;
    }
}

int peek(struct node* top, int pos)
{
    struct node* ptr = top;
    for(int i=0; (i<pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr -> next;
    }
    if(ptr != NULL)
    {
        return ptr -> data;
    }
    else
    {
        return -1;
    }
}

int findElement(struct node* top, int val)
{
    int f = 0;
    struct node* ptr = top;
    while(ptr -> next != NULL)
    {
        if(ptr -> data == val)
        {
            f = 1;
            break;
        }
        ptr = ptr -> next;
    }
    if(ptr -> data == val)
    {
        f = 1;
    }
    if(f == 1)
    {
        printf("\n%d is found", val);
    }
    else
    {
        printf("\n%d is not found", val);
    }
}

int stackTop(struct node* top)
{
    return top -> data;
}

int stackBottom(struct node* top)
{
    struct node* ptr = top;
    while(ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }
    return ptr->data;
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
    struct node* top = NULL;
    top = push(top, 62);
    top = push(top, 27);
    top = push(top, 77);
    top = push(top, 25);
    linkedListTraversal(top);
    
    int element = pop(&top);
    printf("\nPopped element is %d", element);
    
    printf("\n");
    linkedListTraversal(top);
    
    for(int j=1; j<=3; j++)
    {
        printf("\nValue at position %d is: %d",j , peek(top, j));
    }
    
    findElement(top, 62);
    
    printf("\nThe top most value of this stack is %d", stackTop(top));
    printf("\nThe bottom most value of this stack is %d", stackBottom(top));
    return 0;
}