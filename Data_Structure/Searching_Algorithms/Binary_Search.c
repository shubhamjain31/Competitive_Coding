#include<stdio.h>

int BinearSearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size-1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] == element)
        {
            return mid;
        }
        if(arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {23, 27, 34, 85,96};
    int size;
    int element = 27;
    size = sizeof(arr)/sizeof(int);
    int pos = BinearSearch(arr, size, element);

    if(pos == -1)
        printf("%d was not found", element);
    else
        printf("The element %d was found at %d\n",element, pos);
    return 0;
}