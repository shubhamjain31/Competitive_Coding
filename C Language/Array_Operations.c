#include<stdio.h>

void display(int arr[], int n)
{
    //Traversing
    int i;
    for(i=0;i<n-1;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void indInsertion (int arr[], int size, int element, int capacity, int index)
{
    //Insertion at the specific position
    int i;
    if(size >= capacity)
    {
        return -1;
    }
    for(i=size-1; i>=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 0;
}

int findElement(int arr[], int size, int keyElement)
{
    //Element Searching
    for(int i=0 ; i<size; i++)
    {
        if(arr[i] == keyElement)
        {
            if(i!=-1)
            {
                printf("Position of %d: %d\n", keyElement ,i+1);
            }
            else
            {
                printf("Element %d not found\n", keyElement);
            }
        }
    }
}

void indDeletion (int arr[], int size, int index)
{
    //Deletion at the specific position
    int i;
    for(i=index; i<size-1; i++)
    {
        arr[i] = arr[i+1];
    }
}

int main()
{
    int arr[100] = {7,8,56,26,10};
    int size = 5, element = 26, index = 8;
    int keyElement = 7;
    display(arr, size);
    
    indInsertion(arr, size, element, 100, index);
    size += 1;
    display(arr, size);
    
    findElement(arr, size, keyElement);
    
    indDeletion (arr, size, 1);
    size -= 1;
    display(arr, size);
    return 0;
}