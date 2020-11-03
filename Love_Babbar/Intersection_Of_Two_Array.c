#include<stdio.h>

int main()
{
    int testcases;
    printf("No of test cases:\n");
    scanf("%d", &testcases);
    while(testcases--)
    {
        int N, M;
        printf("\nEnter size of first array:\n");
        scanf("%d", &N);
        
        printf("\nEnter size of second array:\n");
        scanf("%d", &M);
        
    
        int a[N], b[M], i, j;
        printf("\nEnter an elements for first array:\n");
        for(i=0; i<N; i++)
        {
            scanf("%d", &a[i]);
        }
        
        printf("\nEnter an elements for second array:\n");
        for(i=0; i<M; i++)
        {
            scanf("%d", &b[i]);
        }
        
        printf("\n");
        i = 0, j = 0;
        while (i<N && j<M)
        {
            if(a[i] < b[j])
            {
                i++;
            }
            else if(b[j] < a[i])
            {
                j++;
            }
            else
            {
                printf("%d ",b[j++]);
                i++;
            }
        }
        
 
    
    }
    return 0;
}