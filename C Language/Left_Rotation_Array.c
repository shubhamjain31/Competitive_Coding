#include<stdio.h>

//function to left rotate an array by one position
void leftRotationByOne(int arr[], int n)
{
    int temp = arr[0], i;
    for(i=0; i<n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

//function to left rotate an array by d positions
void leftRotation(int arr[], int d, int n)
{
    int i;
    for(i=0; i<d; i++)
    {
        leftRotationByOne(arr, n);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int d=2;
    int n = sizeof(arr)/sizeof(arr[0]);
    leftRotation(arr, d, n);
    
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}