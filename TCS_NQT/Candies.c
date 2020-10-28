#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N = 10, k;
	scanf("%d",&k);

	if (k <= 0)
	{
		printf("INVALID INPUT\n");
		printf("%d\n", N);
	}
	else
	{
		printf("NUMBER OF CANDIES SOLD: %d\n",k);
		printf("NUMBER OF CANDIES AVAILABLE:%d\n",N-k);
	}
    return 0;
}