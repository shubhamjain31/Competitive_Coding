from math import factorial as fac
testcases = int(input())
for t in range(testcases):
    n, k = map(int,input().split())
    l = list(map(int,input().split()))
    l.sort()
    q = l[:k]
    a = q.count(q[-1])
    b = l.count(q[-1])
    print(fac(b)//(fac(a)*fac(b-a)))