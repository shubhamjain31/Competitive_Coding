#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

int stack[MAX];
int front = 0;
int top = -1;

void checkPalindrome(char s[])
{
    int i;
    char b;
    
    //push the string into stack
    for(i=0; s[i] != '\0'; i++)
    {
        b = s[i];
        push(b);
    }
    
    //checking stack is palindrome or not
    for(i=0; i<(strlen(s)/2); i++)
    {
        if(stack[top] == stack[front])
        {
            pop();
            front++;
        }
        else
        {
            printf("\n%s is not palindrome",s);
            break;
        }
    }
    if(((strlen(s))/2) == front)
    {
        printf("\n%s is palindrome",s);
        top = -1;
        front = 0;
    }
}

void push(char a)
{
    top++;
    stack[top] = a;
}

void pop()
{
    top--;
}

int main()
{
    char s[MAX];
    printf("Enter a string:\n");
    scanf("%s",s);
    checkPalindrome(s);
    return 0;
}