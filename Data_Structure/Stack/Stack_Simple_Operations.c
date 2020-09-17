#include<stdio.h>

int size = 6;
int stack[6];
int top = -1;

isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

isFull()
{
    if(top == size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int peek()
{
    return stack[top];
}

int push(int val)
{
    if(!isFull())
    {
        top++;
        stack[top] = val;
    }
    else
    {
        printf("Stack Overflow!\n");
    }
}

int pop()
{
    if(!isEmpty())
    {
        int p = stack[top];
        top--;
        return p;
    }
    else
    {
        printf("Stack Overflow!\n");
    }
}

int main()
{
    push(67);
    push(10);
    push(29);
    push(67);
    push(8);
    push(73);
    
    //print peek element
    printf("\nTop element of stack is %d\n",peek());
    
    //print stack data
    while(!isEmpty())
    {
        int data = pop();
        printf("%d ",data);
    }
    
    //check if stack is full or not
    printf("\nStack is %s\n",isFull()?"full":"not full");
   
     //check if stack is empty
    printf("Stack is %s\n",isEmpty()?"empty":"not empty");
    return 0;
}