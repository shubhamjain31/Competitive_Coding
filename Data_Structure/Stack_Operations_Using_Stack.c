#include<stdio.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if(ptr -> top == -1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if(ptr -> top == ptr -> size-1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int push(struct stack *ptr, int data)
{
    if(isFull(ptr))
    {
        printf("Stack OverFlow! Cannot push %d to the stack\n", data);
    }
    else
    {
        ptr -> top++;
        ptr -> arr[ptr -> top] = data;
        return ptr;
    }
}

int pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack UnderFlow! Cannot pop to the stack\n");
        return -1;
    }
    else
    {
        int val = ptr -> arr[ptr -> top];
        ptr -> top--;
        return val;
    }
}

int peek(struct stack *ptr, int index)
{
    int arrayInd = ptr -> top - index+1;
    if(arrayInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return ptr -> arr[arrayInd];
    }
}

int stackTop(struct stack *ptr)
{
    return ptr -> arr[ptr -> top];
}

int stackBottom(struct stack *ptr)
{
    return ptr -> arr[0];
}

int findElement(struct stack *ptr, int data)
{
    int f = 0;
    while(ptr -> top != -1)
    {
        if(ptr -> arr[ptr -> top] == data)
        {
            f = 1;
            break;
        }
        ptr -> top--;
    }
    if(f == 1)
    {
        printf("\n%d is found", data);
    }
    else
    {
        printf("\n%d is not found");
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp -> size = 10;
    sp -> top = -1;
    sp -> arr = (int *)malloc(sp -> size * sizeof(int));
    printf("Stack has been created successfully\n");
    
    printf("Before pushing, Full is %d\n",isFull(sp));
    printf("Before poping, Empty is %d\n",isEmpty(sp));
    push(sp, 68);
    push(sp, 86);
    push(sp, 12);
    push(sp, 37);
    push(sp, 82);
    push(sp, 43);
    push(sp, 39);
    push(sp, 76);
    push(sp, 9);
    push(sp, 92);
    push(sp, 70);  //Stack Overflow since the size of the stack is 10
    
    printf("After pushing, Full is %d\n",isFull(sp));
    printf("After poping, Empty is %d\n",isEmpty(sp));
    
    printf("Popped %d from the stack\n",pop(sp));
    
    for(int i=1; i <= sp->top+1; i++)
    {
        printf("The value at position %d is %d\n",i, peek(sp, i));
    }
    
    printf("\nThe top most value of this stack is %d\n", stackTop(sp));
    printf("\nThe bottom most value of this stack is %d\n", stackBottom(sp));
    
    findElement(sp, 768);
    return 0;
}