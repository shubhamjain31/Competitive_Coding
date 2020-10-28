#include <stdio.h>

#define mod 1000000007

int main()
{
    int testcases;
    scanf("%d", &testcases);
    
    while(testcases--)
    {
        int N;
        long a;
        scanf("%d", &N);
        scanf("%ld", &a);
        
        long long seq = 2 * a, sum = 0, power = 2;
        
        for (int i = 1; i < N + 1; i++)
        {
            scanf("%ld", &a);
            sum = (sum*2) % mod;
            sum = (sum + (seq*a) % mod) % mod;
            seq = (seq + (power*a) % mod) % mod;
            power = (power*2) % mod;
        }
        printf("%ld\n", (long)sum);
    }
    

    return 0;
}
