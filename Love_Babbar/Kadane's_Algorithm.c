//Largest Sum Contiguous Subarray

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
        
        int a[N], i, start, end, s;
        printf("\nEnter an elements for first array:\n");
        for(i=0; i<N; i++)
        {
            scanf("%d", &a[i]);
        }
        
        int max_sum_so_far = a[0];
        int max_ending_here = 0;
        start = 0; end = 0; s = 0;
        for(i=0;i<N;i++) 
        { 
            max_ending_here = max_ending_here + a[i]; 
            if(max_ending_here < 0) 
            { 
                max_ending_here = 0;
                s = i+1;
            } 
            if(max_sum_so_far < max_ending_here) 
            { 
                max_sum_so_far = max_ending_here;
                start = s; end = i;
            } 
        }
        printf("\nMaximum contiguous sum is %d\n",max_sum_so_far);
        printf("\nThe contiguous subarray  with the largest sum is ");
        for(i=start; i<end; i++)
        {
            printf("%d ",a[i]);
        }
    }
    return 0;
}