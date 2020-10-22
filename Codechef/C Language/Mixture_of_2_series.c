#include<stdio.h>

int main()
{
    int n, i, a, b;
    printf("Enter number:\n");
    scanf("%d",&n);
    
    for(i=1; i<=n; i++)
    {
        if(i%2 != 0)
        {
            if(i == 1)
            {
                a = 1;
            }
            else
            {
                a = a * 2;
            }
        }
        else
        {
            if(i == 2)
            {
                b = 1;
            }
            else
            {
                b = b * 3;
            }
        }
    }
    if(n%2 != 0)
    {
        printf("\n%d term of series is %d\t",n, a);
    }
    else
    {
        printf("\n%d term of series is %d\t",n, b);
    }
    return 0;
}