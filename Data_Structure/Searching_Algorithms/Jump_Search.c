#include<stdio.h>
#include<math.h>

int BinearSearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size-1;
    int step = sqrt(size);
    while(arr[step] <= element && step < size)
    {
        low = step;
        step += sqrt(size);
        if(step > high)
        {
            step = size;
        }
    }
    for(int i = low; i<step; i++)
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
    int arr[] = {23, 27, 34, 85,96};
    int size;
    int element = 96;
    size = sizeof(arr)/sizeof(int);
    int pos = BinearSearch(arr, size, element);

    if(pos == -1)
        printf("%d was not found", element);
    else
        printf("The element %d was found at %d\n",element, pos);
    return 0;
}