//Sum of Natural Number using Recursion

#include<stdio.h>

int sum(int x)
{
    if(x != 0)
    {
        return x + sum(x-1);
    }
    else
    {
        return x;
    }
}

int main()
{
    int num, result;
    printf("Enter a number:\n");
    scanf("%d",&num);
    
    result = sum(num);
    printf("\nSum is %d", result);
    return 0;
}