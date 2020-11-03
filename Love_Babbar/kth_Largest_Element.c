#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        printf("Enter a size of an array:\n");
        scanf("%d", &N);
        
        int arr[N], i, j, a, k;
        printf("Enter an elements:\n");
        for(i=0; i<N; i++)
        {
            scanf("%d", &arr[i]);
        }
        
        for(i=0; i<N; i++)
        {
            for(j=i+1; j<N; j++)
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
        printf("kth largest element is: %d", arr[k-1]);
    }
    return 0;
}