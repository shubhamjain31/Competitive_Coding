t = int(input())
for i in range(t):
	n, k, x, y = map(int,input().split())
	flag = 0;
	for i in range(n):
		if((x+(k*i))%n == y):
			print("YES")
			flag = 1
			break
	if flag == 0 :
		print("NO")