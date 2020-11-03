#include <stdio.h>
int main()
{
    int T,N,K;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&N,&K);
        int a[N],temp,i;
        for(i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(a[i]>a[j])
                {
                    temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                }
            }
        }
        int countRight = 0, countLeft = 0;
        long long int combination = 1;
        for(i=K;i<N;i++)
        {
            if(a[i]==a[K-1])
            {
                countRight++;
            }
        }
        for(i=0;i<K-1;i++)
        {
            if(a[i]==a[K-1])
            {
                countLeft++;
            }
        }
        int total=countLeft+countRight+1;
        for(i=0;i<countLeft+1;i++)
        {
            combination = combination*(total-i)/(i+1);
        }
        printf("%lld\n",combination);
    }
    return 0;
 }