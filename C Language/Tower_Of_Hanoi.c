#include<stdio.h>

int main()
{
    int n;
    printf("Enter number of disks:\n");
    scanf("%d",&n);
    TOH(n, 'A','B','C');
    return 0;
}

void TOH(int n, char src, char aux, char dest)
{
    if(n==1)
    printf("Move from %c to %c\n",src,dest);
    else
    {
        TOH(n-1, src, dest, aux);
        TOH(1, src, aux, dest);
        TOH(n-1, aux, src, dest);
    }
    
} 