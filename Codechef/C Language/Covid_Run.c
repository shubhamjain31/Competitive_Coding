#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, k, x, y, flag = 0;
		scanf("%d%d%d%d", &n, &k, &x, &y);
		for (int i = 1; i <= n; i++)
		{
			if((x+(k*i))%n == y)
			{
				printf("YES\n");
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("NO\n");
		}
		
	}
	return 0;
}