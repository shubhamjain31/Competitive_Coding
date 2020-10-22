#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int coins[n-1];
    int i, temp = 0;
    for(i =0; i<n-1; i++)
    {
        scanf("%d",&coins[i]);
        temp = temp ^ coins[i];
    }
    printf("%d",temp);
    return 0;
}