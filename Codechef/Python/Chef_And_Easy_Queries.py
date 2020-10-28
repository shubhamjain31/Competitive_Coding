t = int(input())
for i in range(t):
	n, k = map(int,input().split())
	a  = list(map(int,input().split()))
	count = 0; leftover = 0; day = 0;
	for i in range(n):
		count = a[i]+leftover
		leftover = count-k
		if(count < k):
			day = i+1
			break
	if leftover >= 0 :
		day = n+(leftover//k)+1
	print(day)