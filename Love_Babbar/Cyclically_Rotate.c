#include<stdio.h>

int main()
{
    int testcases;
    printf("No of test cases:\n");
    scanf("%d", &testcases);
    while(testcases--)
    {
        int N;
        printf("\nEnter size of first array:\n");
        scanf("%d", &N);
        
        int a[N], i, x;
        printf("\nEnter an elements for first array:\n");
        for(i=0; i<N; i++)
        {
            scanf("%d", &a[i]);
        }
        
        printf("\n");
        i = N-1, x = a[N-1];
        while (i>0)
        {
            a[i] = a[i-1];
            i--;  
        }
        a[0] = x;
        
        printf("\nRotated array is\n");
        for(i=0; i<N; i++)
        {
            printf("%d ",a[i]);
        }
    }
    return 0;
}