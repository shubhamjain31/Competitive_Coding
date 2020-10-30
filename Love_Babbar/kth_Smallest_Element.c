#include<stdio.h>

int main()
{
    int num;
    printf("Enter a size of an array:\n");
    scanf("%d", &num);
    
    int arr[num], i, j, a, k;
    printf("Enter an elements:\n");
    for(i=0; i<num; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for(i=0; i<num; i++)
    {
        for(j=i+1; j<num; j++)
        {
            if(arr[i]<arr[j])
            {
                a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
    printf("Enter kth element:\n");
    scanf("%d", &k);
    for(i=0; i<k; i++)
    {
        a = arr[i];
    }
    printf("kth smallest element is: %d", a);
    return 0;
}