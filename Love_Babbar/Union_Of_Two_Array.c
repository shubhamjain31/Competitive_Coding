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
        
    
        int a[N], b[M], c[N+M], i, j, k;
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
        
        i = 0, j = 0, k = 0;
        while (i<N && j<M)
        {
            if(a[i] < b[j])
            {
                c[k] = a[i];
                i++;
                k++;
            }
            else if(b[j] < a[i])
            {
                c[k] = b[j];
                j++;
                k++;
            }
            else
            {
                c[k] = a[i];
                i++;
                j++;
                k++;
            }
        }
        
        if(i<N)
        {
            while (i<N)
            {
                c[k] = a[i];
                k++;
                i++;
            }
        }
        else if(j<M)
        {
            while (j<M)
            {
               c[k] = b[j];
               k++;
               j++;
            }
        }
 
    for(i=0; i<k; i++)
    {
        printf("%d ",c[i]);
    }
    }
    return 0;
}