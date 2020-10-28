#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long n, k;
		scanf("%ld %ld", &n, &k);
		long a[n], i, count = 0,leftover = 0 , day;
		for (i = 0; i < n; i++)
		{
			scanf("%ld", &a[i]);
		}
		for (i = 0; i < n; i++)
		{
			count = a[i]+leftover;
			leftover = count - k;
			if(count<k)
			{
				day = i+1;
				break;
			}
		}
		if(leftover>=0)
		{
			day = n+(leftover/k)+1;
		}
		printf("%ld\n", day);
		
	}
	return 0;
}


/*
t = number of test cases
n = number of days chef receives new queries
k = maximum queries chef can answer each day
a[] = number of new queries on day i
count = total queries to be answered on i
leftover = queries not answered on day i
day = day on which chef answers less than k queries
*/