#include<stdio.h>

int LinearSearch(int arr[], int size, int element)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {23, 27, 12, 85,56};
    int size;
    int element = 27;
    size = sizeof(arr)/sizeof(int);
    int pos = LinearSearch(arr, size, element);

    if(pos == -1)
        printf("%d was not found", element);
    else
        printf("The element %d was found at %d\n",element, pos);
    return 0;
}