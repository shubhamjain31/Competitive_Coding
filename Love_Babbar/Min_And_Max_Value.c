#include<stdio.h>

int main()
{
    int num;
    printf("Enter a size of an array:\n");
    scanf("%d", &num);
    
    int arr[num], i;
    int max, min;
    printf("Enter an elements:\n");
    for(i=0; i<num; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    max = min = arr[0];
    for(i=1; i<num; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
        if(min > arr[i])
        {
            min = arr[i];
        }            
    }
    printf("Maximum of array: %d", max);
    printf("\nMinimum of array: %d", min);
    return 0;
}