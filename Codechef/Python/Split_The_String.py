"""t = int(input())
for i in range(t):
	n = int(input())
	s = input()
	last = s[n-1]
	found = 0
	for i in range(0, n-1):
		if(s[i] == last):
			found = 1
			break
	if found == 1 :
		print("YES")
	else:
		print("NO")"""

t=int(input())
for i in range(t):
    n = int(input())
    s = input()
    print(s[-1])
    if s.count(s[-1])>1:
        print("YES")
    else:
        print("NO")