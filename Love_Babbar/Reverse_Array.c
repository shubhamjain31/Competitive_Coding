#include<stdio.h>

int main()
{
    int num;
    printf("Enter size of an array:\n");
    scanf("%d", &num);
    
    int arr[num], i;
    printf("Enter an elements:\n");
    for(i=0; i<num; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Reverse Array is:\n");
    for(i=num-1; i>=0; i--)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}