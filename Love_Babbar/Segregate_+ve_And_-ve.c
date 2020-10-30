//Sort array of 0s, 1s,2s

#include<stdio.h>

int main()
{
    int testcases;
    printf("No of test cases:\n");
    scanf("%d", &testcases);
    while(testcases--)
    {
        int num;
        printf("\nEnter a size of an array:\n");
        scanf("%d", &num);
        
    
        int arr[num], i, j, a;
        printf("\nEnter an elements:\n");
        for(i=0; i<num; i++)
        {
            scanf("%d", &arr[i]);
        }
        
        j = 0;
        for(i=0; i<num; i++)
        {
            if(arr[i]<0)
            {
                if(i != j)
                {
                    a = arr[i];
                    arr[i] = arr[j];
                    arr[j] = a;
                }
            j++;
            }
        }
        
    printf("\n");
    for(i=0; i<num; i++)
    {
        printf("%d ", arr[i]);
    }
    }
    return 0;
}